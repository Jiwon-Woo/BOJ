import sys

k = int(sys.stdin.readline())
limit_k = int(k**0.5)

i = 2
gemstone = []
while i <= limit_k and k > 1:
    while k % i == 0 and k > 1:
        k = k // i
        gemstone.append(i)
    i += 1

if k > 1:
    gemstone.append(k)

print(len(gemstone))
print(*gemstone)
