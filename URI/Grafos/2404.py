# -*- coding: utf-8 -*-
# https://www.urionlinejudge.com.br/judge/pt/problems/view/2404
# Reduzindo Detalhes em um Mapa

qtd_cidades, qtd_rodovias = map(int, input().split())
rodovias = []

for i in range(qtd_rodovias):
    cidade1, cidade2, comprimento = map(int, input().split())
    rodovias.append((comprimento, cidade1, cidade2))

rodovias.sort()

rank = [1 for _ in range(qtd_cidades+1)]
components = [i for i in range(qtd_cidades+1)]


def parent(node: int):
    if (components[node] == node):
        return node
    components[node] = parent(components[node])
    return components[node]


def kruskal(nodes):
    tamanho_total = 0
    for node in nodes:
        tamanho, de, para = node

        if parent(de) != parent(para):
            tamanho_total += tamanho

            # escolhe o lado com mais nos para ser o mestre
            if rank[parent(de)] < rank[parent(para)]:
                de, para = para, de

            rank[parent(de)] += rank[para]
            rank[parent(para)] = 0
            components[parent(para)] = parent(de)

    return tamanho_total


print(kruskal(rodovias))
