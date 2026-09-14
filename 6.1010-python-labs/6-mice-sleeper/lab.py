#!/usr/bin/env python3
"""
6.101 Lab:
Mice-sleeper

Game state is a dictionary with the following keys:
    'board'                : nested list of ints and 'm' (mice)
    'dimensions'           : tuple of board dimensions
    'state'                : 'ongoing' | 'won' | 'lost'
    'visible'              : nested list of booleans (revealed cells)
    'num_mice'             : total mice to place on first reveal
    'revealed_cells_count' : number of cells revealed so far
    'total_cells'          : product of dimensions
    'visible_coordinates'  : set of revealed coordinate tuples
"""



def dump(game, all_keys=False):
    """
    Prints a human-readable version of a game (provided as a dictionary)

    By default uses only "board", "dimensions", "state", "visible" keys (used
    by doctests). Setting all_keys=True shows all game keys.
    """
    if all_keys:
        keys = sorted(game)
    else:
        keys = ("board", "dimensions", "state", "visible")
        # Use only default game keys. If you modify this you will need
        # to update the docstrings in other functions!

    for key in keys:
        val = game[key]
        if isinstance(val, list) and val and isinstance(val[0], list):
            print(f"{key}:")
            for inner in val:
                print(f"    {inner}")
        else:
            print(f"{key}:", val)

# 2-D IMPLEMENTATION

BRD = "board"
DIMEN = "dimensions"
ST = "state"
VS = "visible"
MOUSE = "m"
REV_CNT = "revealed_cells_count"
NUM_MC = "num_mice"
VS_COORDS = "visible_coordinates"
TTC = "total_cells"
LST = "lost"
WON = "won"
ONG = "ongoing"


def get_adj(r, c, game):
    """Return the set of in-bounds coordinates adjacent to (r, c)."""
    rows, cols = game[DIMEN]
    return {
        (x, y)
        for (x, y) in (
            (r + 1, c), (r + 1, c + 1), (r + 1, c - 1),
            (r - 1, c), (r - 1, c + 1), (r - 1, c - 1),
            (r, c + 1), (r, c - 1),
        )
        if 0 <= x < rows and 0 <= y < cols
    }


def new_game_2d(nrows, ncolumns, num_mice):
    """
    Create a new 2D game.

    Parameters:
        nrows (int)     : number of rows
        ncolumns (int)  : number of columns
        num_mice (int)  : number of mice to place on first reveal

    Returns:
        A fresh game state dictionary.
    """
    return {
        BRD: [[0] * ncolumns for _ in range(nrows)],
        DIMEN: (nrows, ncolumns),
        ST: ONG,
        VS: [[False] * ncolumns for _ in range(nrows)],
        NUM_MC: num_mice,
        REV_CNT: 0,
        TTC: nrows * ncolumns,
        VS_COORDS: set(),
    }


def place_mice_2d(game, num_mice, disallowed):
    """
    Randomly place `num_mice` mice, avoiding cells in `disallowed`, and
    increment the counts of all non-mouse neighbors.  Mutates `game`.
    """
    rand_coords = random_coordinates(game[DIMEN])
    placed = set()

    def _update_neighbors(r, c):
        """Increment counts of non-mouse neighbors of (r, c)."""
        for nr, nc in get_adj(r, c, game):
            if game[BRD][nr][nc] != MOUSE:
                game[BRD][nr][nc] += 1

    for r, c in rand_coords:
        if len(placed) == num_mice:
            return
        coord = (r, c)
        if coord not in placed and coord not in disallowed:
            game[BRD][r][c] = MOUSE
            placed.add(coord)
            _update_neighbors(r, c)


