#!/usr/bin/env python3

import os
import pickle
import hashlib

import lab
import pytest

from PIL import Image

TEST_DIRECTORY = os.path.dirname(__file__)


def object_hash(x):
    return hashlib.sha512(pickle.dumps(x)).hexdigest()


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


def compare_images(result, expected, exact=False):
    assert set(result.keys()) == {
        "mode",
        "height",
        "width",
        "pixels",
    }, f"Incorrect keys in dictionary"
    assert result["mode"] == expected["mode"], "Modes must match"
    assert result["height"] == expected["height"], "Heights must match"
    assert result["width"] == expected["width"], "Widths must match"
    assert (
        len(result["pixels"]) == result["height"] * result["width"]
    ), f"Incorrect number of pixels, exp_image {result['height']*result['width']}"
    num_incorrect_val = 0
    first_incorrect_val = None
    num_bad_type = 0
    first_bad_type = None
    num_bad_range = 0
    first_bad_range = None

    row, col = 0, 0
    correct_image = True
    for index, (res, exp) in enumerate(zip(result["pixels"], expected["pixels"])):
        if exact and not isinstance(res, int):
            correct_image = False
            num_bad_type += 1
            if not first_bad_type:
                first_bad_type = f"Pixels must all be integers!"
                first_bad_type += (
                    f"\nPixel had value {res} at index {index} (row {row}, col {col})."
                )
        if exact and res < 0 or res > 255:
            num_bad_range += 1
            correct_image = False
            if not first_bad_range:
                first_bad_range = f"Pixels must all be in the range from [0, 255]!"
                first_bad_range += (
                    f"\nPixel had value {res} at index {index} (row {row}, col {col})."
                )
        if (exact and res != exp) or ((not exact) and abs(res - exp) > 1e-6):
            correct_image = False
            num_incorrect_val += 1
            if not first_incorrect_val:
                first_incorrect_val = f"Pixels must match"
                first_incorrect_val += f"\nPixel had value {res} but expected {exp} at index {index} (row {row}, col {col})."

        if col + 1 == result["width"]:
            col = 0
            row += 1
        else:
            col += 1

    msg = "Image is correct!"
    if first_bad_type:
        msg = (
            first_bad_type
            + f"\n{num_bad_type} pixel{'s'*int(num_bad_type>1)} had this problem."
        )
    elif first_bad_range:
        msg = (
            first_bad_range
            + f"\n{num_bad_range} pixel{'s'*int(num_bad_range>1)} had this problem."
        )
    elif first_incorrect_val:
        msg = (
            first_incorrect_val
            + f"\n{num_incorrect_val} pixel{'s'*int(num_incorrect_val>1)} had incorrect value{'s'*int(num_incorrect_val>1)}."
        )

    assert correct_image, msg


def test_load():
    result_image = load_image(
        os.path.join(TEST_DIRECTORY, "test_images", "centered_pixel.png")
    )
    exp_image = {
        "mode": "greyscale",
        "height": 11,
        "width": 11,
        "pixels": [0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0],
    }
    compare_images(result_image, exp_image)


def test_get_pixel():
    test_image = load_image(os.path.join(TEST_DIRECTORY, "test_images", "bluegill.png"))
    grabbed_pixels = []
    for r in range(test_image["height"]):
        for c in range(test_image["width"]):
            grabbed_pixels.append(lab.get_pixel(test_image, r, c))
    assert grabbed_pixels == test_image["pixels"]


def test_set_pixel():
    test_image = load_image(os.path.join(TEST_DIRECTORY, "test_images", "bluegill.png"))
    adjustments = [
        (104, 29, 31229, 53),
        (79, 45, 23745, 97),
        (183, 297, 55197, 89),
        (20, 215, 6215, 231),
        (126, 82, 37882, 145),
        (212, 89, 63689, 214),
        (81, 67, 24367, 214),
        (46, 240, 14040, 79),
        (200, 132, 60132, 94),
        (197, 80, 59180, 142),
        (197, 80, 59180, 143),
        (197, 80, 59180, 144),
    ]
    for r, c, ix, val in adjustments:
        assert test_image["pixels"][ix] == lab.get_pixel(test_image, r, c) != val
        lab.set_pixel(test_image, r, c, val)
        assert test_image["pixels"][ix] == lab.get_pixel(test_image, r, c) == val

    with pytest.raises(AssertionError):
        lab.set_pixel(test_image, -1, 0, 42)

    with pytest.raises(AssertionError):
        lab.set_pixel(test_image, test_image["height"], 0, 42)

    with pytest.raises(AssertionError):
        lab.set_pixel(test_image, 0, -1, 42)

    with pytest.raises(AssertionError):
        lab.set_pixel(test_image, 0, test_image["width"], 42)


