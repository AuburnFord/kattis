def find(parents,a):
	if parents[a] != a:
		parents[a] = find(parents,parents[a])
	return parents[a]

def union(parents, a,b):
	parents[find(parents,b)] = find(parents,a)

def main():
	height,length=map(int,input().split())
	vals = [] 
	for x in range(height):
		vals.append(input().strip())
	parents = list(range(height*length))
	for y in range(len(vals)):
		for x in range(len(vals[y])):
			if(x+1 < len(vals[y]) and (vals[y][x] == vals[y][x+1])):
				union(parents, x+y*length,(x+1+(y)*length))
			if(y+1 < len(vals) and (vals[y][x] == vals[y+1][x])):
				union(parents, x+y*length,(x+(y+1)*length))
	queries = int(input())
	for x in range(queries):
		a,b,x,y = map(int, input().split())
		a-=1
		b-=1
		x-=1
		y-=1
		if find(parents,y+x*length) == find(parents,b+a*length):
			print("binary" if vals[x][y] == '0' else "decimal")	
		else:
			print("neither")

if __name__ == "__main__":
	main()
