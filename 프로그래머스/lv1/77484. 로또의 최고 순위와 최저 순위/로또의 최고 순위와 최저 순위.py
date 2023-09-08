def solution(lottos, win_nums):
    lottos.sort()
    lottos.reverse()
    zero = lottos.count(0)
    match = 0
    
    for i in range(len(lottos) - zero):
        if lottos[i] in win_nums:
            match += 1
    
    high = 7 - (match + zero) if 7 - (match + zero) < 7 else 6
    low = 7 - match if 7 - match < 7 else 6
    answer = [high, low]
    return answer