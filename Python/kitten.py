def main():
	start = input()
	branches = {}
	a = input()
	while a != "-1":
		a = a.split()
		for branch in a[1:]:
			branches[branch] = a[0]
		a = input()
	path = []
	while start in branches:
		path.append(start) 
		start = branches[start]
	path.append(start)
	print(" ".join(path))
	
if __name__ == "__main__":
	main()
