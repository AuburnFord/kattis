def main():
	lines = []	
	max_len = 0
	while True:
		try:
			lines.append(input())
			if len(lines[-1]) > max_len:
				max_len = len(lines[-1])
		except:
			break
	val = 0
	for x in range(len(lines)-1):
		val += (max_len - len(lines[x]))**2
	print(val)

if __name__ == "__main__":
	main()
