from sys import stdin

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
	nums = stdin.readlines()
	for x in range(c):
		sizes.append(int(nums[x]))
	sizes.sort()
	waste = 0
	for x in range(c,c+r):
		waste += minWaste(int(nums[x]))
	print(waste)

if __name__ == "__main__":
	main()
