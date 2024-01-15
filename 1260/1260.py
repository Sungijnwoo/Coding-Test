from collections import deque

def main():
    N, M, V = map(int, input().split(" "))
    
    dfs_visited = [False for _ in range(N+1)]
    bfs_visited = [False for _ in range(N+1)]
    linkList = {i: [] for i in range(N+1)}
    
    for _ in range(M):
        s, v = map(int, input().split(" "))
        linkList[s].append(v)
        linkList[v].append(s)
        linkList[s].sort()
        linkList[v].sort()
    dfsList = []
    bfsList = []
    dfs(linkList, dfs_visited, V, dfsList)
    bfs(linkList, bfs_visited, V, bfsList)
    print(*dfsList)
    print(*bfsList)

def dfs(linkList: list, visited: list, start: int, result: list):
    result.append(start)
    visited[start] = True
    for v in linkList[start]:
        if not visited[v]:
            dfs(linkList, visited, v, result)
    return result

def bfs(linkList: list, visited: list, start: int, result: list):
    queue = deque([start])
    visited[start] = True
    while queue:
        result.append(queue.popleft())
        for i in linkList[result[-1]]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    return result

      
if __name__ == "__main__":
    main()