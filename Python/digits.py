from sys import stdin,stdout

def count_dig(n):
	tmp = n
	count = 0
	while tmp != 0:
		count+=1
		tmp//=10
	return count

def main():
	a = stdin.readline().strip()
	out = []
	while a != "END":
		#flag = False
		count = 0
		#for x in range(len(a)):
		#	if a[x] != '0' or flag:
		#		count +=1
		#		flag = True
		count = len(a)
		if count ==0:
			out.append('2')
			a = stdin.readline().strip()
			continue
		if count == 1:
			if a == '1':
				out.append('1')
			else:
				out.append('2')
			a = stdin.readline().strip()
			continue
		ncount = 3
		cur = count_dig(count)
		while cur != 1:
			ncount += 1
			cur = count_dig(cur)
		out.append(str(ncount))
		a = stdin.readline().strip()
	stdout.write('\n'.join(out) + '\n')

if __name__ == "__main__":
	main()
