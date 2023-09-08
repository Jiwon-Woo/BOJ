import math

def solution(enroll, referral, seller, amount):
    answer = [0 for _ in range(len(enroll))]
    index_dict = {}
    
    for i in range(len(enroll)):
        index_dict[enroll[i]] = i
    
    for i in range(len(seller)):
        idx = index_dict[seller[i]]
        profit = amount[i] * 10
        answer[idx] += amount[i] * 90
        refer = referral[idx]
        
        while not (refer == '-' or profit < 1):
            idx = index_dict[refer]
            answer[idx] += profit - profit // 10
            refer = referral[idx]
            profit = profit // 10
    
    return answer