from collections import deque

def dfs(v, parent, depth):
    max_depth = depth
    for u in graph[v]:
        if u != parent:
            max_depth = max(max_depth, dfs(u, v, depth + 1))
    max_depths[v] = max_depth
    return max_depth