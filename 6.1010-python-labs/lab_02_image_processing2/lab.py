"""
6.101 Lab:
Image Processing
"""

""" 19 May 2026 """

import os
from PIL import Image

# PIXEL ACCESS

def get_pixel_extend(image, r, c):
    """
    Returns pixel at (r, c), extending boundaries for out-of-bounds coordinates.
    """
    hi, wi = image["height"], image["width"]
    
    # Clamp coordinates to valid ranges
    r, c = (
        min(max(r, 0), hi - 1),
        min(max(c, 0), wi - 1),
    )

    # Return flattened index
    return image["pixels"][r * wi + c]


def get_pixel_wrap(image, r, c):
    """
    Returns pixel at (r, c), wrapping around boundaries for out-of-bounds coordinates.
    """
    max_r, max_c = image["height"], image["width"]
    
    # Wrap coordinates via modulo
    r, c = (r % max_r), (c % max_c)

    # Return flattened index
    return image["pixels"][r * max_c + c]


def get_pixel(image, r, c):
    """
    Returns pixel at (r, c) if within bounds, otherwise 0.
    """
    w, h = image["width"], image["height"]

    return (
        image["pixels"][r * w + c]
        if (0 <= r < h) and (0 <= c < w)
        else 0
    )



# CORE OPERATIONS

def correlate(img, kernel, get_pix=get_pixel_extend):
    """
    Applies a correlation kernel to an image.
    """
    h = img["height"]
    w = img["width"]

    new_pix = [0] * (h * w)
    i = 0
    kernel_items = list(kernel.items())

    for r in range(h):
        for c in range(w):
            cr = 0.0
            
            # Apply kernel at current pixel
            for (x, y), v in kernel_items:
                r1, c1 = r + x, c + y
                cr += get_pix(img, r1, c1) * v
            
            new_pix[i] = cr
            i += 1
    return {
        "mode": "greyscale",
        "height": h,
        "width": w,
        "pixels": new_pix,
    }


def round_and_clip_image(image):
    """
    Rounds pixel values and clips them strictly to [0, 255].
    """
    pix_list = image["pixels"]
    clip_list = [0 if pix < 0 else 255 if pix > 255 else round(pix) for pix in pix_list]

    return {
        "mode": "greyscale",
        "height": image["height"],
        "width": image["width"],
        "pixels": clip_list,
    }


# FILTERS

def inverted(image):
    """
    Inverts pixel intensities (255 - value).
    """
    height = image["height"]
    width = image["width"]
    pix = image["pixels"]
    
    new_pix = [0] * (height * width)
    ind = 0
    
    for row in range(height):
        for col in range(width):
            color = pix[row * width + col]
            new_pix[ind] = 255 - color
            ind += 1
            
    return {"mode": "greyscale", "height": height, "width": width, "pixels": new_pix}


def blurred(image, kernel_size):
    """
    Applies a box blur using an n-by-n uniform kernel.
    """
    kernel = {}
    kernel_val = 1.0 / kernel_size**2
    k = kernel_size // 2
    
    # Generate uniform kernel
    for r in range(kernel_size):
        for c in range(kernel_size):
            kernel[(r - k, c - k)] = kernel_val
            
    cr = correlate(image, kernel)
    return round_and_clip_image(cr)


def sharpened(image, kernel_size):
    """
    Sharpens image by subtracting a blurred version from the original.
    """
    blur = blurred(image, kernel_size)

    blur_pix = blur["pixels"]
    orig_pix = image["pixels"]
    sharp_pix = []

    # Apply unsharp mask logic
    for orig, blr in zip(orig_pix, blur_pix):
        val = 2 * orig - blr
        clipped = 0 if val < 0 else (255 if val > 255 else round(val))
        sharp_pix.append(clipped)

    return {
        "mode": "greyscale",
        "height": image["height"],
        "width": image["width"],
        "pixels": sharp_pix,
    }


