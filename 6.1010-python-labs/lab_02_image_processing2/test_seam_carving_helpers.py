#!/usr/bin/env python3

import os
import sys
import pickle

import pytest

TEST_DIRECTORY = os.path.dirname(__file__)
sys.path.insert(0, TEST_DIRECTORY)

from test import object_hash, compare_images, lab


def test_pattern_greyscale():
    input_fname = os.path.join(TEST_DIRECTORY, "test_images", "pattern.png")
    color_image = lab.load_image(input_fname, mode="color")
    color_hash = object_hash(color_image)
    grey_image = lab.greyscale_image_from_color_image(color_image)
    exp_image = {
        "mode": "greyscale",
        "height": 4,
        "width": 9,
        "pixels": [
            200,
            160,
            160,
            160,
            153,
            160,
            160,
            160,
            200,
            200,
            160,
            160,
            160,
            153,
            160,
            160,
            160,
            200,
            0,
            153,
            160,
            160,
            160,
            160,
            160,
            153,
            0,
            0,
            153,
            153,
            160,
            160,
            160,
            153,
            153,
            0,
        ],
    }
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )
    compare_images(grey_image, exp_image)


@pytest.mark.parametrize(
    "fname", ("centered_pixel", "smallfrog", "bluegill", "twocats", "tree")
)
def test_greyscale(fname):
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)

    grey_image = lab.greyscale_image_from_color_image(color_image)
    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", f"{fname}_grey.png")
    assert object_hash(color_image) == color_hash, (
        "Be careful not to modify the original image!"
    )
    compare_images(grey_image, lab.load_image(exp_fname))


def test_pattern_energy():
    grey_image = {
        "mode": "greyscale",
        "height": 4,
        "width": 9,
        "pixels": [
            200,
            160,
            160,
            160,
            153,
            160,
            160,
            160,
            200,
            200,
            160,
            160,
            160,
            153,
            160,
            160,
            160,
            200,
            0,
            153,
            160,
            160,
            160,
            160,
            160,
            153,
            0,
            0,
            153,
            153,
            160,
            160,
            160,
            153,
            153,
            0,
        ],
    }
    grey_hash = object_hash(grey_image)
    energy = lab.compute_energy(grey_image)
    expected = {
        "mode": "greyscale",
        "width": 9,
        "height": 4,
        "pixels": [
            160,
            160,
            0,
            28,
            0,
            28,
            0,
            160,
            160,
            255,
            218,
            10,
            22,
            14,
            22,
            10,
            218,
            255,
            255,
            255,
            30,
            0,
            14,
            0,
            30,
            255,
            255,
            255,
            255,
            31,
            22,
            0,
            22,
            31,
            255,
            255,
        ],
    }
    compare_images(energy, expected)


@pytest.mark.parametrize(
    "fname", ["centered_pixel", "smallfrog", "bluegill", "twocats", "tree"]
)
def test_energy(fname):
    grey_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    grey_image = lab.load_image(grey_fname)
    energy = lab.compute_energy(grey_image)

    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", f"{fname}_energy.pickle")
    with open(exp_fname, "rb") as f:
        expected = pickle.load(f)

    compare_images(energy, expected)


def test_pattern_cumulative_energy():
    energy = {
        "mode": "greyscale",
        "width": 9,
        "height": 4,
        "pixels": [
            160,
            160,
            0,
            28,
            0,
            28,
            0,
            160,
            160,
            255,
            218,
            10,
            22,
            14,
            22,
            10,
            218,
            255,
            255,
            255,
            30,
            0,
            14,
            0,
            30,
            255,
            255,
            255,
            255,
            31,
            22,
            0,
            22,
            31,
            255,
            255,
        ],
    }
    cem = lab.cumulative_energy_map(energy)
    expected = {
        "mode": "greyscale",
        "width": 9,
        "height": 4,
        "pixels": [
            160,
            160,
            0,
            28,
            0,
            28,
            0,
            160,
            160,
            415,
            218,
            10,
            22,
            14,
            22,
            10,
            218,
            415,
            473,
            265,
            40,
            10,
            28,
            10,
            40,
            265,
            473,
            520,
            295,
            41,
            32,
            10,
            32,
            41,
            295,
            520,
        ],
    }
    compare_images(cem, expected)


@pytest.mark.parametrize(
    "fname", ("centered_pixel", "smallfrog", "bluegill", "twocats", "tree")
)
def test_cumulative_energy(fname):
    energy_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_energy.pickle"
    )
    with open(energy_fname, "rb") as f:
        energy = pickle.load(f)
    cem = lab.cumulative_energy_map(energy)

    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_cumulative_energy.pickle"
    )
    with open(exp_fname, "rb") as f:
        expected = pickle.load(f)

    compare_images(cem, expected)


def check_seam(cem, result, expected):
    assert len(result) == len(expected), (
        f"Expected {len(expected)} indices in seam, but got {len(result)}"
    )
    bad_res_vals = result - expected
    missing_exp_vals = expected - result
    msg = "Correct seam!"
    if missing_exp_vals:
        ind = max(missing_exp_vals)
        row, col = ind // cem["width"], ind % cem["width"]
        msg = f"Missing seam index{'es' * (len(missing_exp_vals) > 1)}!"
        msg += f"\nExpected index {ind} (row {row}, col {col}) to be present in seam."
        msg += f"\nFound {len(bad_res_vals)} unexpected seam indices in result."
        res_show = ", ".join(str(x) for x in sorted(result)[-10:])
        exp_show = ", ".join(str(x) for x in sorted(expected)[-10:])
        if res_show != exp_show:
            msg += f"\nResult included  {res_show}"
            msg += f"\nbut expected had {exp_show}"

    correct_seam = result == expected
    assert correct_seam, msg


