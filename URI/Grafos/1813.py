#coding: utf-8

from Queue import PriorityQueue

INF = float('inf')

cidades, estradas = map(int, raw_input().split())

def atualiza_estrada(origem, destino, distancia, tempo):
    matriz[origem - 1][destino - 1] = [distancia, tempo]

def bfs(matriz, origem, destino, tempo_limite):
    cidades = len(matriz)
    dists = [[float('inf'), float('inf')] for i in xrange(cidades)]
    fila = PriorityQueue()
    fila.put((0, 0, origem))    #distancia, tempo, no
    dists[origem] = (0, 0)

    while not fila.empty():
        dist_atual, tempo_atual, no_atual = fila.get()

        for vizinho in xrange(cidades):
            
            dist = matriz[no_atual][vizinho][0]
            tempo = matriz[no_atual][vizinho][1]

            novo_tempo = tempo+tempo_atual
            nova_dist = dist+dist_atual
            
            if novo_tempo > tempo_limite:
                continue

            if (nova_dist < dists[vizinho][0]):
                fila.put((nova_dist, novo_tempo, vizinho))
                dists[vizinho] = [nova_dist, novo_tempo]
                
    return dists[destino]

instancia = 0
while (cidades + estradas > 0):
    matriz = [[[INF, INF] for i in xrange(cidades)] for j in xrange(cidades)] # (distancia, tempo)
    for i in xrange(cidades):
        matriz[i][i] = [0, 0]
 
    for i in xrange(estradas):
        origem, destino, distancia, tempo = map(int, raw_input().split())
        estrada = matriz[origem - 1][destino - 1]

        if (estrada[0] > distancia):
            atualiza_estrada(origem, destino, distancia, tempo)
        elif (estrada[0] == distancia and estrada[1] > tempo):
            atualiza_estrada(origem, destino, distancia, tempo)
 
    num_entregas = int(raw_input())

    instancia += 1
    print "Instancia %d" % instancia
 
    for i in xrange(num_entregas):
        origem, destino, tempo_limite = map(int, raw_input().split())     
        res = bfs(matriz, origem-1, destino-1, tempo_limite)
        if res[1] <= tempo_limite:
           print "Possivel - %d km, %d min" % (res[0], res[1])
        else:
           print "Impossivel"
    print ""
    cidades, estradas = map(int, raw_input().split())

'''
5 8
1 2 1 3
1 4 1 1
2 3 1 8
2 4 3 1
3 5 1 3
4 5 4 2
5 1 8 8
5 3 1 1
5
1 5 7
5 1 5
1 3 4
1 3 12
1 3 3
0 0
'''
