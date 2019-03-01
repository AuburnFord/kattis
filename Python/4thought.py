# Python 2 solution
def main():
	cases = int(raw_input())
	toEval = "4"
	poss = dict()
	op = ['*','/','+','-']
	for i in range(4):
		toEval += " " + op[i] + " 4"
		for j in range(4):
			toEval += " " + op[j] + " 4"
			for k in range(4):	
				toEval += " " + op[k] + " 4"
				poss[eval(toEval)] = toEval
				toEval = toEval[:-4]
			toEval = toEval[:-4]
		toEval = toEval[:-4]
	for i in range(cases):
		desired = int(raw_input())
		res = poss.get(desired, False)
		if res is not False:
			print res,"=",desired
		else:
			print("no solution")
	
if __name__ == "__main__":
	main()
