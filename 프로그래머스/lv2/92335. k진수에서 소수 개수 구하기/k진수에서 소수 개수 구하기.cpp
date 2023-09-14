#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int is_prime(long p) {
    if (p <= 1)
        return 0;
    
    for (long i = 2; i <= sqrt(p); i++) {
        if (p % i == 0)
            return 0;
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    long p = 0;
    
    int exp = 0;
    while (n > 0) {
        if (n % k == 0) {
            answer += is_prime(p);
            p = 0;
            exp = 0;
        } else {
            p += (n % k) * pow(10, exp);
            exp++;
        }
        n /= k;
    }
    answer += is_prime(p);
    
    return answer;
}