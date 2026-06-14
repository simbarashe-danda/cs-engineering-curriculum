"""
6.101 Lab:
Bacon Number
"""

import pickle

def transform_data(raw_path):
    """
    Build actor-actor graph and precompute Bacon numbers.
    """
    act_mov, mov_act, graph = {}, {}, {}

    # Actor–movie mappings
    for a1, a2, mov in raw_path:
        mov_act.setdefault(mov, set()).update({a1, a2})
        act_mov.setdefault(a1, set()).add(mov)
        act_mov.setdefault(a2, set()).add(mov)

    # Co-star adjacency
    for act, movies in act_mov.items():
        stars = set()
        for mov in movies:
            stars.update(mov_act[mov])
        stars.discard(act)
        graph[act] = stars

    # BFS from Kevin Bacon (ID 4724)
    bacon_id, score = 4724, 0
    dists, parents, depths = {}, {}, {}
    curr_layer, visited = set(), set()

    if bacon_id in graph:
        curr_layer = {bacon_id}
        depths[score] = {bacon_id}
        visited = {bacon_id}
        parents = {bacon_id: None}

    while curr_layer:
        score += 1
        next_layer = set()
        for curr_act in curr_layer:
            for nxt in graph[curr_act]:
                if nxt in visited:
                    continue
                parents[nxt] = curr_act
                dists[nxt] = score
                visited.add(nxt)
                next_layer.add(nxt)
        depths.setdefault(score, set()).update(next_layer)
        curr_layer = next_layer

    return {
        "actors_to_actors": graph,
        "actors_to_movies": act_mov,
        "movies_to_actors": mov_act,
        "bacon_nums_to_actors": depths,
        "bacon_distance": dists,
        "bacon_parent": parents,
    }


def bfs_parents(graph, src, goal_fn=None):
    """
    BFS returning parent map. With goal_fn, returns (parents, found_node) early.
    """
    curr_layer, visited = set(), set()
    parents = {}

    if type(src) != set:
        if src not in graph:
            return {}
        parents = {src: None}
        if goal_fn and goal_fn(src):
            return parents, src
        curr_layer.add(src)
        visited.add(src)
    else:
        parents = {node: None for node in src if node in graph}
        if not parents:
            return (None, None) if goal_fn else {}
        for node in parents:
            if goal_fn and goal_fn(node):
                return parents, node
        curr_layer = set(parents.keys())
        visited = set(parents.keys())

    while curr_layer:
        next_layer = set()
        for cur in curr_layer:
            for nxt in graph[cur]:
                if nxt in visited:
                    continue
                parents[nxt] = cur
                if goal_fn and goal_fn(nxt):
                    return parents, nxt
                visited.add(nxt)
                next_layer.add(nxt)
        curr_layer = next_layer

    return (None, None) if goal_fn else parents


def path_from_parents(parents, target):
    """
    Reconstruct path from target to root using parent pointers.
    """
    if target not in parents:
        return None
    path = [target]
    while parents[target]:
        target = parents[target]
        path.append(target)
    return path[::-1]


def acted_together(data, actor_id_1, actor_id_2):
    """Return True if the two actors co-starred."""
    return actor_id_2 in data["actors_to_actors"].get(actor_id_1, set())


def actors_with_bacon_number(data, num):
    """Return the set of actors with Bacon number `num`."""
    return data["bacon_nums_to_actors"].get(num, set())


def bacon_path(data, actor_id):
    """Return shortest path from Kevin Bacon to `actor_id`."""
    return path_from_parents(data["bacon_parent"], actor_id)


def actor_to_actor_path(data, actor_id_1, actor_id_2):
    """Return shortest path between two actors."""
    parents = bfs_parents(data["actors_to_actors"], actor_id_1)
    print(parents)
    return path_from_parents(parents, actor_id_2)


def actor_path(data, actor_id_1, goal_test_function):
    """Return shortest path from `actor_id_1` to any actor satisfying goal."""
    parents, target = bfs_parents(data["actors_to_actors"], actor_id_1,
                                  goal_fn=goal_test_function)
    return path_from_parents(parents, target) if parents else None


def actors_connecting_films(data, film1, film2):
    """Return shortest actor path connecting two films."""
    graph = data["actors_to_actors"]
    mov_dict = data["movies_to_actors"]
    src_set = mov_dict.get(film1, set())
    tgt_set = mov_dict.get(film2, set())

    if not (src_set and tgt_set):
        return None

    overlap = src_set & tgt_set
    if overlap:
        return [next(iter(overlap))]

    goal = lambda a, ts=tgt_set: a in ts
    parents, target = bfs_parents(graph, src_set, goal_fn=goal)
    return path_from_parents(parents, target) if parents else None

def movie_id_to_name(path):
    """Load {movie_id: movie_name} mapping from pickle file."""
    with open(path, "rb") as f:
        name_to_id = pickle.load(f)            # {name: id}
    return {id: name for name, id in name_to_id.items()}


def movie_name_path(data, id_to_name, actor_id1, actor_id2):
    """Return shortest sequence of movie names connecting two actors."""
    # Shortest actor chain (early exit when target found)
    actr_path = actor_path(data, actor_id1,
                           goal_test_function=lambda a: a == actor_id2)
    if not actr_path:
        return None
    if len(actr_path) == 1:                    # same actor, no movies
        return []

    act_mov = data["actors_to_movies"]
    movie_path = []

    # For each consecutive actor pair, pick a common film
    for a1, a2 in zip(actr_path, actr_path[1:]):
        shared = next(iter(act_mov[a1] & act_mov[a2]))  # guaranteed non‑empty
        movie_path.append(id_to_name[shared])

    return movie_path

# example
MoviePath = ("resources/movies.pickle")
ActorPath = "resources/large.pickle"
if __name__ == "__main__":
    with open(ActorPath, "rb") as f:
        largedb = pickle.load(f)    # list[tuple(int,int,int)]
        data = transform_data(largedb)

    d1 = movie_id_to_name(MoviePath) # dict(id->name)
