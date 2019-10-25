def main():
	word = input()
	best = "z"*len(word)
	a = 0
	b = a + 1
	while a < len(word)-2:
		while b < len(word)-1:
			new_word = word[a::-1] + word[b:a:-1] + word[-1:b:-1]
			if new_word < best:
				best = new_word
			b += 1
		a += 1
		b = a + 1
	print(best)	

if __name__ == "__main__":
	main()
