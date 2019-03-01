seen = set()
while True:
	try:
		a = input().split()
	except EOFError:
		break
	for x in a:
		if not (x.lower() in seen):
			print(x,end=" ")	
			seen.add(x.lower())
		else:
			print(".",end=" ")
	print()
