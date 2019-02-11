val = input()
for i in range(128, 0, -1):
	if val % i**9 == 0:
		print i
		break