def test_inverted_1():
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "centered_pixel.png")
    input_image = load_image(input_fname)
    input_hash = object_hash(input_image)
    result_image = lab.inverted(input_image)
    exp_image = {
        "mode": "greyscale",
        "height": 11,
        "width": 11,
        "pixels": [255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255,   0, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255],
    }
    compare_images(result_image, exp_image)
    assert (
        object_hash(input_image) == input_hash
    ), "Be careful not to modify the original image!"


def test_inverted_2():
    assert False


@pytest.mark.parametrize("fname", ["mushroom", "twocats", "chess"])
def test_inverted_images(fname):
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", "%s_invert.png" % fname)
    input_image = load_image(input_fname)
    input_hash = object_hash(input_image)
    result_image = lab.inverted(input_image)
    exp_image = load_image(exp_fname)
    compare_images(result_image, exp_image)
    assert (
        object_hash(input_image) == input_hash
    ), "Be careful not to modify the original image!"


def test_oob_get_pixel():
    expected = [
        (131, 153, 126),
        (140, 230, 55),
        (213, 51, 161),
        (140, 164, 136),
        (7, 293, 149),
        (-1, 146, 0),
        (220, -9, 0),
        (249, -1, 0),
        (220, 243, 0),
        (220, 71, 0),
        (-1, -1, 0),
        (-1, 300, 0),
        (220, -1, 0),
        (220, 300, 0),
        (109, 384, 0),
        (-71, -47, 0),
        (58, -55, 0),
        (-3, 266, 0),
        (221, 258, 0),
        (267, 197, 0),
        (221, -11, 0),
        (-60, 244, 0),
        (301, 249, 0),
        (115, 371, 0),
    ]
    test_image = load_image(os.path.join(TEST_DIRECTORY, "test_images", "bluegill.png"))
    for r, c, val in expected:
        assert lab.get_pixel(test_image, r, c) == val


def test_correlate_small():
    test_image = {
        "mode": "greyscale",
        "height": 5,
        "width": 5,
        "pixels": [10] * 25,
    }
    lab.set_pixel(test_image, 2, 2, 255)
    out = lab.correlate(test_image, {(0, 0): 1})
    compare_images(out, test_image, exact=False)

    out = lab.correlate(test_image, {(1, 1): 0.5, (-1, -1): 0.5})
    expected = {
        "mode": "greyscale",
        "height": 5,
        "width": 5,
        "pixels": [
            5,     5,    5,     5,   0,
            5, 132.5,   10,    10,   5,
            5,    10,   10,    10,   5,
            5,    10,   10, 132.5,   5,
            0,     5,    5,     5,   5]}

    out = lab.correlate(test_image, {(2, 1): -1})
    expected = {
        "mode": "greyscale",
        "height": 5,
        "width": 5,
        "pixels": [
            -10, -255, -10, -10,  0,
            -10,  -10, -10, -10,  0,
            -10,  -10, -10, -10,  0,
              0,    0,   0,   0,  0,
              0,    0,   0,   0,  0]}
    compare_images(out, expected, exact=False)

_test_kernels = [
    {(0, 0): 1},
    {(1, 1): 0.5, (-1, -1): 0.5},
    {(2, 1): 0.75, (0, 0): 0.25},
]

@pytest.mark.parametrize("kernel", range(3))
@pytest.mark.parametrize("fname", ["mushroom", "twocats", "chess"])
def test_correlate_images(kernel, fname):
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
    input_image = load_image(input_fname)
    result = lab.correlate(input_image, _test_kernels[kernel])
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", "%s_correlate_%02d.pickle" % (fname, kernel)
    )
    with open(exp_fname, 'rb') as f:
        exp_image = pickle.load(f)
    compare_images(result, exp_image, exact=False)


def test_blurred_black_image():
    # REPLACE THIS with your 1st test case from section 6.1
    assert False


def test_blurred_centered_pixel():
    # REPLACE THIS with your 2nd test case from section 6.1
    assert False


@pytest.mark.parametrize("kernsize", [1, 3, 7])
@pytest.mark.parametrize("fname", ["mushroom", "twocats", "chess"])
def test_blurred_images(kernsize, fname):
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", "%s_blur_%02d.png" % (fname, kernsize)
    )
    input_image = load_image(input_fname)
    input_hash = object_hash(input_image)
    result_image = lab.blurred(input_image, kernsize)
    exp_image = load_image(exp_fname)
    compare_images(result_image, exp_image)
    assert (
        object_hash(input_image) == input_hash
    ), "Be careful not to modify the original image!"


@pytest.mark.parametrize("kernsize", [1, 3, 9])
@pytest.mark.parametrize("fname", ["mushroom", "twocats", "chess"])
def test_sharpened_images(kernsize, fname):
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", "%s_sharp_%02d.png" % (fname, kernsize)
    )
    input_image = load_image(input_fname)
    input_hash = object_hash(input_image)
    result_image = lab.sharpened(input_image, kernsize)
    exp_image = load_image(exp_fname)
    compare_images(result_image, exp_image)
    assert (
        object_hash(input_image) == input_hash
    ), "Be careful not to modify the original image!"
