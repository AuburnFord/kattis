from itertools import combinations

def main():
	cases = int(input())
	for x in range(1, cases + 1):
		seen = {} 
		ints = [int(n) for n in input().split()]
		n = ints[0]
		ints = ints[1:]
		i = 1
		while i < n+1:
			for tuples in combinations(ints, i):
				total = sum_tup(tuples)
				if seen.setdefault(total,tuples) != tuples:
					print("Case #" + str(x) + ":\n" + " ".join(str(o) for o in tuples) + "\n" + " ".join(str(o) for o in seen[total]))
					i = n+2 
					break
			i+=1
		if i == n+1:
			print("Impossible")

def sum_tup(nums):
	total = 0
	for x in nums:
		total += x	
	return total

if __name__ == "__main__":
	main()
