def main():
	roll = {}
	names = {} 
	while True:
		try:
			person = input().split()
		except:
			break
		roll.setdefault(person[1], [])
		roll[person[1]].append(person[0])
		names.setdefault(person[0], 0)
		names[person[0]] += 1
	out = ""
	for lname in sorted (roll):
		for fname in sorted (roll[lname]):
			out += fname
			if names[fname] != 1:
				out += " " + lname
			out += "\n"
	print(out)

if __name__ == "__main__":
	main()
