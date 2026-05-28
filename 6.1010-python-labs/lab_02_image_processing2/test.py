#!/usr/bin/env python3

import os
import lab
import pickle
import hashlib

import pytest


TEST_DIRECTORY = os.path.dirname(__file__)


def object_hash(x):
    return hashlib.sha512(pickle.dumps(x)).hexdigest()


def compare_images(result, expected):
    assert set(result.keys()) == {"mode", "height", "width", "pixels"}, (
        f"Incorrect keys in dictionary"
    )
    assert result["mode"] == expected["mode"], "Modes must match"
    assert result["height"] == expected["height"], "Heights must match"
    assert result["width"] == expected["width"], "Widths must match"
    emsg = f"Incorrect number of pixels, expected {result['height'] * result['width']}"
    assert len(result["pixels"]) == result["height"] * result["width"], emsg
    num_incorrect_val = 0
    first_incorrect_val = None
    num_bad_type = 0
    first_bad_type = None

    row, col = 0, 0
    correct_image = True
    for index, (res, exp) in enumerate(zip(result["pixels"], expected["pixels"])):
        emsg = f"\nPixel had value {res} at index {index} (row {row}, col {col})."
        if isinstance(exp, int):  # greyscale image:
            if not isinstance(res, int):
                correct_image = False
                num_bad_type += 1
                if not first_bad_type:
                    first_bad_type = "Pixels must all be integers!"
                    first_bad_type += emsg
            if res != exp:
                correct_image = False
                num_incorrect_val += 1
                if not first_incorrect_val:
                    first_incorrect_val = "Pixels must match"
                    first_incorrect_val += f"\nPixel had value {res} but expected {exp} at index {index} (row {row}, col {col})."
        else:  # color image
            if not isinstance(res, tuple) or len(res) != 3:
                correct_image = False
                num_bad_type += 1
                if not first_bad_type:
                    first_bad_type = f"Color pixels must all be length 3 tuples!"
                    first_bad_type += emsg
            elif not all(isinstance(pix, int) for pix in res):
                correct_image = False
                num_bad_type += 1
                if not first_bad_type:
                    first_bad_type = f"Color pixel tuple values must all be integers!"
                    first_bad_type += emsg

            if res != exp:
                correct_image = False
                num_incorrect_val += 1
                if not first_incorrect_val:
                    first_incorrect_val = f"Pixels must match"
                    first_incorrect_val += f"\nPixel had value {res} but expected {exp}"
                    first_incorrect_val += (
                        f"\n at index {index} (row {row}, col {col})."
                    )

        # increment row / col
        if col + 1 == result["width"]:
            col = 0
            row += 1
        else:
            col += 1

    msg = "Image is correct!"
    if first_bad_type:
        msg = first_bad_type
        msg += f"\n{num_bad_type} pixel{'s' * (num_bad_type > 1)} had this problem."
    elif first_incorrect_val:
        msg = first_incorrect_val
        msg += f"\n{num_incorrect_val} pixel{'s' * (num_incorrect_val > 1)} had incorrect value{'s' * int(num_incorrect_val > 1)}."

    assert correct_image, msg


# CORRELATION EDGE EFFECTS


@pytest.mark.parametrize("fname", ["construct", "cat", "bluegill"])
@pytest.mark.parametrize("mode", ["color", "greyscale"])
@pytest.mark.parametrize("edge", ["wrap", "extend"])
def test_edge_behaviors(fname, mode, edge):
    func = getattr(lab, f"get_pixel_{edge}")

    with open(
        os.path.join(TEST_DIRECTORY, "test_results", f"{fname}_{mode}_{edge}.pickle"),
        "rb",
    ) as f:
        vals = pickle.load(f)

    im = lab.load_image(
        os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png"), mode=mode
    )

    for r, c, ar, ac, val in vals:
        gotval = func(im, r, c)
        assert val == gotval, (
            f"Expected value at ({r}, {c}) to be the same as ({ar}, {ac}): {val} (got {gotval})"
        )


