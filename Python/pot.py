def main():
	nums = int(input())
	total = 0
	for i in range(0,nums):
		num = input()
	#	if num[-1] == '0':
	#		total += int(num[0:-2]) ** int(num[-2:])
	#	else:
		total += int(num[0:-1]) ** int(num[-1:])
	print(total)

if __name__ == "__main__":
	main()
