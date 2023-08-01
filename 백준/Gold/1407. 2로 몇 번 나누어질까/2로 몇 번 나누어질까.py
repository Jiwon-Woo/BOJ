import sys

a, b = map(int, sys.stdin.readline().split())

answer = 0
power = 1
power_of_2 = 2**power
while power_of_2 <= b:
    answer += (b // power_of_2 - (a - 1) // power_of_2) * (2**(power - 1))
    power += 1
    power_of_2 = 2**power


answer += (b - a + 1)
print(answer)