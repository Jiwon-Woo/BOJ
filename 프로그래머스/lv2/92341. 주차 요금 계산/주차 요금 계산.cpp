#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int end_of_day = 23 * 60 + 59;


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car_park_info;
    
    for (int i = 0; i < records.size(); i++) {
        string car_number = records[i].substr(6, 4);
        int hour = (records[i][0] - '0') * 10 + records[i][1] - '0';
        int min = (records[i][3] - '0') * 10 + records[i][4] - '0';
        
        if (car_park_info.find(car_number) == car_park_info.end()) {
            car_park_info[car_number] = end_of_day - (hour * 60 + min);
        } else if (records[i].size() == 13) {
            car_park_info[car_number] += end_of_day - (hour * 60 + min);
        } else {
            car_park_info[car_number] -= end_of_day - (hour * 60 + min);
        }
    }
    
    for (auto info: car_park_info) {
        if (info.second <= fees[0]) {
            answer.push_back(fees[1]);
        } else {
            int fee = fees[1] + ceil((info.second - fees[0]) / (double)fees[2]) * fees[3];
            answer.push_back(fee);
        }
    }
    
    return answer;
}