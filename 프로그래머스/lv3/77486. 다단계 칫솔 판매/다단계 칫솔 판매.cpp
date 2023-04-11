#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer = vector(enroll.size(), 0);
    map<string, int> index_tree;
    
    for (int i = 0; i < enroll.size(); i++) {
        index_tree[enroll[i]] = i;
    }
    
    for (int i = 0; i < seller.size(); i++) {
        int idx = index_tree[seller[i]];
        int profit = amount[i] * 100;

        while (profit) {
            int commission = profit * 0.1;
            if (referral[idx] == "-") {
                answer[idx] += profit - commission;
                break;
            }
            answer[idx] += profit - commission;
            profit = commission;
            idx = index_tree[referral[idx]];
        }
        
    }
    
    return answer;
}