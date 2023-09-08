def solution(rows, columns, queries):
    square = [[j * columns + i + 1 for i in range(columns)] for j in range(rows)]
    answer = []
    
    for query in queries:
        x1, y1, x2, y2 = [q - 1 for q in query]
        
        mini = 10000
        mini = min(mini, square[x1][y1])
        store = square[x1][y1]
        
        x, y = x1 + 1, y1
        while not (x == x1 and y == y1):
            mini = min(mini, square[x][y])
            if y == y1:
                square[x - 1][y] = square[x][y]
                if x + 1 <= x2:
                    x += 1
                else:
                    y += 1
            elif x == x2:
                square[x][y - 1] = square[x][y]
                if y + 1 <= y2:
                    y += 1
                else:
                    x -= 1
            elif y == y2:
                square[x + 1][y] = square[x][y]
                if x - 1 >= x1:
                    x -= 1
                else:
                    y -= 1
            elif x == x1:
                square[x][y + 1] = square[x][y]
                if y - 1 >= y1:
                    y -= 1
        square[x1][y1 + 1] = store        
        answer.append(mini)
    
    
    return answer