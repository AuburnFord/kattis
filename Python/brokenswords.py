def main():
	swords = int(input())
	t = 0
	l = 0
	for x in range(swords):
		sword = input()
		if sword[0] == '0':
			t += 1
		if sword[1] == '0':
			t += 1
		if sword[2] == '0':
			l += 1
		if sword[3] == '0':
			l += 1
	new = 0
	while True:
		if t > 1 and l > 1:
			new += 1
			t -= 2
			l -= 2
		else:
			break
	print(new, t, l)
		

if __name__ == "__main__":
	main()
