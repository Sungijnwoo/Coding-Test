from collections import deque
import sys
sys.setrecursionlimit(1000000)

def main():
    M, N = map(int, input().split(" "))
    graph = [list(map(int, input().split(" "))) for _ in range(N)]
    move_direct = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    nominate_pos = []
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                nominate_pos.append([i, j])

    result = bfs(nominate_pos, graph)
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                print(-1)
                return
    print(result - 1)

def bfs(nominate_pos, graph):
    move_direct = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    count = 0
    while nominate_pos:
        count += 1
        n_nominate_pos = []
        for i, j in nominate_pos:
            for di, dj in move_direct:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= len(graph) or nj < 0 or nj >= len(graph[0]):
                    continue
                if graph[ni][nj] == 0:
                    graph[ni][nj] = 1
                    n_nominate_pos.append([ni, nj])      
        nominate_pos = n_nominate_pos[:]

    return count      
    

if __name__ == "__main__":
    main()