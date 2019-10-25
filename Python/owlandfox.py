def digsum(n):
	tot = 0
	while n > 0:
		tot += n%10
		n//=10
	return tot	

def main():
	cases = int(input())
	for x in range(cases):
		num = int(input())
		tar = digsum(num) - 1
		num -= 1
		while digsum(num) != tar:
			num -= 1
		print(num)
	
if __name__ == "__main__":
	main()
