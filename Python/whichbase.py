def main():
	cases = int(input())
	for x in range(cases):
		c, num = input().split()
		o,d,h = 0,0,0
		try:
			o = int(num,8)
		except:
			pass
		try:
			d = int(num)
		except:
			pass
		try:
			h = int(num,16)
		except:
			pass
		print(c,o,d,h)

if __name__ == "__main__":
	main()
