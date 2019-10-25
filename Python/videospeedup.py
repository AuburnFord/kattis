def main():
	n,p,k = map(int, input().split())
	times = [int(x) for x in input().split()]	
	tot = 0
	start = 0
	mult = 1
	for x in times:
		tot += (x - start)*mult
		start = x
		mult += p/100 
	tot += (k - start)*mult
	print(tot)

if __name__ == "__main__":
	main()
