def main():
	name = input()	
	length = len(name)
	best = 100
	i = 0
	while i < length:
		newname = name+name[0:i][::-1]
		diff = i
		for x in range(len(newname)//2):
			if newname[x] != newname[len(newname)-1-x]:
				diff += 1
		best = min(best,diff)
		i+=1
	print(best)

if __name__ == "__main__":
	main()
