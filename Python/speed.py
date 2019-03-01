def calc(guess, offset, miles):
	val = 0	
	for x in range(len(offset)):
		if not guess+offset[x] == 0:
			val += miles[x]/(guess+offset[x])
	return val

def main():
	n,t = input().split()
	n = int(n)
	t = int(t)
	minN = 1000
	offset = []
	miles = []
	for i in range(n):
		a,b = input().split()
		if int(b) < minN:
			minN = int(b)
		miles.append(int(a))
		offset.append(int(b))
	PRECISION = 0.0000001
	upper = 10**7
	lower = -minN
	guess = (upper+lower)/2
	val = calc(guess,offset,miles)
	count = 0
	while abs(val - t) > PRECISION and count < 200:
		if val < t:
			upper = guess
		else:
			lower = guess
		guess = (upper+lower)/2
		val = calc(guess,offset,miles)
		count+=1
	print(guess)

if __name__ == "__main__":
	main()
