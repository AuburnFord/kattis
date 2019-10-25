def main():
	h,w = map(int, input().split())
	pipes = []
	for x in range(h):
		pipes.append(input())
	req_right = [[False]*w for y in range(h)]
	req_down = [[False]*w for y in range(h)]

	flag = True

	for y in range(h):
		if not flag:
			break
		for x in range(w):
			c = pipes[y][x]
			r = req_right[y][x-1] if x > 0 else False
			d = req_down[y-1][x] if y > 0 else False	
			
			if c == 'A':
				if r or d:
					flag = False
					break
			elif c == 'B':
				if r == d:
					flag = False
					break
				if r:
					req_right[y][x] = True
				elif d:
					req_down[y][x] = True
			elif c == 'C':
				if r == d:
					if (not r) and (not d):
						req_right[y][x] = True
						req_down[y][x] = True
				elif r:
					req_down[y][x] = True
				elif d:
					req_right[y][x] = True
			elif c == 'D':
				if (not r) or (not d):
					flag = False
					break
				req_right[y][x] = True
				req_down[y][x] = True
	for x in range(w):
		if req_down[-1][x]:
			flag = False
	for y in range(h):
		if req_right[y][-1]:
			flag = False
#	print(req_right)
#	print(req_down)

	if flag:
		print('Possible')
	else:
		print('Impossible')
					
if __name__ == "__main__":
	main()
