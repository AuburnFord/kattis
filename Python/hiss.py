def main():
	word = raw_input()
	out = ""
	for x in range(len(word)-1):
		if word[x:x+2] == "ss":
			out = "hiss"
			break
	if out == "":
		out = "no hiss"
	print(out)

if __name__ == '__main__':
	main()
