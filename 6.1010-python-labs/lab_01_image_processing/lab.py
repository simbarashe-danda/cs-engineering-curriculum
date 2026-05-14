
"""
6.101 Lab:
Image Processing
"""
""" 14 May 2026 """

import os
from PIL import Image

def inverted(image):
    """
    Given an image, produce a new image that has all of its colors inverted.

    This process should not mutate the original image, but rather should create
    and return a new image.
    """
    # there was bug in the result dictionary,
    # "pixels" = [] crashes when we try to assign elements to pixels for the first time
    height = image["height"]
    width = image["width"]
    pix = image["pixels"]
    new_pix = [0] * (height * width)    # prefill 0s
    ind = 0 # index
    # there was bug at the two for loops. height and width was interchanged
    for row in range(height):
        for col in range(width):
            color = pix[row*width + col]
            new_pix[ind] = 255 - color
            ind += 1
    # there was bug at the inversion process. there was 256 - color instead of 255
    return {
        "mode": "greyscale",
        "height": height,
        "width": width,
        "pixels": new_pix
    }

# HELPER FUNCTIONS
# Solution and  implementation below is my own.
def correlate(image, kernel):
    """
    Create and return a new dictionary representing the result of correlating
    the given `image` with the given `kernel`.

    This process should not mutate the input image. It should output a new
    image dictionary where the pixel values have not been rounded or clipped.

    Parameters:
        `image`: a greyscale image
        `kernel`: a dictionary mapping (r, c) indices to kernel values, where
                  (0,0) represents the pixel in the center of the kernel

    Returns:
        a new image representing the result of the correlation
    """
    height = image["height"]
    width = image["width"]
    pixel = image["pixels"]

    new_pixels = [0] * (height * width) # pixel list to be populated
    ind = 0 # index
    kernel_items = list(kernel.items()) # better perfomance that keeping on looking into dict

    for r in range(height):  # fixed row
        for c in range(width):   # fixed col
            cr = 0.0    # correlated values
            for (x,y), v in kernel_items:    # for index and value in kernel dict
                rw, cl = r+x, c+y   # row and col
                if (0 <= rw < height) and (0 <= cl < width):   # coordinates are in range
                    cr += pixel[rw*width + cl] * v  # correlate    
            new_pixels[ind] = cr    # grow correlated pixels list
            ind += 1

    return  {
        "mode": "greyscale",
        "height": height,
        "width": width,
        "pixels": new_pixels,
    }

def round_and_clip_image(image):
    """
    Create and return a new greyscale image dictionary representing the result
    of transforming the pixel values in the given `image` into integers within
    the valid range of [0, 255].

    All values should be converted to integers using Python's `round` function.
    This process should not mutate the input image.
    """
    pix_list = image["pixels"]
    clip_list = []
    for pix in pix_list:
        # Inline clipping
        clipped = 0 if pix < 0 else (255 if pix > 255 else round(pix))
        clip_list.append(clipped)

    return {
        "mode": "greyscale",
        "height": image["height"],
        "width": image["width"],
        "pixels": clip_list,
    }


# FILTERS


def blurred(image, kernel_size):
    """
    Create and return a new greyscale image dictionary representing the result
    of applying a box blur (with the given `kernel_size`) to the given `image`.

    This process should not mutate the input image.
    """
    # first, create a representation for the appropriate n-by-n kernel
    # then compute the correlation of the input image with that kernel
    # finally, adjust the correlated pixel values to be valid integers
    kernel = {} # kernel dct
    kernel_val = 1.0/kernel_size**2   # kernel value that should sum to 1
    k = kernel_size//2 # used for kernel coordinates
    for r in range(kernel_size):
        for c in range(kernel_size):
            kernel[(r-k, c-k)] = kernel_val # assign val to each kernel coordinate
    cr = correlate(image, kernel)   # correlated img with, possibly floats and out of bound vals
    return round_and_clip_image(cr) # remove floats and out of bounds

def sharpened(image, kernel_size):
    """
    Create and return a new greyscale image dictionary representing the result
    of applying the 'sharpen' operation to the given `image`.

    This process should not mutate the input image.
    """
    blur = blurred(image, kernel_size)

    blur_pix = blur["pixels"]
    orig_pix = image["pixels"]
    sharp_pix = []

    # sharpen an image9
    for orig, blr in zip(orig_pix, blur_pix):
        val = 2 * orig - blr
        # Inline clipping
        clipped = 0 if val < 0 else (255 if val > 255 else round(val))
        sharp_pix.append(clipped)

    return { # return sharpened img
        "mode": "greyscale",
        "height": image["height"],
        "width": image["width"],
        "pixels": sharp_pix,
    }



