#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<string, int> score;
    
    score["R"] = 0; score["T"] = 0;
    score["C"] = 0; score["F"] = 0;
    score["J"] = 0; score["M"] = 0;
    score["A"] = 0; score["N"] = 0;
    
    for (int i = 0; i < choices.size(); i++) {
        string type;
        if (choices[i] < 4) {
            type += survey[i][0];
            score[type] += 4 - choices[i];
        } else if (choices[i] > 4) {
            type += survey[i][1];
            score[type] += choices[i] - 4;
        }
    }
    
    score["R"] >= score["T"] ? answer.push_back('R') : answer.push_back('T');
    score["C"] >= score["F"] ? answer.push_back('C') : answer.push_back('F');
    score["J"] >= score["M"] ? answer.push_back('J') : answer.push_back('M');
    score["A"] >= score["N"] ? answer.push_back('A') : answer.push_back('N');
    
    return answer;
}