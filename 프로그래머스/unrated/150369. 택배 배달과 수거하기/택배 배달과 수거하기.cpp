#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int last_deliveries_idx = -1;
    int last_pickups_idx = -1;
    
    for (int i = deliveries.size() - 1; i > -1; i--) {
        if (deliveries[i]) {
            last_deliveries_idx = i;
            break;
        }
    }
    
    for (int i = pickups.size() - 1; i > -1; i--) {
        if (pickups[i]) {
            last_pickups_idx = i;
            break;
        }
    }
    
    
    while (last_deliveries_idx > -1 || last_pickups_idx > -1) {
        // cout << last_deliveries_idx << ", " << last_pickups_idx << "\n";
        answer += max(last_deliveries_idx, last_pickups_idx) + 1;
        // cout << "answer:" << answer << "\n";
        
        int delivery_cap = cap;
        for (int i = last_deliveries_idx; i > -1; i--) {
            if (delivery_cap > deliveries[i]) {
                delivery_cap -= deliveries[i];
                deliveries[i] = 0;
                if (i == 0) {
                    last_deliveries_idx = -1;
                }
            } else if (delivery_cap < deliveries[i]) {
                deliveries[i] -= delivery_cap;
                delivery_cap = 0;
                last_deliveries_idx = i;
                break;
            } else {
                deliveries[i] = 0;
                delivery_cap = 0;
                last_deliveries_idx = i - 1;
            }
        }
        
        int pickup_cap = cap;
        for (int i = last_pickups_idx; i > -1; i--) {
            if (pickup_cap > pickups[i]) {
                pickup_cap -= pickups[i];
                pickups[i] = 0;
                if (i == 0) {
                    last_pickups_idx = -1;
                }
            } else if (pickup_cap < pickups[i]) {
                pickups[i] -= pickup_cap;
                pickup_cap = 0;
                last_pickups_idx = i;
                break;
            } else {
                pickups[i] = 0;
                pickup_cap = 0;
                last_pickups_idx = i - 1;
            }
        }
    
    }
    
    return answer * 2;
}