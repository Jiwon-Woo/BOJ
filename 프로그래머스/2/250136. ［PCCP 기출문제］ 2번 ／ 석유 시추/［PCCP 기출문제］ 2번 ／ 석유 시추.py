from collections import deque


def bfs(row, col, n, m, land, id):
    queue = deque()
    queue.append((row, col))
    land[row][col] = id
    
    connects = [(-1, 0), (0, -1), (0, 1), (1, 0)]
    while len(queue) > 0:
        x, y = queue.pop()
        for i, j in connects:
            curr_x, curr_y = x + i, y + j
            if curr_x < 0 or curr_x >= n or curr_y < 0 or curr_y >= m:
                continue
            if land[curr_x][curr_y] != 1:
                continue
            queue.append((curr_x, curr_y))
            land[curr_x][curr_y] = id


def calculate_oil(land, n, m, id):
    amount_of_oil = [0 for _ in range(id)]
    col_of_oil = [set() for _ in range(m)]
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 0:
                continue
            amount_of_oil[land[i][j]] += 1
            col_of_oil[j].add(land[i][j])
    
    return amount_of_oil, col_of_oil
    

def get_max_oil(m,amount_of_oil, col_of_oil):
    sum_of_oil = [0 for _ in range(m)]
    
    for i in range(m):
        for oil_id in col_of_oil[i]:
            sum_of_oil[i] += amount_of_oil[oil_id]
    
    return sum_of_oil
    
    
    
def solution(land):
    id = 2
    n, m = len(land), len(land[0])
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1:
                bfs(i, j, n, m, land, id)
                id += 1
    
    oil_set = set()
    amount_of_oil, col_of_oil = calculate_oil(land, n, m, id)
    sum_of_oil = get_max_oil(m, amount_of_oil, col_of_oil)
    
    return max(sum_of_oil)