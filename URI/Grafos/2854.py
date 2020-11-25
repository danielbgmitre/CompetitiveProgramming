# -*- coding: utf-8 -*-

M, N = map(int, input().split())
graph = {}
visited = {}

for _ in range(N):
    name1, _, name2 = input().split()
    try:
        graph[name1].append(name2)
    except KeyError:
        graph[name1] = [name2]

    if not name2 in graph:
        graph[name2] = []

    visited[name1] = False
    visited[name2] = False


def toposort(graph: dict, visited: dict, curr=None, order=[]) -> list:
    if curr == None:
        for name in graph.keys():
            if not visited[name]:
                toposort(graph, visited, name, order)
        return order

    visited[curr] = True
    for adj in graph[curr]:
        if not visited[adj]:
            toposort(graph, visited, adj, order)
    order.append(curr)

    return order


def dfs(graph, visited, curr):
    if visited[curr]:
        return

    visited[curr] = True
    for adj in graph[curr]:
        dfs(graph, visited, adj)


def disjoint(graph, visited, order) -> int:
    res = 0
    for name in order:
        if not visited[name]:
            res += 1
        dfs(graph, visited, name)
    return res


toposorted = toposort(graph, visited.copy())
for name in toposorted:
    for adj in graph[name]:
        graph[adj].append(name)

print(disjoint(graph, visited.copy(), reversed(toposorted)))
