sizes = []

def minWaste(req):
	l = 0
	r = len(sizes)-1
	while l<r:
		m = l + (r-l)//2;
		if sizes[m] == req:
			return 0	
		if sizes[m] > req:
			r = m
		else:
			l = m + 1
	return sizes[l] - req	

def main():
	c,r = [int(x) for x in input().split()]
	for x in range(c):
		sizes.append(int(input()))
	sizes.sort()
	waste = 0
	for x in range(r):
		waste += minWaste(int(input()))
	print(waste)

if __name__ == "__main__":
	main()
