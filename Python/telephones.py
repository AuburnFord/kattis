from sys import stdin, stdout

def main():
	n,m = map(int, stdin.readline().split())
	while n!=0 or m!=0:
		conv = list() 
		for _ in range(n):
			o,p, start, lngth = map(int, stdin.readline().split())
			conv.append((start,start+lngth))	
		for _ in range(m):
			start,end = map(int, stdin.readline().split())
			end = start + end
			count = 0
			for s,e in conv:
				if (s < end and e > start):
					count += 1
		#	stdout.write(str(count) + '\n')	
			print(count)
		n,m = map(int, stdin.readline().split())

if __name__ == "__main__":
	main()
