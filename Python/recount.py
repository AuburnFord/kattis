from sys import stdin,stdout
def main():
	names = dict()
	a = stdin.readline().strip()
	while a != "***":
		if a not in names:
			names[a] = 0
		names[a] += 1
		a = stdin.readline().strip()
	high_name = "Runoff!"
	high = -1
	for name in names:
		if names[name] > high:
			high = names[name]
			high_name = name
		elif names[name] == high:
			high_name = "Runoff!"
	print(high_name)

if __name__ == "__main__":
	main()
