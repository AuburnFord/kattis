def main():
	n,p = [int(x) for x in raw_input().split()]
	items = list()
	for x in raw_input().split():
		items.append(int(x))
	items.sort()
	num = 1
	for x in range(1,len(items)):	
		if (items[x-1] + items[x]) > p:
			break
		num+=1
	print(num)
		
if __name__ == '__main__':
	main()
