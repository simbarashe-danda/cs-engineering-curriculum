# -*- coding: utf-8 -*-
"""
6.101 Lab: Autocomplete
"""

import doctest
from text_tokenize import tokenize_sentences


VAL = "value"
CHIL = "children"
_TYPE_ERR_MSG = "type(key) must be 'str'"
_VAL_ERR_MSG = "no value exists"


def _validate_key(key):
    """Raise TypeError if key is not a string."""
    if not isinstance(key, str):
        raise TypeError(_TYPE_ERR_MSG)


def _search(node, key):
    """
    Traverse the trie following `key`.  Return the value associated with
    the key if it exists, otherwise return None.
    """
    _validate_key(key)

    def _recur(nd, k):
        if not k:                      # base case: reached end of key
            return nd.get(VAL)          # returns None if no value
        child = nd[CHIL].get(k[0])
        if child is None:
            return None
        return _recur(child, k[1:])

    return _recur(node, key)


def trie_contains(trie, key):
    """Return True if `key` exists in `trie`, False otherwise."""
    return _search(trie, key) is not None


def trie_get(trie, key):
    """
    Return the value associated with `key` in `trie`.
    Raise ValueError if `key` is not present.
    """
    val = _search(trie, key)
    if val is None:                    # None -> "not found"
        raise ValueError(_VAL_ERR_MSG)
    return val


def trie_items(trie):
    """
    Return a list of all (key, value) pairs in `trie` (order arbitrary).
    """
    result = []

    def _collect(prefix, node):
        if VAL in node:
            result.append((prefix, node[VAL]))
        for ch, child in node[CHIL].items():
            _collect(prefix + ch, child)

    _collect("", trie)
    return result


def trie_new():
    """Return a new, empty trie."""
    return {CHIL: {}}


def trie_set(trie, key, value):
    """
    Mutate `trie` so that `key` is associated with `value`.
    Raise TypeError if `key` is not a string.
    """
    _validate_key(key)

    def _insert(node, k):
        if not k:
            node[VAL] = value
            return
        prefix = k[0]
        child = node[CHIL]
        if prefix not in child:
            child[prefix] = trie_new()
        _insert(child[prefix], k[1:])

    _insert(trie, key)


def trie_from_dict(mapping):
    """
    Build a new trie from a dictionary of string keys to values.
    """
    t = trie_new()
    for k, v in mapping.items():
        trie_set(t, k, v)
    return t


def trie_delete(trie, key):
    """
    Remove `key` from `trie`.  Raise ValueError if `key` does not exist,
    or TypeError if `key` is not a string.
    """
    _validate_key(key)

    def _delete(node, k):
        if not k:
            if VAL in node:
                del node[VAL]
            else:
                raise ValueError(_VAL_ERR_MSG)
            return

        child = node[CHIL]
        prefix = k[0]
        if prefix not in child:
            raise ValueError(_VAL_ERR_MSG)
        _delete(child[prefix], k[1:])

    _delete(trie, key)


def word_frequencies(text):
    """
    Build a trie where keys are words in `text` and values are their
    occurrence counts.
    """
    sentences = tokenize_sentences(text)
    freq = {}
    for sent in sentences:
        for word in sent.split():
            freq[word] = freq.get(word, 0) + 1
    return trie_from_dict(freq)


def autocomplete(trie, prefix, max_count=None):
    """
    Return a set of the most-frequent words that start with `prefix`.
    If `max_count` is given, include only the top `max_count` results.
    """
    # Navigate to the subtrie rooted at the end of the prefix
    def _descend(node, pref):
        if not pref:
            return node
        ch = pref[0]
        child = node[CHIL].get(ch)
        if child is None:
            return trie_new()
        return _descend(child, pref[1:])

    sub = _descend(trie, prefix)
    completions = trie_items(sub)

    if not completions:
        return set()

    # Convert (suffix, value) pairs into (full_word, value)
    pairs = [(prefix + suf, val) for suf, val in completions]

    if max_count is None:
        return {word for word, _ in pairs}

    pairs.sort(key=lambda x: x[1], reverse=True)
    top = pairs[:max_count]
    return {word for word, _ in top}


def word_filter(trie, pattern):
    """
    Return the set of all words in `trie` that match `pattern`.
    Pattern syntax:
        *  – any sequence of characters (including empty)
        ?  – any single character
    """
    matches = set()

    def _match(node, pat, word):
        if not pat:                    # whole pattern consumed
            if VAL in node:
                matches.add(word)
            return

        cur, rest = pat[0], pat[1:]
        children = node[CHIL]

        # literal character
        if cur not in ("*", "?"):
            if cur in children:
                _match(children[cur], rest, word + cur)
            return

        # '?' matches exactly one existing character
        if cur == "?":
            for ch, child in children.items():
                _match(child, rest, word + ch)
            return

        # '*' matches zero or more characters
        if cur == "*":
            # zero characters
            _match(node, rest, word)
            # one or more: consume a character, keep the '*'
            for ch, child in children.items():
                _match(child, pat, word + ch)

    _match(trie, pattern, "")
    return matches


if __name__ == "__main__":
    doctest.testmod()