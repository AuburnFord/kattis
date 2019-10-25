import math

def main():
	num = input()
	fl = len(num)	
	if fl < 4:
		n = int(num)
		print(1 if n == 1 else 2 if n == 2 else 3 if n == 6 else 4 if n == 24 else 5 if n == 120 else 6)
	else:
		mult = 7
		numl = 4 * math.log10(2) + 2 * math.log10(3) + math.log10(5)
		while numl <= fl:
			numl += math.log10(mult)
			mult+=1
		print(mult-1)
			
			
if __name__ == "__main__":
	main()