def reveal_2d(game, row, col):
    """
    Reveal the cell at (row, col), flood-filling from zero-valued cells.

    On the first reveal, mice are placed avoiding the clicked cell and its
    neighbors.

    Returns:
        int: number of newly revealed cells.
    """
    if game[ST] != ONG or game[VS][row][col]:
        return 0

    # First reveal: place mice away from the clicked cell and its neighbors.
    if game[REV_CNT] == 0:
        disallowed = get_adj(row, col, game)
        disallowed.add((row, col))
        place_mice_2d(game, game[NUM_MC], disallowed)

    def _reveal(r, c):
        if game[VS][r][c]:
            return 0

        game[VS][r][c] = True
        game[VS_COORDS].add((r, c))
        count = 1

        # Flood fill only through cells with zero adjacent mice.
        if game[BRD][r][c] == 0:
            for nr, nc in get_adj(r, c, game):
                count += _reveal(nr, nc)
        return count

    revealed_count = _reveal(row, col)
    game[REV_CNT] += revealed_count

    # Update the game state based on the outcome of this reveal.
    if game[BRD][row][col] == MOUSE:
        game[ST] = LST
    elif game[REV_CNT] + game[NUM_MC] == game[TTC] and game[ST] == ONG:
        game[ST] = WON

    return revealed_count


def render_2d(game, all_visible=False):
    """
    Return a 2D grid of single-character strings for display:
        '_' hidden, 'm' mouse, ' ' empty, or a digit 1-8.
    """
    hidden, empty = "_", " "

    def _render_cell(value, coord):
        if not all_visible and coord not in game[VS_COORDS]:
            return hidden
        return empty if value == 0 else str(value)

    return [
        [_render_cell(value, (r, c)) for c, value in enumerate(row)]
        for r, row in enumerate(game[BRD])
    ]


# N-D IMPLEMENTATION

def new_game_nd(dimensions, num_mice):
    """
    Create a new N-dimensional game.

    Parameters:
        dimensions (tuple) : sizes of each dimension
        num_mice (int)     : number of mice to place on first reveal

    Returns:
        A fresh game state dictionary.
    """
    def _recur_board(idx, val=0):
        """Recursively build a nested-list board filled with `val`."""
        return (
            [val] * dimensions[idx] if idx == len(dimensions) - 1
            else [_recur_board(idx + 1, val) for _ in range(dimensions[idx])]
        )

    total_cells = 1
    for size in dimensions:
        total_cells *= size

    return {
        BRD: _recur_board(0),
        DIMEN: dimensions,
        ST: ONG,
        VS: _recur_board(0, False),
        TTC: total_cells,
        NUM_MC: num_mice,
        REV_CNT: 0,
        VS_COORDS: set(),
    }


def neighbors(coord, dim):
    """Yield all in-bounds neighbor coordinates of `coord` in `dim`."""
    def _gen_offsets(offset, depth):
        """Generate every offset of -1/0/+1 per axis, excluding all zeros."""
        if depth == len(dim):
            if any(offset):
                yield offset
            return
        yield from _gen_offsets(offset + (-1,), depth + 1)
        yield from _gen_offsets(offset + (0,), depth + 1)
        yield from _gen_offsets(offset + (1,), depth + 1)

    for offset in _gen_offsets((), 0):
        candidate = tuple(coord[i] + offset[i] for i in range(len(coord)))
        if all(0 <= candidate[i] < dim[i] for i in range(len(dim))):
            yield candidate


def get_val(board, coord, depth):
    """Return the value at `coord` in a nested list, recursively indexed."""
    if depth == len(coord) - 1:
        return board[coord[depth]]
    return get_val(board[coord[depth]], coord, depth + 1)