def test_blurred_extend():
    for kernsize in [1, 3, 7]:
        for fname in ["mushroom", "twocats", "chess"]:
            input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
            exp_fname = os.path.join(
                TEST_DIRECTORY, "test_results", "%s_blur_%02d.png" % (fname, kernsize)
            )
            input_image = lab.load_image(input_fname)
            input_hash = object_hash(input_image)
            result_image = lab.blurred(input_image, kernsize)
            exp_image = lab.load_image(exp_fname)
            compare_images(result_image, exp_image)
            assert object_hash(input_image) == input_hash, (
                "Be careful not to modify the original image!"
            )


def test_sharpened_extend():
    for kernsize in [1, 3, 9]:
        for fname in ["mushroom", "twocats", "chess"]:
            input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
            exp_fname = os.path.join(
                TEST_DIRECTORY, "test_results", "%s_sharp_%02d.png" % (fname, kernsize)
            )
            input_image = lab.load_image(input_fname)
            input_hash = object_hash(input_image)
            result_image = lab.sharpened(input_image, kernsize)
            exp_image = lab.load_image(exp_fname)
            compare_images(result_image, exp_image)
            assert object_hash(input_image) == input_hash, (
                "Be careful not to modify the original image!"
            )


# SOBEL OPERATOR


@pytest.mark.parametrize("fname", ["mushroom", "twocats", "chess"])
def test_edges_images(fname):
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "%s.png" % fname)
    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", "%s_edges.png" % fname)
    input_image = lab.load_image(input_fname)
    input_hash = object_hash(input_image)
    result_image = lab.edges(input_image)
    exp_image = lab.load_image(exp_fname)
    compare_images(result_image, exp_image)
    assert object_hash(input_image) == input_hash, (
        "Be careful not to modify the original image!"
    )


# COLOR IMAGES


def test_load_color():
    color_image = lab.load_image("test_images/centered_pixel.png", mode="color")
    exp_image = {
        "mode": "color",
        "height": 11,
        "width": 11,
        "pixels": [
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (253, 253, 149),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
        ],
    }
    compare_images(color_image, exp_image)


def test_color_filter_inverted():
    color_image = lab.load_image("test_images/centered_pixel.png", mode="color")
    color_hash = object_hash(color_image)
    color_inverted = lab.color_filter_from_greyscale_filter(lab.inverted)
    assert callable(color_inverted), (
        "color_filter_from_greyscale_filter should return a function."
    )
    result_image = color_inverted(color_image)
    exp_image = {
        "mode": "color",
        "height": 11,
        "width": 11,
        "pixels": [
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (2, 2, 106),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
            (11, 82, 57),
        ],
    }
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


def test_color_filter_edges():
    color_image = lab.load_image("test_images/centered_pixel.png", mode="color")
    color_hash = object_hash(color_image)
    color_edges = lab.color_filter_from_greyscale_filter(lab.edges)
    assert callable(color_edges), (
        "color_filter_from_greyscale_filter should return a function."
    )
    result_image = color_edges(color_image)
    exp_image = {
        "mode": "color",
        "height": 11,
        "width": 11,
        "pixels": [
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (13, 113, 69),
            (18, 160, 98),
            (13, 113, 69),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (18, 160, 98),
            (0, 0, 0),
            (18, 160, 98),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (13, 113, 69),
            (18, 160, 98),
            (13, 113, 69),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
            (0, 0, 0),
        ],
    }
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


@pytest.mark.parametrize("fname", ["frog", "tree"])
@pytest.mark.parametrize("filter_name", ["edges", "inverted"])
def test_color_filter_images(fname, filter_name):
    filter_ = getattr(lab, filter_name)
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_{filter_name}.png"
    )
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)
    color_filter = lab.color_filter_from_greyscale_filter(filter_)
    assert callable(color_filter), (
        "color_filter_from_greyscale_filter should return a function."
    )
    result_image = color_filter(color_image)
    exp_image = lab.load_image(exp_fname, mode="color")

    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


