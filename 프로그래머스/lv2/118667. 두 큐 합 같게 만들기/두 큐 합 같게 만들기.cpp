#include <string>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long answer = 0;
    deque<int> dequeue1(queue1.begin(), queue1.end());
    deque<int> dequeue2(queue2.begin(), queue2.end());
    long sum1 = accumulate(dequeue1.begin(), dequeue1.end(), 0);
    long sum2 = accumulate(dequeue2.begin(), dequeue2.end(), 0);
    long sum = sum1 + sum2;
    long diff = sum1 - sum2;
    
    if (sum % 2) {
        return -1;
    }
    
    long initial_sum1 = sum1;
    long initial_sum2 = sum2;
    while (diff) {
        if (diff > 0) {
            int temp = dequeue1[0];
            dequeue1.pop_front();
            dequeue2.push_back(temp);
            sum1 -= temp;
            sum2 += temp;
        } else {
            int temp = dequeue2[0];
            dequeue2.pop_front();
            dequeue1.push_back(temp);
            sum1 += temp;
            sum2 -= temp;
        }
        answer++;
        diff = sum1 - sum2;
        if (answer >= queue1.size() * 4) {
            return -1;
        }
    }
    
    return answer;
}