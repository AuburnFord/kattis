def main():
	planets = int(input())
	for i in range(planets):
		start, rate, bound = map(int, input().split())
		count = 0
		while start <= bound:
			start *= rate
			count += 1
		print(count)

if __name__ == "__main__":
	main()