def test_color_blur_small():
    blur_filter = lab.make_blur_filter(3)
    assert callable(blur_filter), "make_blur_filter should return a function."
    color_blur = lab.color_filter_from_greyscale_filter(blur_filter)
    color_image = lab.load_image("test_images/centered_pixel.png", mode="color")
    color_hash = object_hash(color_image)
    result_image = color_blur(color_image)
    exp_image = {
        "mode": "color",
        "height": 11,
        "width": 11,
        "pixels": [
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (245, 182, 193),
            (245, 182, 193),
            (245, 182, 193),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (245, 182, 193),
            (245, 182, 193),
            (245, 182, 193),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (245, 182, 193),
            (245, 182, 193),
            (245, 182, 193),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
            (244, 173, 198),
        ],
    }
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


@pytest.mark.parametrize("ker_size", [3, 5])
@pytest.mark.parametrize("fname", ["cat", "mushroom"])
def test_color_blur_images(fname, ker_size):
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_blurred{ker_size}.png"
    )
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)

    blur_filter = lab.make_blur_filter(ker_size)
    assert callable(blur_filter), "make_blur_filter should return a function."
    color_blur = lab.color_filter_from_greyscale_filter(blur_filter)

    result_image = color_blur(color_image)
    exp_image = lab.load_image(exp_fname, mode="color")
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


@pytest.mark.parametrize("ker_size", [3, 5])
@pytest.mark.parametrize("fname", ["construct", "bluegill"])
def test_color_sharpen_images(fname, ker_size):
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_sharpened{ker_size}.png"
    )
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)

    sharpen_filter = lab.make_sharpen_filter(ker_size)
    assert callable(sharpen_filter), "make_sharpen_filter should return a function."
    color_sharpen = lab.color_filter_from_greyscale_filter(sharpen_filter)

    result_image = color_sharpen(color_image)
    exp_image = lab.load_image(exp_fname, mode="color")
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


def test_small_cascade():
    color_edges = lab.color_filter_from_greyscale_filter(lab.edges)
    color_inverted = lab.color_filter_from_greyscale_filter(lab.inverted)
    color_blur_5 = lab.color_filter_from_greyscale_filter(lab.make_blur_filter(5))

    color_image = lab.load_image("test_images/centered_pixel.png", mode="color")
    color_hash = object_hash(color_image)

    exp_image = {
        "mode": "color",
        "height": 11,
        "width": 11,
        "pixels": [
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (254, 250, 252),
            (254, 244, 248),
            (253, 240, 246),
            (253, 240, 246),
            (253, 240, 246),
            (254, 244, 248),
            (254, 250, 252),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (254, 244, 248),
            (253, 238, 244),
            (252, 227, 238),
            (252, 227, 238),
            (252, 227, 238),
            (253, 238, 244),
            (254, 244, 248),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (253, 240, 246),
            (252, 227, 238),
            (250, 211, 228),
            (250, 211, 228),
            (250, 211, 228),
            (252, 227, 238),
            (253, 240, 246),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (253, 240, 246),
            (252, 227, 238),
            (250, 211, 228),
            (250, 211, 228),
            (250, 211, 228),
            (252, 227, 238),
            (253, 240, 246),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (253, 240, 246),
            (252, 227, 238),
            (250, 211, 228),
            (250, 211, 228),
            (250, 211, 228),
            (252, 227, 238),
            (253, 240, 246),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (254, 244, 248),
            (253, 238, 244),
            (252, 227, 238),
            (252, 227, 238),
            (252, 227, 238),
            (253, 238, 244),
            (254, 244, 248),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (254, 250, 252),
            (254, 244, 248),
            (253, 240, 246),
            (253, 240, 246),
            (253, 240, 246),
            (254, 244, 248),
            (254, 250, 252),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
            (255, 255, 255),
        ],
    }
    f_cascade = lab.filter_cascade([color_edges, color_inverted, color_blur_5])
    assert callable(f_cascade), "filter_cascade should return a function."
    result_image = f_cascade(color_image)
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


