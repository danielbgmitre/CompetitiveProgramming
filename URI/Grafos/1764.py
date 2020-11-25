# -*- coding: utf-8 -*-
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1764
# Itinerário do Papai Noel

from collections import namedtuple

MAXN = 200200

graph = [[] for _ in range(MAXN)]
par = [i for i in range(MAXN)]
rank = [1 for _ in range(MAXN)]

Node = namedtuple('Node', ('start', 'end', 'weight'))


def parent(a) -> int:
    if par[a] == a:
        return a
    par[a] = parent(par[a])
    return par[a]


def join(a: int, b: int):
    if rank[parent(a)] > rank[parent(b)]:
        a, b = b, a
    rank[parent(b)] += rank[parent(a)]
    rank[parent(a)] = 0
    par[parent(a)] = parent(b)


def weight(node: Node):
    return node.weight


def extract_nodes(num_nodes: int) -> list:
    nodes = []
    for i in range(num_nodes):
        for adj in graph[i]:
            nodes.append(adj)
    nodes.sort(key=weight)
    return nodes


def kruskal(num_nodes: int) -> int:
    nodes = extract_nodes(num_nodes)
    # print(nodes)
    res = 0
    for node in nodes:
        if parent(node.start) != parent(node.end):
            join(node.start, node.end)
            res += node.weight
    return res


while 1:
    m, n = map(int, input().split())
    if n == 0:
        break

    for i in range(m + 1):
        graph[i].clear()
        rank[i] = 1
        par[i] = i

    for _ in range(n):
        x, y, z = map(int, input().split())
        graph[x].append(Node(x, y, z))

    print(kruskal(m))
