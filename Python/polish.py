def isNum(c):
	if len(c) > 1:
		return	True 
	if ord(c) > 0x39 or ord(c) < 0x30:
		return False
	return True

def isOp(c):
	if len(c) > 1:
		return False
	if ord(c) >= 0x30:
		return False
	return True

def main():
	count = 0
	while True:
		stack = []
		pop = []
		try:
			eq = input().split()
		except EOFError:
			break
		count += 1
		out = "Case " + str(count) + ":"
		for x in eq:
			stack.append(x)
		while stack:
			if isOp(stack[-1]):
				op = stack.pop()
				op1 = pop.pop()
				op2 = pop.pop()	
				if isNum(op1) and isNum(op2):
					pop.append(str(eval(op1+op+op2)))
				else:
					pop.append(op2)
					pop.append(op1)
					pop.append(op)
			else:
				pop.append(stack.pop())	
		while pop:
			out += " " + pop.pop()
		print(out)

if __name__ == "__main__":
	main()
