def main():
	line = input()
	lower = 0
	white = 0
	upper = 0
	sym = 0
	for x in line:
		if ord(x) <= ord('Z') and ord(x) >= ord('A'):
			upper += 1
		elif ord(x) <= ord('z') and ord(x) >= ord('a'):
			lower += 1
		elif x == '_':
			white += 1
		else:
			sym += 1
	length = len(line)
	print(white/length)
	print(lower/length)
	print(upper/length)
	print(sym/length)
	
if __name__ == "__main__":
	main()
