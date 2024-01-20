from collections import deque

def bfs():
    N, M = map(int, input().split(" "))

    map = [input() for _ in range(N)]


    visited = [[0 for _ in range(M)] for _ in range(N)]
    cost_map = [[0 for _ in range(M)] for _ in range(N)]
    move_direct = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    nominate_pos = deque()
    nominate_pos.append((0, 0))
    while nominate_pos:
        cur_x, cur_y = nominate_pos.popleft()
        visited[cur_y][cur_x] = 1
        
        for x_direct, y_direct in move_direct:
            next_x = cur_x + x_direct
            next_y = cur_y + y_direct
            if next_x >= 0 and next_x < M and next_y >= 0 and next_y < N and map[next_y][next_x] == "1" and visited[next_y][next_x] == 0:
                nominate_pos.append([next_x, next_y])
                cost_map[next_y][next_x] = cost_map[cur_y][cur_x] + 1
        
    print(cost_map[N-1][M-1] + 1)    


if __name__ == "__main__":
    bfs()