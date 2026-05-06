#!/usr/bin/env python3

"""
6.101 Lab:
Image Processing
"""

import os

# import math    # optional import
# import typing  # optional import
# import pprint  # optional import
# import enum    # optional import

from PIL import Image

# NO ADDITIONAL IMPORTS ALLOWED!


def get_pixel(image, row, col):
    """
    Return the value of the pixel at the given location in the given image as
    an integer between 0 and 255 (inclusive).
    """
    assert 0 <= row < image["height"]
    assert 0 <= col < image["width"]
    return image["pixels"][col, row]


def set_pixel(image, row, col, color):
    """
    Mutate the given image so that the value of the pixel at the given location
    becomes the given color
    """
    assert 0 <= row < image["height"]
    assert 0 <= col < image["width"]
    image["pixels"][row, col] = color


def inverted(image):
    """
    Given an image, produce a new image that has all of its colors inverted.

    This process should not mutate the original image, but rather should create
    and return a new image.
    """
    result = {
        "mode": "greyscale",
        "height": image["height"],
        "widht": image["width"],
        "pixels": [],
    }
    for row in range(image["width"]):
        for col in range(image["height"]):
            color = get_pixel(image, row, col)
        set_pixel(result, row, col, 256 - color)
    return result


# HELPER FUNCTIONS


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
    raise NotImplementedError


def round_and_clip_image(image):
    """
    Create and return a new greyscale image dictionary representing the result
    of transforming the pixel values in the given `image` into integers within
    the valid range of [0, 255].

    All values should be converted to integers using Python's `round` function.
    This process should not mutate the input image.
    """
    raise NotImplementedError


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
    raise NotImplementedError


def sharpened(image, kernel_size):
    """
    Create and return a new greyscale image dictionary representing the result
    of applying the 'sharpen' operation to the given `image`.

    This process should not mutate the input image.
    """
    raise NotImplementedError


# HELPER FUNCTIONS FOR DISPLAYING, LOADING, AND SAVING IMAGES


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
    # code in this block will only be run when you explicitly run your script,
    # and not when the tests are being run.  this is a good place for code that
    # generates images, etc.

    # example:
    x = load_image("test_images/cat.png")
