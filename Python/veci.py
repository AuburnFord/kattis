def main():
	nums = [int(x) for x in input()]
	
	if len(nums) == 1:
		print(0)
		return
	seen = set()
	seen.add(nums[-1])
	past = [nums[-1]]
	flag = True
	for x in range(len(nums)-2,-1,-1):
		seen.add(nums[x])
		past.append(nums[x])
		if nums[x] < nums[x+1]:
			n = 0
			for y in range(nums[x]+1,10):
				if y in seen:
					n = y
					break
#			print(n)
			past = sorted(past)	
#			print(past)
			nums = nums[:x] + [n]
			df = False
			for y in past:
				if not df and y == n:
					df = True
				else:
					nums.append(y)	
			flag = False
			break	
	if flag:
		print(0)
	else:
		nums = [str(x) for x in nums]
		print("".join(nums))

if __name__ == "__main__":
	main()
