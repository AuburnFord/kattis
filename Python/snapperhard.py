def main():
	n = int(input())
	out = ""
	for x in range(1,n+1):
		c,s = [int(x) for x in input().split()]
		s %= (2**c)
		out += "Case #" + str(x) + ": "
		if s == (2**c)-1:
			out += "ON\n"	
		else:
			out += "OFF\n"
	print(out)
			
if __name__ == "__main__":
	main()
