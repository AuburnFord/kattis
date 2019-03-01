from sys import stdin, stdout
def main():
	n = [int(x) for x in stdin.readline().split()]
	given = list() 
	for x in stdin:
		given.append(int(x))
	seen = set(given) 
	cur = 0
	out = ''
	
	for num in given:
		while cur < num:
			cur += 1
			if cur not in seen:
				out += str(cur) + '\n'
		out += str(num) + '\n'
	cur += 1
	while cur <= n[0]:
		out+=str(cur)+'\n'
		cur+=1
	stdout.write(out)

if __name__ == "__main__":
	main()
