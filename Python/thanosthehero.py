def main():
	p = int(input())
	planets = [int(x) for x in input().split()]
	to_kill = 0
	for i in reversed(range(len(planets)-1)):
		if planets[i+1] == 0:
			to_kill = -1
			break
		else:
			if planets[i] >= planets[i+1]:
				to_kill += planets[i]-planets[i+1] + 1	
				planets[i] = planets[i+1]-1
	if to_kill == -1:
		print(1)
	else:
		print(to_kill)

if __name__ == "__main__":
	main()
