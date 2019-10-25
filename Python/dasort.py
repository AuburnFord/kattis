def main():
	c = int(input())
	out = ""
	for _ in range(c):
		l = input().split()
		a = []
		need = int(l[1])
		while need > 0:
			a.extend([int(x) for x in input().split()])
			need -= 10
		b = sorted(a)
		count = 0
		idx = 0
		for el in a:
			if b[idx] == el:
				idx+=1
			else:
				count+=1
		out += str(l[0]) + " " + str(count) + "\n"
	print(out[:-1])

if __name__ == "__main__":
	main()