def edges(image):
    """
    Computes edge magnitude using Sobel-like kernels K1 and K2.
    """
    k1 = {
        (-1, -1): -1, (-1, 0): -2, (-1, 1): -1,
        (1, -1): 1,   (1, 0): 2,   (1, 1): 1,
    }
    
    k2 = {
        (-1, -1): -1, (-1, 1): 1,
        (0, -1): -2,  (0, 1): 2,
        (1, -1): -1,  (1, 1): 1,
    }
    
    rnd, cr = (
        lambda x: 0 if x < 0 else (255 if x > 255 else round(x)),
        correlate,
    )
    
    o1_pix, o2_pix = cr(image, k1)["pixels"], cr(image, k2)["pixels"]
    
    size = len(image["pixels"])
    new_pix = [0] * size
    
    root, sq = lambda x: (x**0.5) if x > 0 else x, lambda x: x**2

    # Calculate root sum of squares per pixel
    for i in range(size):
        px1, px2 = o1_pix[i], o2_pix[i]
        new_pix[i] = rnd(root(sq(px1) + sq(px2)))

    return {
        "mode": "greyscale",
        "height": image["height"],
        "width": image["width"],
        "pixels": new_pix,
    }


# FILTER COMPOSITION & COLOR

def color_filter_from_greyscale_filter(filt, *args):
    """
    Adapts a greyscale filter to process RGB color images per channel.
    Args: Kernel size or None
    """
    def color_filter(image):
        h, w = image["height"], image["width"]
        pixels = image["pixels"]

        if not pixels:
            return {"mode": image["mode"], "height": h, "width": w, "pixels": []}

        # Isolate RGB channels
        r_pix, g_pix, b_pix = map(list, zip(*pixels))

        image1 = lambda pix_type: {"mode": "greyscale", "height": h, "width": w, "pixels": pix_type}
        p = "pixels"

        filt_r, filt_g, filt_b = [], [], []
        
        # Apply filter per channel
        filt_r = filt(image1(r_pix), *args)[p]
        filt_g = filt(image1(g_pix), *args)[p]
        filt_b = filt(image1(b_pix), *args)[p]

        # Recombine channels
        filt_pixels = list(zip(filt_r, filt_g, filt_b))
        
        return {
            "mode": image["mode"],
            "height": h,
            "width": w,
            "pixels": filt_pixels,
        }

    return color_filter


def filter_cascade(filters):
    """
    Chains multiple image filters into a single operation.
    """
    def apply_filt(image):
        for f in filters:
            image = f(image)
        return image
    return apply_filt


# SEAM CARVING

def greyscale_image_from_color_image(color_image):
    """
    Converts RGB image to greyscale using standard luminance weights.
    """
    pix_list = color_image["pixels"]
    g_scale = [round(.299*r + .587*g + .114*b) for (r,g,b) in pix_list]

    return {
        "mode": "greyscale",
        "height": color_image["height"],
        "width": color_image["width"],
        "pixels": g_scale,
    }


def compute_energy(grey_image):
    """
    Generates energy map using edge detection.
    """
    return edges(grey_image)


def cumulative_energy_map(energy_image):
    """
    Computes minimum cumulative energy map for seam carving.
    """
    hi = energy_image["height"]
    wd = energy_image["width"]

    e_pix = energy_image["pixels"]
    pixels = e_pix[:wd]  # Copy first row as base case

    for r in range(1, hi):
        row, row1 = (r-1)*wd, r*wd

        # Left edge
        i, n = row, row1
        min_adj = min(pixels[i], pixels[i+1])
        pixels.append(min_adj + e_pix[n])

        # Middle columns
        for c in range(1, wd-1):
            i, n = row+c, row1+c
            min_adj = min(pixels[i-1], pixels[i], pixels[i+1])
            pixels.append(min_adj + e_pix[n])

        # Right edge
        i, n = row + wd-1, row1 + wd-1
        min_adj = min(pixels[i-1], pixels[i])
        pixels.append(min_adj + e_pix[n])

    return {
        "mode": "greyscale",
        "height": hi,
        "width": wd,
        "pixels": pixels,
    }

