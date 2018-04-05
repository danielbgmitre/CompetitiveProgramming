#coding: utf-8

qtd_cidades, qtd_rodovias = map(int, raw_input().split())
rodovias = []

for i in xrange(qtd_rodovias):
    cidade1, cidade2, comprimento = map(int, raw_input().split())
    rodovias.append((comprimento, cidade1, cidade2))

rodovias.sort()

rank = [1 for _ in xrange(qtd_cidades+1)]
components = [i for i in xrange(qtd_cidades+1)]

def parent(node):
	if (components[node] == node):
		return node
	else:
		components[node] = parent(components[node])	#otimizacao
		return components[node]

def kruskal(nodes):
    tamanho_total = 0
    for node in nodes:
        tamanho, de, para = node

        if parent(de) != parent(para):
            tamanho_total += tamanho
            # print "adicionei aresta entre", de, para
            if rank[parent(de)] < rank[parent(para)]:	#escolhe o lado com mais nos para ser o mestre
                rank[parent(para)] += rank[parent(de)]
                rank[parent(de)] = 0
                components[parent(de)] = parent(para)	#conecta os componentes
            else:
                rank[parent(de)] += rank[para]
                rank[parent(para)] = 0
                components[parent(para)] = parent(de)	#conecta os componentes
        # else:
        #     print de, para, "ja estao conectados"
    return tamanho_total

print kruskal(rodovias)
