#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer = vector(2, 0);
    int zero = 0;
    int correct = 0;
    
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            zero++;
            continue;
        }
        auto vi = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (vi != win_nums.end()) {
            correct++;
        }
    }
    answer[0] = 7 - (correct + zero) < 6 ? 7 - (correct + zero) : 6;
    answer[1] = 7 - (correct) < 6 ? 7 - (correct) : 6;
    return answer;
}