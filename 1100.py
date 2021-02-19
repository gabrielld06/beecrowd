R = 8
C = 8

dc = [1, 2, 2, 1, -1, -2, -2, -1]
dr = [-2, -1, 1, 2, -2, -1, 1, 2]

alf = {'a' : 0, 'b' : 1, 'c' : 2,  'd' : 3, 'e' : 4, 'f' : 5, 'g' : 6, 'h' : 7}

def explore_neighbours(r, c):
    global nodes_in_next_layer
    
    for i in range(8):
        rr = r + dr[i]
        cc = c + dc[i]
        
        if rr < 0 or cc < 0: continue
        if rr >= R or cc >= C: continue
    
        if visited[rr][cc]: continue
    
        rq.append(rr)
        cq.append(cc)
        visited[rr][cc] = True
        nodes_in_next_layer += 1

def solve():
    global nodes_left_in_layer
    global nodes_in_next_layer
    move_count = 0
    reached_end = False
    rq.append(sr)
    cq.append(sc)
    visited[sr][sc] = True
    
    while len(rq) > 0:
        r = rq[0]
        c = cq[0]
        rq.pop(0)
        cq.pop(0)
        if r == fr and c == fc:
            reached_end = True
            break
        explore_neighbours(r, c)
        nodes_left_in_layer -= 1
        if nodes_left_in_layer == 0:
            nodes_left_in_layer = nodes_in_next_layer
            nodes_in_next_layer = 0
            move_count += 1
    return move_count


while True:
  try:

    pos1, pos2 = input().split()
    sr = alf[pos1[0]]
    sc = int(pos1[1])-1
    fr = alf[pos2[0]]
    fc = int(pos2[1])-1
    rq = []
    cq = []
    
    nodes_left_in_layer = 1
    nodes_in_next_layer = 0
    
    visited = [[False for i in range(C)] for j in range(R)]
    
    print('To get from {} to {} takes {} knight moves.'.format(pos1, pos2, solve()))

  except EOFError:
    break
