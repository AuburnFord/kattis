while True:
	try:
		a = [int(x) for x in input().split()]
	except EOFError:
		break
	sum2 = 0
	for x in a:
		sum2+=x
	print(sum2//2)
