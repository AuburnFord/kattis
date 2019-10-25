def main():
	_ = input()
	ints = [int(x) for x in input().split()]
	# init the tuple
	tup = [1,0]
	while len(ints) !=0:
		buildup(ints.pop(), tup)		
	print("/".join([str(x) for x in tup]))

def buildup(num, lst):
	# swap the numerator and denominator
	swap(lst)
	# multiply the number by denom and add it to numerator
	lst[0] += num*lst[1]

def swap(lst):
	temp = lst[0]
	lst[0] = lst[1]
	lst[1] = temp

if __name__ == "__main__":
	main()
