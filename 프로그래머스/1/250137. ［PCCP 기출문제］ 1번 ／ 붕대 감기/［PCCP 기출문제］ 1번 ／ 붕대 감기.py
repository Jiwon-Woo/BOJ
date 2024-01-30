def solution(bandage, health, attacks):
    answer = health
    
    for i in range(len(attacks)):
        if i > 0:
            interval = attacks[i][0] - attacks[i - 1][0] - 1
            answer += interval * bandage[1]
            answer += (interval // bandage[0]) * bandage[2]
            if answer > health:
                answer = health
        
        answer -= attacks[i][1]
        
        if answer <= 0:
            answer = -1
            break
        
    return answer