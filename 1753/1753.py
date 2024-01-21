import sys
from collections import defaultdict
from collections import deque
sys.setrecursionlimit(1000000)

def main():
    V, E = map(int, input().split(" "))
    start_point = int(input())
    graph = defaultdict(lambda : defaultdict(lambda : 1e10))
    for _ in range(E):
        u, v, w = map(int, input().split(" "))
        graph[u][v] = min(graph[u][v], w)

    nominate_pos = deque()
    nominate_pos.append([start_point, 0])
    result = {i: 1e10 for i in range(V+1)}
    visited = [False for _ in range(V+1)]
    result[start_point] = 0
    visited[0] = True
    while not all(visited):
        visited[start_point] = True
        for v, w in graph[start_point].items():
            if w +  + result[start_point] < result[v]:
                result[v] = w +  + result[start_point]
        
        min_cost = 1e11
        for idx in range(1, V+1):
            if not visited[idx] and result[idx] < min_cost:
                min_cost = result[idx]
                start_point = idx
    
    for i in range(1, V+1):
        if result[i] != 1e10:
            print(result[i])
        else:
            print("INF")


if __name__ == "__main__":
    main()