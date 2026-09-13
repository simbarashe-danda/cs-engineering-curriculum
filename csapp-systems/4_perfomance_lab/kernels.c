/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "RAX",              /* Team name */

    "Simbarashe Danda",     /* First member full name */
    "dandasimbarashe21@gmail.com",  /* First member email address */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* optimization 1*/
static int min(int, int);

char block_rotate10_descr[] = "block_rotate10: use 10-block sub-matrix to eliminate cache misses";
void block_rotate10(int dim, pixel *src, pixel *dst) {
    int ii, jj;
    int i, j;       
    int bsz = 10;  // block size

    for (ii = 0; ii < dim; ii+=bsz)
	    for (jj = 0; jj < dim; jj+=bsz)
            for (i = ii; i < min(ii+bsz, dim); i++)
                for (j = jj; j < min(jj+bsz, dim); j++)
                    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}     

/* optimization 2: Assumes dim always a mutiple of 16 */
char block_rotate16_descr[] = "block_rotate16: use 16-block sub-matrix to eliminate cache misses\n"
"eliminate min-max calls";
void block_rotate16(int dim, pixel *src, pixel *dst) {
    int ii, jj;
    int i, j;       
    int bsz = 16;  // block size

    for (ii = 0; ii < dim; ii+=bsz)
	    for (jj = 0; jj < dim; jj+=bsz)
            for (i = ii; i < ii+bsz; i++)
                for (j = jj; j < jj+bsz; j++)   // assume matrix always a mutliple of 16
                    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version (opt_rotate1)";
void rotate(int dim, pixel *src, pixel *dst) 
{
    block_rotate16(dim, src, dst);  // fastest
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
    add_rotate_function(&block_rotate10, block_rotate10_descr);
    add_rotate_function(&block_rotate16, block_rotate16_descr);
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}



/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * opt1_smooth - Optimized version 1 of smooth 
 */
char opt1_smooth_descr[] = "opt1_smooth:  remove min-max and manually handle bound edge cases.\n"
"eliminate pixel and pixel sum creation in loop.";
void opt1_smooth(int dim, pixel *src, pixel *dst) {
    int i, j;
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    /* Region 1 : Top left corner */
    i = j = 0;
    initialize_pixel_sum(&sum);

    for(ii = i; ii <= i+1; ii++) 
	    for(jj = j; jj <= j+1; jj++) 
	        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    dst[RIDX(i, j, dim)] = current_pixel;

    /* Region 2 : Top right corner */
    j = dim - 1;
    initialize_pixel_sum(&sum);

    for(ii = i; ii <= i+1; ii++) 
	    for(jj = j-1; jj <= j; jj++) 
	        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(dst + RIDX(i, j, dim), sum);

    /* Region 3 : Lower left corner */
    j = 0; i = dim-1;
    initialize_pixel_sum(&sum);

    for(ii = i-1; ii <= i; ii++) 
	    for(jj = j; jj <= j+1; jj++) 
	        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    dst[RIDX(i, j, dim)] = current_pixel;

    /* Region 4 : Lower right corner */
    i = j = dim-1;
    initialize_pixel_sum(&sum);
    
    for(ii = i-1; ii <= i; ii++) 
	    for(jj = j-1; jj <= j; jj++) 
	        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    dst[RIDX(i, j, dim)] = current_pixel;

    /* The following regions all exclude corners */

    /* Region 5 : top row */
    i = 0;
	for (j = 1; j < dim-1; j++)
    {  
        initialize_pixel_sum(&sum);
        for(ii = i; ii <= i+1; ii++) 
	        for(jj = j-1; jj <= j+1; jj++) 
	            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

        assign_sum_to_pixel(&current_pixel, sum);
        dst[RIDX(i, j, dim)] = current_pixel;
    }

    /* Region 6 : lower row */
    i = dim-1;
	for (j = 1; j < dim-1; j++)
    {  
        initialize_pixel_sum(&sum);
        for(ii = i-1; ii <= i; ii++) 
	        for(jj = j-1; jj <= j+1; jj++) 
	            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

        assign_sum_to_pixel(&current_pixel, sum);
        dst[RIDX(i, j, dim)] = current_pixel;
    }

    /* Region 7 : left column */
    j = 0;
	for (i = 1; i < dim-1; i++)
    {  
        initialize_pixel_sum(&sum);
        for(ii = i-1; ii <= i+1; ii++) 
	        for(jj = j; jj <= j+1; jj++) 
	            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

        assign_sum_to_pixel(&current_pixel, sum);
        dst[RIDX(i, j, dim)] = current_pixel;
    }

    /* Region 8 : right column */
    j = dim-1;
	for (i = 1; i < dim-1; i++)
    {  
        initialize_pixel_sum(&sum);
        for(ii = i-1; ii <= i+1; ii++) 
	        for(jj = j-1; jj <= j; jj++) 
	            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

        assign_sum_to_pixel(&current_pixel, sum);
        dst[RIDX(i, j, dim)] = current_pixel;
    }

    /* Region 9 : Internal matrix*/
    for (i = 1; i < dim-1; i++) 
	    for (j = 1; j < dim-1; j++)
        {   
            initialize_pixel_sum(&sum);
            for(ii = i-1; ii <= i+1; ii++) 
	            for(jj = j-1; jj <= j+1; jj++) 
	                accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

            assign_sum_to_pixel(&current_pixel, sum);
            dst[RIDX(i, j, dim)] = current_pixel;
        }
}


/*
 * opt2_smooth - Optimized version 2 of smooth 
 */
char opt2_smooth_descr[] = "opt2_smooth: on top of opt1 :\n"
"eliminate multiplication costs, add function unfolding, removed pixel sum abstraction";
void opt2_smooth(int dim, pixel *src, pixel *dst) {
    int i, j, k;
    int lim;
    int red, green, blue;
    red = green = blue = 0;
    

    /* Region 1 : Internal matrix */
    for (j = 1, i = dim+1; j < dim-1; ++j, i += 2)
	    for (k = 1; k < dim-1; k++, ++i)
        {
           // accumulate sum
            red = (src[i].red + src[i-1].red + src[i+1].red
            + src[i+dim].red + src[i+dim-1].red + src[i+dim+1].red
            + src[i-dim].red + src[i-dim-1].red + src[i-dim+1].red );

            blue = (src[i].blue + src[i-1].blue + src[i+1].blue
            + src[i+dim].blue + src[i+dim-1].blue + src[i+dim+1].blue
            + src[i-dim].blue + src[i-dim-1].blue + src[i-dim+1].blue );

            green = (src[i].green + src[i-1].green + src[i+1].green
            + src[i+dim].green + src[i+dim-1].green + src[i+dim+1].green
            + src[i-dim].green + src[i-dim-1].green + src[i-dim+1].green );

            // assign pixel sum to dst pixel
            dst[i].red = (unsigned short) (red/9);
            dst[i].blue = (unsigned short) (blue/9);
            dst[i].green = (unsigned short) (green/9);
        }
        k = i-1;  // lower left corner

    /* Region 2 : Top left corner */
    i = 0;
    red = (src[i].red + src[i+1].red
    + src[i+dim].red + src[i+dim+1].red);

    blue = (src[i].blue + src[i+1].blue
    + src[i+dim].blue + src[i+dim+1].blue);

    green = (src[i].green + src[i+1].green
    + src[i+dim].green + src[i+dim+1].green);

    dst[i].red = (unsigned short) (red/4);
    dst[i].blue = (unsigned short) (blue/4);
    dst[i].green = (unsigned short) (green/4);
    lim = dim-1; ++i;

    /* Region 3 : top row */
	for (; i < lim; ++i)
    { 
        red = (src[i-1].red + src[i].red + src[i+1].red
        + src[i+dim-1].red + src[i+dim].red + src[i+dim+1].red );

        blue = (src[i-1].blue + src[i].blue + src[i+1].blue
        + src[i+dim-1].blue + src[i+dim].blue + src[i+dim+1].blue );

        green = (src[i-1].green + src[i].green + src[i+1].green
        + src[i+dim-1].green + src[i+dim].green + src[i+dim+1].green );

        dst[i].red = (unsigned short) (red/6);
        dst[i].blue = (unsigned short) (blue/6);
        dst[i].green = (unsigned short) (green/6);
    }
    lim += i;

    /* Region 4 : Top right corner */
    red = (src[i-1].red + src[i].red
    + src[i+dim-1].red + src[i+dim].red);

    blue = (src[i-1].blue + src[i].blue
    + src[i+dim-1].blue + src[i+dim].blue);

    green = (src[i-1].green + src[i].green
    + src[i+dim-1].green + src[i+dim].green);

    dst[i].red = (unsigned short) (red/4);
    dst[i].blue = (unsigned short) (blue/4);
    dst[i].green = (unsigned short) (green/4);
    ++i; ++lim;

    /* Region 5 : left column */
	for (; i < k; i+=dim)
    {  
        red = (src[i].red + src[i+1].red
        + src[i-dim].red + src[i-dim+1].red
        + src[i+dim].red + src[i+dim+1].red );

        blue = (src[i].blue + src[i+1].blue
        + src[i-dim].blue + src[i-dim+1].blue
        + src[i+dim].blue + src[i+dim+1].blue );

        green = (src[i].green + src[i+1].green
        + src[i-dim].green + src[i-dim+1].green
        + src[i+dim].green + src[i+dim+1].green );

        dst[i].red = (unsigned short) (red/6);
        dst[i].blue = (unsigned short) (blue/6);
        dst[i].green = (unsigned short) (green/6);
    }

    /* Region 6 : Lower left corner */
    i = k;
    red = (src[i].red + src[i+1].red
    + src[i-dim].red + src[i-dim+1].red);

    blue = (src[i].blue + src[i+1].blue
    + src[i-dim].blue + src[i-dim+1].blue);

    green = (src[i].green + src[i+1].green
    + src[i-dim].green + src[i-dim+1].green);

    dst[i].red = (unsigned short) (red/4);
    dst[i].blue = (unsigned short) (blue/4);
    dst[i].green = (unsigned short) (green/4);
    ++i; lim = i+dim-2;

    /* Region 7 : lower row */
	for (; i < lim; ++i)
    {  
        red = (src[i-1].red + src[i].red + src[i+1].red
        + src[i-dim-1].red + src[i-dim].red + src[i-dim+1].red );

        blue = (src[i-1].blue + src[i].blue + src[i+1].blue
        + src[i-dim-1].blue + src[i-dim].blue + src[i-dim+1].blue );

        green = (src[i-1].green + src[i].green + src[i+1].green
        + src[i-dim-1].green + src[i-dim].green + src[i-dim+1].green );

        dst[i].red = (unsigned short) (red/6);
        dst[i].blue = (unsigned short) (blue/6);
        dst[i].green = (unsigned short) (green/6);
    }
    
    /* Region 8 : Lower right corner */
    red = (src[i-1].red + src[i].red
    + src[i-dim-1].red + src[i-dim].red);

    blue = (src[i-1].blue + src[i].blue
    + src[i-dim-1].blue + src[i-dim].blue);

    green = (src[i-1].green + src[i].green
    + src[i-dim-1].green + src[i-dim].green);

    dst[i].red = (unsigned short) (red/4);
    dst[i].blue = (unsigned short) (blue/4);
    dst[i].green = (unsigned short) (green/4);

    /* Region 9 : right column */
    lim = i; // lower right corner
    i = dim+dim-1;
	for (; i < lim; i+=dim)
    { 
        red = (src[i-1].red + src[i].red
        + src[i-dim-1].red + src[i-dim].red
        + src[i+dim-1].red + src[i+dim].red );

        blue = (src[i-1].blue + src[i].blue
        + src[i-dim-1].blue + src[i-dim].blue
        + src[i+dim-1].blue + src[i+dim].blue );

        green = (src[i-1].green + src[i].green
        + src[i-dim-1].green + src[i-dim].green
        + src[i+dim-1].green + src[i+dim].green );

        dst[i].red = (unsigned short) (red/6);
        dst[i].blue = (unsigned short) (blue/6);
        dst[i].green = (unsigned short) (green/6);
    }

}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    opt2_smooth(dim, src, dst); // fastest
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
    add_smooth_function(&opt1_smooth, opt1_smooth_descr);
    add_smooth_function(&opt2_smooth, opt2_smooth_descr);
}

