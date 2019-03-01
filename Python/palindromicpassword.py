def getCloser(num):
	front = int(num[:3])
	up = int(str(front+1) + str(front+1)[::-1])
	current = int(str(front) + str(front)[::-1])
	down = int(str(front-1) + str(front-1)[::-1])
	if abs(down-int(num)) > abs(up-int(num)):
		if abs(current-int(num)) > abs(up-int(num)):
			return up	
		else:
			return current
	elif abs(down-int(num)) > abs(current-int(num)):
		return current
	else:
		return down

def isPal(num):
	if num[:3] == num[-1:-4:-1]:
		return True
	return False

def main():
	cases = int(input())
	for x in range(cases):
		num = input()
		if isPal(num):
			print(num)
		else:
			print(getCloser(num))

if __name__ == "__main__":
	main()
