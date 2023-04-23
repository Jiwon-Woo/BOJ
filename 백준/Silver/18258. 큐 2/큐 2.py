import sys
from collections import deque

class Myqueue:
	def __init__(self):
		self.queue = deque()
		return

	def push(self, num):
		self.queue.append(num)
		return

	def pop(self):
		if (len(self.queue) == 0):
			return -1
		return (self.queue.popleft())

	def size(self):
		return (len(self.queue))

	def empty(self):
		return (int(len(self.queue) == 0))

	def front(self):
		if (len(self.queue) == 0):
			return -1
		return (self.queue[0])
	
	def back(self):
		if (len(self.queue) == 0):
			return -1
		return (self.queue[-1])


n = int(input())
commands = []
for i in range(n):
	cmd = sys.stdin.readline().rstrip()
	if (cmd.startswith('push') == 1):
		cmd = cmd.split(' ')[1]
	commands.append(cmd)

def	ft_stack(n, commands):
	queue = Myqueue()
	for i in range(n):
		if (commands[i].isdigit() == 1):
			queue.push(int(commands[i]))
		elif (commands[i] == 'pop'):
			print(queue.pop())
		elif (commands[i] == 'size'):
			print(queue.size())
		elif (commands[i] == 'empty'):
			print(queue.empty())
		elif (commands[i] == 'front'):
			print(queue.front())
		elif (commands[i] == 'back'):
			print(queue.back())
	return

ft_stack(n, commands)