def solution(lottos, win_nums):
    zero = lottos.count(0)
    match = 0
    
    for i in range(len(lottos)):
        if (lottos[i] != 0) and (lottos[i] in win_nums):
            match += 1
    
    high = 7 - (match + zero) if 7 - (match + zero) < 7 else 6
    low = 7 - match if 7 - match < 7 else 6
    answer = [high, low]
    return answer