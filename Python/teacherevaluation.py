def main():
	num, target = map(int, input().split())
	
	vals = [int(x) for x in input().split()]
	sum_v = sum(vals)
	
	if target == 0 or target == 100:
		if sum_v/len(vals) == target:
			print('0')
		else:
			print('impossible')
	else:
		avg = sum_v/len(vals)
		count = 0
		if avg == target:
			print('0')
		else:
			number = len(vals) + 1
			total = sum_v
			while True:	
				tar_total = target * number
				diff = tar_total - total
				count += 1
				if diff > 0:
					if diff <= 100:
						break	
					else:
						total += 100
						number += 1
				elif diff < 100:
					if diff >= -100:
						break
					else:
						number += 1	
				else:
					break
			print(count)

if __name__ == "__main__":
	main()
