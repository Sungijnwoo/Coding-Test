from collections import deque
import sys
sys.setrecursionlimit(1000000)

def main():
    N = int(input())
    graph = [list(map(int, input())) for i in range(N)]
    visited = [[0 for _ in range(N)] for _ in range(N)]
    result = []
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0 and graph[i][j] == 1:
                result.append(bfs(i, j, graph, visited))
    
    result.sort()
    print(len(result))
    for count in result:
        print(count)
    

def bfs(i, j, graph, visited):
    move_direct = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    count = 0
    nominate_pos = deque()
    nominate_pos.append([i, j])
    visited[i][j] = 1
    while nominate_pos:
        count += 1
        cur_i, cur_j = nominate_pos.popleft()
        for di, dj in move_direct:
            next_i, next_j = cur_i + di, cur_j + dj

            if next_i < 0 or next_i >= len(graph) or next_j < 0 or next_j >= len(graph):
                continue

            if graph[next_i][next_j] == 1 and visited[next_i][next_j] == 0:
                visited[next_i][next_j] = 1
                nominate_pos.append([next_i, next_j])
    return count
    



if __name__ == "__main__":
    main()