def minimum_energy_seam(cem):
    """
    given a "cumulative energy map" dictionary,
    return a set of the indices into the pixels list associated with the
    vertical seam that should be removed from the original image.
    """
    ht, wt = cem["height"],cem["width"]
    pix = cem["pixels"] # reference 
    idx = min( # min val index, last row
        range(wt*(ht-1), ht*wt), key=lambda i:pix[i])    

    indices = [idx]
    for _ in range(ht-1):
        x = idx-wt   # upper row direct adjacent
        f1,f2 = (x % wt) != 0, (x % wt) != (wt-1)  # flags for far right and far left
        idx = min(range(x-f1, x+1+f2), key=lambda i:pix[i])
        indices.append(idx)
    return set(indices)

def image_without_seam(color_image, seam):
    """
    given an image and a set of indices,
    return a new image with the associated pixels removed.
    """
    pix = color_image["pixels"]
    new_pix = [val for (i, val) in enumerate(pix) if i not in seam]

    return {
        "mode": color_image["mode"],
        "height": color_image["height"],
        "width": color_image["width"]-1,    # only a column is lost
        "pixels": new_pix,
    }




# HELPER FUNCTIONS FOR DISPLAYING, LOADING, AND SAVING IMAGES
# code below is from MIT stuff
 
def set_pixel(image, row, col, color):
    """
    Mutate the given image so that the value of the pixel at the given location
    becomes the given color
    """
    # there was a bug at the return line,
    # row column indexing was broken
    assert 0 <= row < image["height"]
    assert 0 <= col < image["width"]
    image["pixels"][row * image["width"] + col] = (
        color  # assign color at proper x,y coordinate
    )


def print_values(image):
    """
    Given an image dictionary, prints a string representation of the image
    pixel values to the terminal. This function may be helpful for manually
    testing and debugging tiny image examples.

    Note that pixel values that are floats will be rounded to the nearest int.
    """
    assert image["mode"] in {"greyscale", "color"}
    print(
        f"{image['mode'].title()} image with {image['height']} rows and {image['width']} columns:"
    )
    print()
    for r in range(image["height"]):
        if image["mode"] == "greyscale":
            formatted_pixel = lambda p: f"{round(p):>3}"
        else:
            formatted_pixel = lambda p: (
                "(" + ", ".join(f"{round(v):>3}" for v in p) + ")"
            )
        print(
            "   ".join(
                formatted_pixel(get_pixel(image, r, c)) for c in range(image["width"])
            )
        )


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
    if image["mode"] not in {"greyscale", "color"}:
        raise ValueError(f"Unknown image mode: {image['mode']}")
    if (pixcount := image["height"] * image["width"]) != len(image["pixels"]):
        raise ValueError(
            f"Incorrect number of pixels (expected {pixcount}, got {len(image['pixels'])})"
        )
    if image["mode"] == "greyscale":
        if not all(isinstance(x, int) and 0 <= x <= 255 for x in image["pixels"]):
            msg = "Pixel values in a greyscale image must be integers between 0 and 255"
            raise ValueError(msg)
    else:
        msg = "Pixel values in a color image must be tuples of length 3"
        if not all(
            isinstance(p, tuple)
            and len(p) == 3
            and all(isinstance(x, int) and 0 <= x < 256 for x in p)
            for p in image["pixels"]
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

    img = load_image("test_images/pigbird.png")
    # save_image(blurred(img, 13), "pump_blurred.png")
    save_image(
        round_and_clip_image(correlate(img, {(-4, -6): 0.5, (3, 2): 0.5})),
        "pigbird_correlated_ext.png",
    )
    save_image(
        round_and_clip_image(
            correlate(img, {(-4, -6): 0.5, (3, 2): 0.5}, get_pixel_wrap)
        ),
        "pigbird_correlated_wrap.png",
    )
    save_image(
        round_and_clip_image(correlate(img, {(-4, -6): 0.5, (3, 2): 0.5}, get_pixel)),
        "pigbird_correlated_norm.png",
    )