def test_pattern_seam_indices():
    cem = {
        "mode": "greyscale",
        "width": 9,
        "height": 4,
        "pixels": [
            160,
            160,
            0,
            28,
            0,
            28,
            0,
            160,
            160,
            415,
            218,
            10,
            22,
            14,
            22,
            10,
            218,
            415,
            473,
            265,
            40,
            10,
            28,
            10,
            40,
            265,
            473,
            520,
            295,
            41,
            32,
            10,
            32,
            41,
            295,
            520,
        ],
    }
    seam = lab.minimum_energy_seam(cem)
    expected = {2, 11, 21, 31}
    check_seam(cem, seam, expected)


def test_edge_seam_indices():
    # NOTE: these are not technically valid cumulative energy maps,
    # but they are still useful small test cases
    cem1 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            10,
            20,
            10,
            5,
            12,
            20,
            20,
            5,
            11,
            12,
            10,
            5,
            20,
            11,
            12,
            20,
            20,
            5,
            11,
            12,
        ],
    }
    expected1 = {17, 11, 7, 3}  # zig-zag middle columns, no ties
    seam1 = lab.minimum_energy_seam(cem1)
    check_seam(cem1, seam1, expected1)

    cem2 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            20,
            20,
            0,
            0,
            0,
            20,
            20,
            0,
            0,
            0,
            20,
            20,
            0,
            0,
            0,
            20,
            20,
            20,
            20,
            20,
        ],
    }
    expected2 = {15, 10, 5, 0}  # leftmost column
    seam2 = lab.minimum_energy_seam(cem2)
    check_seam(cem2, seam2, expected2)

    cem3 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            0,
            0,
            0,
            20,
            10,
            0,
            0,
            0,
            20,
            10,
            0,
            0,
            0,
            20,
            10,
            20,
            20,
            20,
            20,
            10,
        ],
    }
    expected3 = {19, 14, 9, 4}  # rightmost column
    seam3 = lab.minimum_energy_seam(cem3)
    check_seam(cem3, seam3, expected3)

    cem4 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            0,
            10,
            0,
            0,
            0,
            0,
            10,
            10,
            10,
            10,
            0,
            10,
            20,
            20,
            10,
            20,
            20,
            20,
            10,
            10,
        ],
    }
    expected4 = {18, 14, 8, 2}  # zig-zag right side
    seam4 = lab.minimum_energy_seam(cem4)
    check_seam(cem4, seam4, expected4)

    cem5 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            10,
            20,
            20,
            20,
            0,
            10,
            20,
            20,
            20,
            0,
            10,
            20,
            20,
            20,
            0,
            10,
            20,
            20,
            20,
            10,
        ],
    }
    expected5 = {15, 10, 5, 0}  # leftmost column
    seam5 = lab.minimum_energy_seam(cem5)
    check_seam(cem5, seam5, expected5)

    cem6 = {
        "mode": "greyscale",
        "width": 5,
        "height": 4,
        "pixels": [
            10,
            5,
            0,
            20,
            0,
            10,
            10,
            10,
            20,
            0,
            10,
            5,
            0,
            20,
            0,
            10,
            20,
            20,
            20,
            10,
        ],
    }
    expected6 = {15, 11, 5, 1}  # zig-zag left column
    seam6 = lab.minimum_energy_seam(cem6)
    check_seam(cem6, seam6, expected6)


@pytest.mark.parametrize(
    "fname", ("centered_pixel", "smallfrog", "bluegill", "twocats", "tree")
)
def test_min_seam_indices(fname):
    cem_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_cumulative_energy.pickle"
    )
    with open(cem_fname, "rb") as f:
        cem = pickle.load(f)
    seam = lab.minimum_energy_seam(cem)

    exp_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_minimum_energy_seam.pickle"
    )
    with open(exp_fname, "rb") as f:
        expected = set(pickle.load(f))

    check_seam(cem, seam, expected)


def test_pattern_seam_removal():
    color_fname = os.path.join(TEST_DIRECTORY, "test_images", "pattern.png")
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)
    seam_indices = {2, 11, 21, 31}
    result_image = lab.image_without_seam(color_image, seam_indices)
    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", "pattern_1seam.png")
    compare_images(result_image, lab.load_image(exp_fname, mode="color"))
    assert color_hash == object_hash(color_image), "Be careful not to modify the input!"


@pytest.mark.parametrize("fname", ("pattern", "bluegill", "twocats", "tree"))
def test_seam_removal(fname):
    seam_fname = os.path.join(
        TEST_DIRECTORY, "test_results", f"{fname}_minimum_energy_seam.pickle"
    )
    with open(seam_fname, "rb") as f:
        seam = set(pickle.load(f))

    color_fname = os.path.join(TEST_DIRECTORY, "test_images", f"{fname}.png")
    color_image = lab.load_image(color_fname, mode="color")
    color_hash = object_hash(color_image)
    result_image = lab.image_without_seam(color_image, seam)

    exp_fname = os.path.join(TEST_DIRECTORY, "test_results", f"{fname}_1seam.png")
    compare_images(result_image, lab.load_image(exp_fname, mode="color"))
    assert color_hash == object_hash(color_image), "Be careful not to modify the input!"
