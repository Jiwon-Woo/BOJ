#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix = vector(rows, vector(columns, 0));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = i * columns + j + 1;
        }
    }
    
    for (int i = 0; i < queries.size(); i++) {
        int small_x = queries[i][0] - 1;
        int small_y = queries[i][1] - 1;
        int large_x = queries[i][2] - 1;
        int large_y = queries[i][3] - 1;
        
        int x = small_x;
        int y = small_y;
        int init_value = matrix[small_x][small_y];
        int min_value = rows * columns + 1;

        while (true) {
            if (y == small_y + 1 && x == small_x) {
                matrix[x][y] = init_value;
                min_value = min(min_value, matrix[x][y]);
                break;
            } else if (y == small_y && x < large_x) {
                matrix[x][y] = matrix[x + 1][y];
                min_value = min(min_value, matrix[x][y]);
                x++;
            } else if (y < large_y && x == large_x) {
                matrix[x][y] = matrix[x][y + 1];
                min_value = min(min_value, matrix[x][y]);
                y++;
            } else if (y == large_y && x > small_x) {
                matrix[x][y] = matrix[x - 1][y];
                min_value = min(min_value, matrix[x][y]);
                x--;
            } else {
                matrix[x][y] = matrix[x][y - 1];
                min_value = min(min_value, matrix[x][y]);
                y--;
            }
        }
        
        answer.push_back(min_value);
    }

    
    return answer;
}