def main():
	num = int(input())
	worlds = [int(x) for x in input().split()][::-1]
	kills = 0
	for x in range(1, num):
		if worlds[x-1] == 0:
			kills = -1
			break
		if worlds[x] >= worlds[x-1]:
			kills += worlds[x] - worlds[x-1] + 1
			worlds[x] = worlds[x-1] - 1
		
				
	if kills == -1:
		print(1)	
	else:
		print(kills)

if __name__ == "__main__":
	main()
