def main():
	line = input()
	programs = {}
	repeat = set()
	seen = set()
	program = ""
	while not line == "0":
		if line == "1":
			for x in sorted(programs.items(), key=lambda x: (-len(x[1].difference(repeat)),x[0])):
				print(x[0], len(x[1].difference(repeat)))
			programs.clear()
			repeat.clear()	
			seen.clear()
		elif line[0].isupper():
			program = line	
			programs[program] = set()
		elif line[0].islower():
			if line in seen and not line in programs[program]: 
				repeat.add(line)
			programs[program].add(line)
			seen.add(line)
		line = input()
	
if __name__ == "__main__":
	main()
