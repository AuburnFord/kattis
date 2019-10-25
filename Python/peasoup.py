def main():
	restaurants = int(input())
	flag = True
	for _ in range(restaurants):
		items = int(input())
		menu = set()
		name = input()
		for i in range(items):
			menu.add(input())
		if "pea soup" in menu and "pancakes" in menu:
			print(name)
			flag = False
			break
	if flag:
		print("Anywhere is fine I guess")
			

if __name__ == "__main__":
	main()