def place_mice_nd(game, num_mice, disallowed):
    """
    Randomly place `num_mice` mice in an N-D board, avoiding `disallowed`,
    and increment the counts of all non-mouse neighbors.  Mutates `game`.
    """
    def _set_val(path, value=1):
        """Set the cell at `path` to `value`; if value==1, increment instead."""
        def _recur_set(board, depth):
            index = path[depth]
            if depth == len(path) - 1:
                board[index] = (
                    value + board[index]
                    if value == 1 and board[index] != MOUSE
                    else MOUSE
                )
                return
            _recur_set(board[index], depth + 1)

        _recur_set(game[BRD], 0)

    def _incr_neighbors(coord):
        """Increment counts of non-mouse neighbors of `coord`."""
        for neighbor in neighbors(coord, game[DIMEN]):
            _set_val(neighbor)

    placed = set()

    for coord in random_coordinates(game[DIMEN]):
        if len(placed) == num_mice:
            break
        if coord not in placed and coord not in disallowed:
            _set_val(coord, value=MOUSE)
            placed.add(coord)
            _incr_neighbors(coord)


def reveal_nd(game, coordinates):
    """
    Reveal `coordinates` in an N-D board, flood-filling from zero cells.

    On the first reveal, mice are placed avoiding the clicked cell and its
    neighbors.

    Returns:
        int: number of newly revealed cells.
    """
    if game[ST] != ONG or get_val(game[VS], coordinates, 0):
        return 0

    # First reveal: place mice away from the clicked cell and its neighbors.
    if game[REV_CNT] == 0:
        disallowed = set(neighbors(coordinates, game[DIMEN]))
        disallowed.add(coordinates)
        place_mice_nd(game, game[NUM_MC], disallowed)

    def _set_true(board, coord, depth):
        """Recursively set the visible flag to True at `coord`."""
        if depth == len(coord) - 1:
            board[coord[depth]] = True
            return
        _set_true(board[coord[depth]], coord, depth + 1)

    def _reveal(coord):
        """Recursively reveal `coord`, flood-filling through zero cells."""
        if get_val(game[VS], coord, 0):
            return 0

        _set_true(game[VS], coord, 0)
        game[VS_COORDS].add(coord)
        count = 1

        if get_val(game[BRD], coord, 0) == 0:
            for neighbor in neighbors(coord, game[DIMEN]):
                count += _reveal(neighbor)
        return count

    revealed_count = _reveal(coordinates)
    game[REV_CNT] += revealed_count

    # Update the game state based on the outcome of this reveal.
    if get_val(game[BRD], coordinates, 0) == MOUSE:
        game[ST] = LST
    elif game[REV_CNT] + game[NUM_MC] == game[TTC] and game[ST] == ONG:
        game[ST] = WON

    return revealed_count


def render_nd(game, all_visible=False):
    """
    Return an N-dimensional grid of single-character strings for display:
        '_' hidden, 'm' mouse, ' ' empty, or a digit 1-8.
    """
    hidden, empty = "_", " "
    dim = game[DIMEN]
    visible_coords = game[VS_COORDS]

    def _render_cell(coord):
        """Return the display string for the cell at `coord`."""
        value = get_val(game[BRD], coord, 0)
        if not (all_visible or coord in visible_coords):
            return hidden
        return empty if value == 0 else str(value)

    def _recur_grid(depth, prefix):
        """Recursively build the nested-list display grid."""
        return [
            _render_cell(prefix + (i,)) if depth == len(dim) - 1
            else _recur_grid(depth + 1, prefix + (i,))
            for i in range(dim[depth])
        ]

    return _recur_grid(0, ())


def random_coordinates(dimensions):
    """
    Given a tuple representing the dimensions of a game board, return an
    infinite generator that yields pseudo-random coordinates within the board.
    For a given tuple of dimensions and seed, the output sequence will always
    be the same.
    """
    def prng(state):
        # see https://en.wikipedia.org/wiki/Lehmer_random_number_generator
        while True:
            yield (state := state * 48271 % 0x7FFFFFFF) / 0x7FFFFFFF

    prng_gen = prng(
        seed
        if (seed := getattr(random_coordinates, "seed", None)) is not None
        else (sum(dimensions) + 61016101)
    )
    while True:
        yield tuple(int(dim * val) for val, dim in zip(prng_gen, dimensions))


if __name__ == "__main__":
    pass