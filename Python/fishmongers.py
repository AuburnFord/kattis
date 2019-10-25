from sys import stdin, stdout

def main():
	num_fish, num_buyers = [int(x) for x in stdin.readline().split()]
	fish_wgt = sorted([int(x) for x in stdin.readline().split()], reverse = True)
	buyers = {}
	for idx in range(num_buyers):
		line = [int(x) for x in input().split()]
		buyers[line[1]] = buyers.get(line[1], 0) + line[0]
	total = 0
	idx = 0
	idx1 = 0
	vals = sorted(buyers.keys(), reverse = True)
	len1 = len(vals)
	while idx < num_fish and idx1 < len1:
		val = vals[idx1]
		buyers[val] -= 1
		total += val * fish_wgt[idx]
		if buyers[val] == 0:
			idx1+=1
		idx += 1
	print(total)	
		
if __name__ == "__main__":
	main()
