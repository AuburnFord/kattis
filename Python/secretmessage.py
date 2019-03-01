import math

c = int(input())
for x in range(c):
	msg = input()
	length = len(msg)
	size = math.ceil(math.sqrt(length))
	for x in range(size*size-length):
		msg+="*"
	for x in range(size*size):
		if msg[x//size + size*(size-1-(x%size))]!="*":
			print(msg[x//size + size*(size-1-(x%size))], end="")
	print("")
