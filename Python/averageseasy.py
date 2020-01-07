def main():
	cases = int(input())
	for _ in range(cases):
		input()
		ncs,ne = map(int, input().split())
		cs = [int(x) for x in input().split()]
		econ = [int(x) for x in input().split()]
		cs_sum = sum(cs)
		econ_sum = sum(econ)
		cs_avg = cs_sum/ncs
		econ_avg = econ_sum/ne
		
		possible = 0
		for student in cs:
			if student > econ_avg:
				if (cs_sum-student)/(ncs-1) > cs_avg:
					possible += 1
		print(possible)

if __name__ == "__main__":
	main()
