# # Busca em largura carecalol
# from collections import deque

# class Graph:
#   def __init__(self, V, Adj):
#     self.V = V
#     self.Adj = Adj

# class Vertex:
#   def __init__(self, d, cor):
#     self.d = d
#     self.cor = cor

# def enqueue(Q,v):
#     Q.append(v)
    
# def dequeue(Q):
#     return Q.popleft()

# def bfs(G, s):
#     G.V[s].d = True
#     G.V[s].cor = 'cinza'
#     Q = deque([])
#     enqueue(Q,s)
#     while(len(Q) != 0):
#         u = dequeue(Q)
#         for v in G.Adj[u]:
#             if G.V[v].cor == 'branco':
#                 G.V[v].cor = 'cinza'
#                 G.V[v].d = not G.V[u].d
#                 enqueue(Q, v)
#             elif u != v and G.V[u].d == G.V[v].d:
#                 return False
#         G.V[u].cor = 'preto'
#     return True

# n = int(input())

# g = Graph([], [])
# g.V = [Vertex(None, 'branco') for i in range(n)]
# g.Adj = []
# index = 0
# while(index < n):
#     line = input().split()
#     g.Adj.append([])
#     for i in range(len(line)):
#         if(int(line[i]) > 0):
#             g.Adj[index].append(i)
#     index += 1
# resp = "Fail!" if bfs(g, 0) else "Bazinga!"
# print(resp)


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
        for v in range(len(G.Adj[u])):
            if G.Adj[u][v] == 0 and G.V[v].cor == 'branco':
                G.V[v].cor = 'cinza'
                G.V[v].d = not G.V[u].d
                enqueue(Q, v)
            elif G.Adj[u][v] == 0 and G.V[u].d == G.V[v].d:
                return False
        G.V[u].cor = 'preto'
    return True

n = int(input())

g = Graph([], [])
g.V = [Vertex(None, 'branco') for i in range(n)]
g.Adj = []
index = 0
while(index < n):
    line = input().split()
    g.Adj.append([])
    for i in range(len(line)):
        if i != index:
            g.Adj[index].append(int(line[i]))
        else:
            g.Adj[index].append(-1)
    index += 1
resp = "Bazinga!" if bfs(g, 0) else "Fail!"
print(resp)
