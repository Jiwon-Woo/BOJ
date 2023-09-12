#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void recur(vector<vector<int>> users, vector<vector<int>> prices, vector<int> sales, int size, vector<int> &answer) {
    if (sales.size() == size) {
        vector<pair<bool, int>> user_emo = vector(users.size(), make_pair(false, 0));
        int emoticon_plus = 0;
        int emoticon_pay = 0;
        
        for (int i = 0; i < users.size(); i++) {
            for (int j = 0; j < sales.size(); j++) {
                if (users[i][0] > sales[j] * 10 || user_emo[i].first) {
                    continue;
                }
                user_emo[i].second += prices[j][sales[j]];
                emoticon_pay += prices[j][sales[j]];
                if (user_emo[i].second >= users[i][1]) {
                    emoticon_plus++;
                    emoticon_pay -= user_emo[i].second;
                    user_emo[i].first = true;
                    user_emo[i].second = 0;
                    
                }
            }
        }
        if (answer[0] == emoticon_plus) {
            answer[1] = max(emoticon_pay, answer[1]);
        } else if (answer[0] < emoticon_plus){
            answer[0] = emoticon_plus;
            answer[1] = emoticon_pay;
        }
        return;
    }
    
    for (int i = 1; i <= 4; i++) {
        sales.push_back(i);
        recur(users, prices, sales, size, answer);
        sales.pop_back();
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = vector(2, 0);
    vector<vector<int>> prices = vector(emoticons.size(), vector(5, 0));
    
    for (int i = 0; i < emoticons.size(); i++) {
        for (int j = 0; j <= 4; j++) {
            prices[i][j] = emoticons[i] - emoticons[i] * 0.1 * j;
        }
    }
    
    recur(users, prices, vector<int>(), emoticons.size(), answer);
    return answer;
}