@pytest.mark.parametrize("cascade", [0, 1, 2])
@pytest.mark.parametrize("image", ["tree", "stronger"])
def test_cascades_greyscale(cascade, image):
    cascade0 = [
        lab.make_sharpen_filter(5),
        lab.edges,
    ]
    cascade1 = [
        lab.make_blur_filter(5),
        lab.edges,
        lab.make_sharpen_filter(3),
        lambda im: {
            k: ([int((i + 128) / 2) for i in v] if isinstance(v, list) else v)
            for k, v in im.items()
        },
    ]
    cascade2 = [lab.edges] * 3 + [lab.inverted]

    cascades = [cascade0, cascade1, cascade2]
    f_cascade = lab.filter_cascade(cascades[cascade])
    assert callable(f_cascade), "filter_cascade should return a function."

    fname = os.path.join(TEST_DIRECTORY, "test_images", f"{image}.png")
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{image}_grey_cascade{cascade}.png"
    )
    image = lab.load_image(fname)
    hash_ = object_hash(image)
    result_image = f_cascade(image)
    exp_image = lab.load_image(exp_fname)
    compare_images(result_image, exp_image)
    assert object_hash(image) == hash_, "Be careful not to modify the original image!"


@pytest.mark.parametrize("cascade", [0, 1, 2])
@pytest.mark.parametrize("image", ["tree", "stronger"])
def test_cascades(cascade, image):
    color_edges = lab.color_filter_from_greyscale_filter(lab.edges)
    color_inverted = lab.color_filter_from_greyscale_filter(lab.inverted)
    cascade0 = [
        color_edges,
        lab.color_filter_from_greyscale_filter(lab.make_sharpen_filter(3)),
    ]
    cascade1 = [
        lab.color_filter_from_greyscale_filter(lab.make_blur_filter(5)),
        color_edges,
        lab.color_filter_from_greyscale_filter(lab.make_sharpen_filter(3)),
        lambda im: {
            k: ([(i[1], i[0], i[2]) for i in v] if isinstance(v, list) else v)
            for k, v in im.items()
        },
    ]
    cascade2 = [color_edges] * 5 + [color_inverted]

    cascades = [cascade0, cascade1, cascade2]
    f_cascade = lab.filter_cascade(cascades[cascade])
    assert callable(f_cascade), "filter_cascade should return a function."

    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{image}.png")
    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{image}_cascade{cascade}.png"
    )
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)
    result_image = f_cascade(color_image)
    exp_image = lab.load_image(exp_fname, mode="color")
    compare_images(result_image, exp_image)
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )


def seams_endtoend(inp_name, out_name, number):
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", inp_name)
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)

    for i in range(1, number):
        result_image = lab.seam_carving(color_image, i)
        exp_fname = os.path.join(
            TEST_DIRECTORY, "test_results", out_name, f"{i:02d}.png"
        )
        compare_images(result_image, lab.load_image(exp_fname, mode="color"))
        assert object_hash(color_image) == color_hash, (
            "Be careful not to modify the original image!"
        )


def seams_one(images):
    for i in images:
        color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{i}.png")
        color_image = lab.load_image(color_fname, mode="color")
        color_hash = object_hash(color_image)

        result_image = lab.seam_carving(color_image, 1)
        exp_fname = os.path.join(TEST_DIRECTORY, "test_results", f"{i}_1seam.png")
        compare_images(result_image, lab.load_image(exp_fname, mode="color"))
        assert object_hash(color_image) == color_hash, (
            "Be careful not to modify the original image!"
        )


def test_seamcarving_images_1():
    seams_one(("pattern", "smallfrog"))


def test_seamcarving_images_2():
    seams_one(("bluegill", "tree", "twocats"))


def test_seamcarving_centeredpixel():
    seams_endtoend("centered_pixel.png", "seams_centered_pixel", 11)


def test_seamcarving_pattern():
    seams_endtoend("pattern.png", "seams_pattern", 9)


def test_seamcarving_smallfrog():
    seams_endtoend("smallfrog.png", "seams_smallfrog", 31)


def test_seamcarving_mushroom():
    seams_endtoend("smallmushroom.png", "seams_mushroom", 47)


def test_presence_of_custom_feature():
    assert hasattr(lab, "custom_feature"), "Custom feature code is not present!"
    assert callable(lab.custom_feature), "custom_feature should be a function"
