def main():
	h,w,r = map(int,input().split())
	grid = []
	for x in range(h):
		grid.append(input())
	max_x = 0
	max_y = 0
	max_hit = 0
	for y in range(h-r+1):
		for x in range(w-r+1):
			count = 0			
			for y_o in range(1,r-1):
				for x_o in range(1,r-1):
					if grid[y+y_o][x+x_o] == '*':
						count+=1
			if count > max_hit:
				max_hit = count
				max_x = x
				max_y = y	
	out = ""
	for y in range(h):
		for x in range(w):
			if (x==max_x and y == max_y) or(x==max_x and y == max_y+r-1) or (y== max_y and x == max_x+r-1) or (x==max_x+r-1 and y == max_y+r-1):
				out+='+'
			elif (x==max_x or x==max_x+r-1) and (y > max_y and y < max_y+r-1):
				out+='|'
			elif (y==max_y or y==max_y+r-1) and (x > max_x and x < max_x+r-1):
				out+='-'
			else:
				out+=grid[y][x]
		out+='\n'
	print(max_hit)
	print(out[:-1])

if __name__ == "__main__":
	main()
