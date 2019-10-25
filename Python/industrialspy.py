from math import ceil,sqrt
from collections import deque
import time
def calc_primes(rnge,primes):
	primes[0] = False
	primes[1] = False
	for x in range(4,rnge,2):
		primes[x] = False
#	for x in range(9,rnge,6):
#		primes[x] = False
	for x in range(3,int(ceil(sqrt(rnge)))):
		if primes[x]:
			for y in range(x*x, rnge, 2*x):
				primes[y] = False

def main():
	primes = [True]*10000000
	now = time.time()
	calc_primes(10000000,primes)	
#	print(time.time()-now)

	cases = int(input())
	for _ in range(cases):

		nums = [int(x) for x in input()]
#		print(nums)
		seen = set() # numbers already seen
		count = 0
		
		lngth = len(nums)
		q = deque()
		for x in range(lngth):
			if nums[x] not in seen:
				q.append((nums[x], set([x])))
				seen.add(nums[x])
				if primes[nums[x]]:
					count+=1
		while q:
			val,idx = q.popleft()	
#			print(val,idx)
			for x in range(lngth):
				if x not in idx:
					nval = val *10 + nums[x]
					if nval not in seen:
						tmp = idx.copy()
						tmp.add(x)
						q.append((nval, tmp))
						seen.add(nval)
						if primes[nval]:
							count+=1
		print(count)

if __name__ == "__main__":
	main()
