import sys

n = int(sys.stdin.readline())
qna_list = []
for _ in range(n):
    qna_list.append(list(map(int, sys.stdin.readline().split())))

answer = 0
for x in range(1, 10):
    for y in range(1, 10):
        for z in range(1, 10):
            if x == y or y == z or x == z:
                continue
            same = 0
            for qna in qna_list:
                strike = 0
                ball = 0
                str_num = str(x * 100 + y * 10 + z)
                str_q = str(qna[0])
                for i in range(0, 3):
                    for j in range(0, 3):
                        if str_num[i] == str_q[j]:
                            if i == j:
                                strike += 1
                            else:
                                ball += 1
                if strike != qna[1] or ball != qna[2]:
                    break
                same += 1
            if same == len(qna_list):
                answer += 1

print(answer)