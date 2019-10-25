from collections import deque
def update(pos, temp):
	row = pos // 3
	col = pos % 3
	string = list(int(x) for x in temp) 
	for x in range(3):
		string[x+row*3] = ((string[x+row*3])-48+1)%4
		string[col+x*3] = ((string[col+x*3])-48+1)%4
	string[col+row*3] = ((string[col+row*3])-48+3)%4
	string = list(str(x) for x in string)
	return "".join(string)

def bfs(start):
	seen = set() 
	q = deque()	
	selections = list(range(9))
	q.append(start)
	q.append(None)
	count = 0 
	temp = 0
	while len(q) != 0:# and temp < 5:
		cur = q.popleft()
#		print(cur)
		if cur == None:
			if len(q) != 0: 
				count += 1
				q.append(None)
#			print(q)
			continue
		if cur in seen:
			continue
		seen.add(cur)
		if cur == '000000000':
			break
		for x in selections:	
			new = update(x,cur)
			q.append(new)
	if '000000000' not in seen:
		count = -1
	return count
	
		

def main():
	safe = "" 
	for x in range(3):
		safe += "".join(input().split())
	print(bfs(safe))
#	print(update(5,update(4,update(4,update(0,safe)))))

if __name__ == "__main__":
	main()
