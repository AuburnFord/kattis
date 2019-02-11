mem = [[-1 for x in range(5001)] for y in range(101)]

def calc(decksLeft, target, cards):
	if mem[decksLeft][target]!=-1:
		return mem[decksLeft][target]
	poss = 0;
	val = 1
	if decksLeft!=0:
		while val <= cards and val <= target - (decksLeft-1):
			if val + decksLeft-1<=target and val + (decksLeft-1)*cards >=target:
				poss += calc(decksLeft-1, target-val, cards)
			val+=1				
	else:
		poss = 1
	mem[decksLeft][target] = poss
	return poss

def main():
	n,k,t = raw_input().split()
	n = int(n)
	k = int(k)
	t = int(t)
	print(calc(n,t,k)%1000000009)

if __name__ == '__main__':
    main()