# HELPER FUNCTIONS FOR DISPLAYING, LOADING, AND SAVING IMAGES
# code below is from MIT stuff

def get_pixel(image, row, col):
    """
    Return the value of the pixel at the given location in the given image as
    an integer between 0 and 255 (inclusive).
    """
    # there was a bug at the return line
    assert 0 <= col < image["width"]
    assert 0 <= row < image["height"]
    return image["pixels"][row*image["width"] + col]

def set_pixel(image, row, col, color):
    """
    Mutate the given image so that the value of the pixel at the given location
    becomes the given color
    """
    # there was a bug at the return line,
    # row column indexing was broken
    assert 0 <= row < image["height"]
    assert 0 <= col < image["width"]
    image["pixels"][row*image["width"] + col] = color  # assign color at proper x,y coordinate

def print_values(image):
    """
    Given an image dictionary, prints a string representation of the image
    pixel values to the terminal. This function may be helpful for manually
    testing and debugging tiny image examples.

    Note that pixel values that are floats will be rounded to the nearest int.
    """
    assert image["mode"] in {"greyscale", "color"}
    print(f"{image['mode'].title()} image with {image['height']} rows and {image['width']} columns:")
    print()
    for r in range(image["height"]):
        if image['mode'] == "greyscale":
            formatted_pixel = lambda p: f"{round(p):>3}"
        else:
            formatted_pixel = lambda p: ("(" + ", ".join(f"{round(v):>3}" for v in p) + ")")
        print("   ".join(formatted_pixel(get_pixel(image, r, c)) for c in range(image["width"])))


def load_image(filename, mode="greyscale"):
    """
    Loads an image from the given file and returns a dictionary
    representing that image.  This also performs conversion to greyscale.

    Invoked as, for example:
       i = load_image("test_images/cat.png") # greyscale image
       c = load_image("test_images/bluegill.png", mode="color") # color image
    """
    assert mode in {"greyscale", "color"}
    if not os.path.isabs(filename):
        filename = os.path.join(os.path.dirname(__file__), filename)
    with open(filename, "rb") as image_handle:
        image = Image.open(image_handle).convert("RGB" if mode == "color" else "L")
        try:
            pixels = list(image.get_flattened_data())
        except AttributeError:
            pixels = list(image.getdata())
        width, height = image.size
        return {
            "mode": mode,
            "height": height,
            "width": width,
            "pixels": list(pixels),
        }


def save_image(image, filename, buffer_filetype="PNG"):
    """
    Saves the given image to disk or to a file-like object.  If filename is
    given as a string, the file type will be inferred from the given name.  If
    filename is given as a file-like object, the file type will be determined
    by the "buffer_filetype" parameter.
    """
    # make sure we have a valid image
    if image['mode'] not in {'greyscale', 'color'}:
        raise ValueError(f'Unknown image mode: {image["mode"]}')
    if (pixcount := image['height'] * image['width']) != len(image['pixels']):
        raise ValueError(f'Incorrect number of pixels (expected {pixcount}, got {len(image["pixels"])})')
    if image['mode'] == 'greyscale':
        if not all(isinstance(x, int) and 0 <= x <= 255 for x in image['pixels']):
            msg = "Pixel values in a greyscale image must be integers between 0 and 255"
            raise ValueError(msg)
    else:
        msg = "Pixel values in a color image must be tuples of length 3"
        if not all(
            isinstance(tuple, p) and len(p) == 3
            and all(isinstance(x, int) and 0 <= x < 255 for x in p)
            for p in image['pixels']
        ):
            msg = "Pixel values in a color image must be length-3 tuples of integers between 0 and 255"
            raise ValueError(msg)

    if isinstance(filename, str):
        if not os.path.isabs(filename):
            # treat relative paths as being relative to this file
            filename = os.path.join(os.path.dirname(__file__), filename)

            # make folders if they do not exist
            directory = os.path.realpath(os.path.dirname(filename))
            if directory and not os.path.exists(directory):
                os.makedirs(directory)

    # actually save image
    out = Image.new(
        mode=("L" if image["mode"] == "greyscale" else "RGB"),
        size=(image["width"], image["height"]),
    )
    out.putdata(image["pixels"])
    if isinstance(filename, str):
        out.save(filename)
    else:
        out.save(filename, buffer_filetype)
    out.close()


if __name__ == "__main__":
    # tests
    
    img = load_image("pump.png")
    save_image(blurred(img, 13), "pump_blurred.png")
    save_image(round_and_clip_image(correlate(img, {(-4,-6): 1})), "pump_correlated.png")

    img = load_image("nature.png")
    save_image(inverted(img), "nature_inverted.png")
    save_image(sharpened(img, 11), "nature_sharpened.png")
