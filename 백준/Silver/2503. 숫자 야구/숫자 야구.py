import sys

N = int(sys.stdin.readline())
hint = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

sys.setrecursionlimit(999999999)

answer = 0


def calculate(number, hint_number, strike, ball):
    str_number = str(number)
    str_hint_number = str(hint_number)

    if str_number[0] == '0' or str_number[1] == '0' or str_number[2] == '0':
        return False
    if str_number[0] == str_number[1] or str_number[1] == str_number[2] or str_number[2] == str_number[0]:
        return False

    for i in range(3):
        for j in range(3):
            if str_number[i] != str_hint_number[j]:
                continue
            if i == j:
                strike -= 1
            else:
                ball -= 1

    if strike == 0 and ball == 0:
        return True
    return False


def recur(hint_idx, number):
    global answer

    if number == 1000:
        return

    if hint_idx == N:
        answer += 1
        recur(0, number + 1)
        return

    hint_number, strike, ball = hint[hint_idx]
    if calculate(number, hint_number, strike, ball):
        recur(hint_idx + 1, number)
    else:
        recur(0, number + 1)


recur(0, 123)
print(answer)
