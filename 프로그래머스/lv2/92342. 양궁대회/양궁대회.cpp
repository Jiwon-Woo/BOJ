#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_diff = 0;
vector<int> answer = vector(1, -1);

void recur(int idx, vector<int> info, vector<int> result, int remain, int lion, int apeach) {
    if (idx == 10) {
        result[10] = remain;
        int diff = lion - apeach;
        if (diff > max_diff) {
            answer = result;
            max_diff = diff;
        } else if (diff == max_diff) {
            for (int i = 11; i >= 0; i--) {
                if (answer[i] > result[i])
                    break;
                else if (answer[i] == result[i])
                    continue;
                answer = result;
                break;
            }
        }
        return;
    }
    
    // 어피치보다 한발 더 맞추는 경우
    if (remain > info[idx]) {
        result[idx] = info[idx] + 1;
        recur(idx + 1, info, result, remain - result[idx], lion + 10 - idx, apeach);
    }

    // 아예 안맞추는 경우
    result[idx] = 0;
    if(info[idx] == 0 && result[idx] == 0)
        recur(idx + 1, info, result, remain, lion, apeach);
    else if(info[idx] >= result[idx])
        recur(idx + 1, info, result, remain, lion, apeach + 10 - idx);

}

vector<int> solution(int n, vector<int> info) {
    
    recur(0, info, vector<int>(11, 0), n, 0, 0);
    return answer;
}