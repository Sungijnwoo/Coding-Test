from itertools import combinations
from collections import deque
from copy import deepcopy
def main():
    N, M = map(int, input().split(" "))
    graph = [list(map(int, input().split(" "))) for _ in range(N)]

    empties = deque()
    viruses = deque()
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                empties.append([i, j])
            elif graph[i][j] == 2:
                viruses.append([i, j])

    wall_cases = combinations(empties, 3)
    result = 0
    for wall_case in wall_cases:
        copy_grpah = deepcopy(graph)
        copy_viruses = deepcopy(viruses)
        copy_grpah[wall_case[0][0]][wall_case[0][1]] = 1
        copy_grpah[wall_case[1][0]][wall_case[1][1]] = 1
        copy_grpah[wall_case[2][0]][wall_case[2][1]] = 1
        result = max(result, bfs(copy_grpah, copy_viruses))
    print(result)

def bfs(graph, viruses):
    move_direct = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    while viruses:
        virus_i, virus_j = viruses.popleft()
        for d_i, d_j in move_direct:
            n_i, n_j = virus_i + d_i, virus_j + d_j
            if n_i < 0 or n_i >= len(graph) or n_j < 0 or n_j >= len(graph[0]):
                continue
            if graph[n_i][n_j] == 0:
                graph[n_i][n_j] = 2
                viruses.append([n_i, n_j])
    
    count = 0
    for i in graph:
        for j in i:
            if j == 0:
                count += 1
    return count
    





if __name__ == "__main__":
    main()