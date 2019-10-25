def main(): 
	val = int(input())
	char = []
	while val > 0:
		char.append(val%2)
		val //=2
	newval = 0
	for x in range(len(char)):
		newval *= 2
		newval += char[x]
	print(newval)

if __name__ == "__main__":
	main()
