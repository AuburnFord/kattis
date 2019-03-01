# Python 3 solution
def main():
	cases = int(input())
	toEval = "4"
	poss = dict()
	op = ['*','//','+','-']
	for i in range(4):
		toEval += " " + op[i] + " 4"
		for j in range(4):
			toEval += " " + op[j] + " 4"
			for k in range(4):	
				toEval += " " + op[k] + " 4"
				poss[eval(toEval)] = toEval
				if k == 1:
					toEval = toEval[:-5]
				else:
					toEval = toEval[:-4]
			if j == 1:
				toEval = toEval[:-5]
			else:
				toEval = toEval[:-4]
		if i == 1:
			toEval = toEval[:-5]
		else:
			toEval = toEval[:-4]
	for i in range(cases):
		desired = int(input())
		res = poss.get(desired, False)
		flag = False
		if res is not False:
			out = ""
			for i in range(len(res)):
				if res[i] == "/" and not flag:
					flag = True
				else:
					out += res[i]
					flag = False
			print(out," = ",desired)
		else:
			print("no solution")
	
if __name__ == "__main__":
	main()
