def main():
	out = []
	while True:
		h,k = [int(x) for x in input().split()]
		if h == 0 and k == 0:
			break
		heads = []
		knights = []
		for _ in range(h):
			heads.append(int(input()))
		for _ in range(k):
			knights.append(int(input()))
		heads.sort(reverse=True)
		knights.sort(reverse=True)
		total = 0
		while heads and knights and len(heads) <= len(knights):
			if heads[-1] <= knights[-1]:
				total += knights.pop()
				heads.pop()
			else:
				knights.pop()
		if not heads:
			out.append(str(total))
		else:	
			out.append("Loowater is doomed!")
	print("\n".join(out))

if __name__ == "__main__":
	main()
