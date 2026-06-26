"""
6.101 Lab:
Snekoban Game
"""

DIRECTION_VECTOR = {
    "up": (-1, 0),
    "down": (+1, 0),
    "left": (0, -1),
    "right": (0, +1),
}

# Indices into the game tuple (returned by make_new_game)
IDX_USER, IDX_COMP, IDX_WALL, IDX_TGT, IDX_HT, IDX_WT = 0, 1, 2, 3, 4, 5

def make_new_game(level_description):
    """
    Parse a level description into an internal tuple representation.
    """
    desc = level_description
    WALL, COMP, TGT, USER, HT, WT = (
        "wall", "computer", "target", "player", "height", "width",
    )

    # Collect objects
    parts = {
        USER: [], COMP: [], WALL: [],
        TGT: [], HT: len(desc), WT: len(desc[0]),
    }

    for r, row in enumerate(desc):
        for c, elem in enumerate(row):
            coord = (r, c)
            if len(elem) == 1:
                parts[elem[0].lower()].append(coord)
            elif len(elem) == 2:               # target + (player or computer)
                parts[TGT].append(coord)
                val = USER if USER in elem else COMP
                parts[val].append(coord)

    parts[USER], parts[WALL], parts[COMP], parts[TGT] = (
        parts[USER][0],                          # single player location
        frozenset(parts[WALL]),
        frozenset(parts[COMP]),
        frozenset(parts[TGT]),
    )

    return tuple(parts.values())

def victory_check(game):
    """
    Return True iff every computer is on a target.
    Unwinnable (False) if no computers or no targets.
    """
    return game[IDX_COMP] and game[IDX_TGT] and game[IDX_COMP].issubset(game[IDX_TGT])

def step_game(game, direction):
    """
    Return the game state after moving the player in `direction`.
    Does not mutate the input.
    """
    dr, dc = DIRECTION_VECTOR[direction]
    pr, pc = game[IDX_USER]
    new_p = (pr + dr, pc + dc)

    r, c = new_p
    # Bounds / wall checks
    if r < 0 or r >= game[IDX_HT] or c < 0 or c >= game[IDX_WT]:
        return game
    if new_p in game[IDX_WALL]:
        return game

    # Simple move (no computer in the way)
    if new_p not in game[IDX_COMP]:
        return (
            new_p, game[IDX_COMP], game[IDX_WALL],
            game[IDX_TGT], game[IDX_HT], game[IDX_WT],
        )

    # Push a computer
    new_c = (pr + 2 * dr, pc + 2 * dc)
    r, c = new_c
    if r < 0 or r >= game[IDX_HT] or c < 0 or c >= game[IDX_WT]:
        return game
    if new_c in game[IDX_WALL] or new_c in game[IDX_COMP]:
        return game

    new_comps = (game[IDX_COMP] - {new_p}) | {new_c}
    return (
        new_p, new_comps, game[IDX_WALL],
        game[IDX_TGT], game[IDX_HT], game[IDX_WT],
    )

def dump_game(game):
    """
    Convert the internal tuple back to a level description
    (list of lists of lists of strings).
    """
    WALL, COMP, TGT, USER = "wall", "computer", "target", "player"
    user, comps, walls, tgts, ht, wt = game

    return [
        [
            (
                [TGT, USER] if (r, c) == user and (r, c) in tgts else
                [TGT, COMP] if (r, c) in comps and (r, c) in tgts else
                [TGT, WALL] if (r, c) in walls and (r, c) in tgts else
                [TGT]       if (r, c) in tgts else
                [USER]      if (r, c) == user else
                [COMP]      if (r, c) in comps else
                [WALL]      if (r, c) in walls else
                []
            )
            for c in range(wt)
        ]
        for r in range(ht)
    ]

def solve_puzzle(game):
    """
    Return a shortest list of moves ('up','down','left','right') that
    reaches the victory condition, or None if unsolvable.
    """
    user, comps, walls, tgts, ht, wt = game

    queue = [(user, comps)]          # BFS queue: dynamic states
    head = 0                         # read pointer 
    visited = {(user, comps)}        # seen dynamic states
    parents = {(user, comps): None}  # parent pointer + direction

    def step_dynamic(full_state, dir):
        """Return new (player, computers) if move is valid, else None."""
        new = step_game(full_state, dir)
        return None if new == full_state else (new[IDX_USER], new[IDX_COMP])

    def reconstruct_path(par, target):
        """Backtrack from target to start using parent pointers."""
        if par[target] is None:      # already at start
            return []
        state, move = par[target]
        path = [move]
        while par[state] is not None:
            state, move = par[state]
            path.append(move)
        return path[::-1]

    while head < len(queue):
        p, c = queue[head]
        head += 1
        full = (p, c, walls, tgts, ht, wt)

        if victory_check(full):
            return reconstruct_path(parents, (p, c))

        for dir in DIRECTION_VECTOR:
            nxt = step_dynamic(full, dir)
            if nxt is None or nxt in visited:
                continue
            visited.add(nxt)
            parents[nxt] = ((p, c), dir)
            queue.append(nxt)

    return None

# example of using the solver
import pprint
if __name__ == "__main__":
    desc = [    # game description
    [[], [], ["wall"], ["wall"], ["wall"], ["wall"], ["wall"], [], [], []],
    [[], ["wall"], ["wall"], [], [], [], ["wall"], [], [], []],
    [[], ["wall"], [], [], ["wall"], [], ["wall"], [], [], []],
    [["wall"], ["wall"], [], [], [], [], ["wall"], [], [], []],
    [["wall"], [], [], ["computer"], [], ["wall"], ["wall"], ["wall"], ["wall"], []],
    [["wall"], [], [], ["computer"], ["computer"], ["wall"], ["target"], [], ["wall"], []],
    [["wall"], ["wall"], ["wall"], ["computer"], [], [], [], [], ["wall"], []],
    [[], [], ["wall"], [], [], ["wall"], [], [], ["wall"], []],
    [[], [], ["wall"], ["wall"], ["wall"], ["wall"], ["target"], [], ["wall"], []],
    [[], [], [], ["wall"], ["player"], ["wall"], ["target"], [], ["wall"], ["wall"]],
    [[], [], [], ["wall"], [], [], ["target"], [], [], ["wall"]],
    [[], [], [], ["wall"], [], [], [], [], [], ["wall"]],
    [[], [], [], ["wall"], ["wall"], ["wall"], ["wall"], ["wall"], ["wall"], ["wall"]]
    ]
    game = make_new_game(desc)
    path = solve_puzzle(game)
    pprint.pprint(path)