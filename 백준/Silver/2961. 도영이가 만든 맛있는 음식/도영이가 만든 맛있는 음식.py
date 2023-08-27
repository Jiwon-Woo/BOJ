import sys

N = int(sys.stdin.readline())
ingredients = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
mini = 999999999


def recur(index, use, sour, bitter):
    global ingredients, mini

    if index == N:
        if use == 0:
            return
        mini = min(mini, abs(sour - bitter))
        return

    recur(index + 1, use + 1, sour *
          ingredients[index][0], bitter + ingredients[index][1])

    recur(index + 1, use, sour, bitter)


recur(0, 0, 1, 0)
print(mini)
