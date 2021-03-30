# Busca em largura carecalol
from collections import deque

class Graph:
  def __init__(self, V, Adj):
    self.V = V
    self.Adj = Adj

class Vertex:
  def __init__(self, d, cor):
    self.d = d
    self.cor = cor

def enqueue(Q,v):
    Q.append(v)
    
def dequeue(Q):
    return Q.popleft()

def bfs(G, s):
    G.V[s].d = True
    G.V[s].cor = 'cinza'
    Q = deque([])
    enqueue(Q,s)
    while(len(Q) != 0):
        u = dequeue(Q)
        for v in G.Adj[u]:
            if G.V[v].cor == 'branco':
                G.V[v].cor = 'cinza'
                G.V[v].d = not G.V[u].d
                enqueue(Q, v)
            elif u != v and G.V[u].d == G.V[v].d:
                return False
        G.V[u].cor = 'preto'
    return True

n = int(input())
while(n != 0):
    g = Graph([], [])
    g.V = [Vertex(None, 'branco') for i in range(n)]
    g.Adj = []
    for i in range(n):
        index = int(input()) - 1
        line = input().split()
        g.Adj.append([])
        for i in range(len(line)):
            g.Adj[index].append(int(line[i])-1)
    resp = "SIM" if bfs(g, 0) else "NAO"
    print(resp)
    n = int(input())
    
