def main():
	cards = input().split()
	c = {}
	for x in cards:
		if x[0] not in c:
			c[x[0]] = 0
		c[x[0]] += 1
	count = -1
	for x in c:
		if c[x] > count:
			count = c[x]
	print(count)

if __name__ =="__main__":
	main()
