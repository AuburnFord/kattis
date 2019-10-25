import string

def main():
	char, total = [int(x) for x in input().split()]
	alpha = dict(zip([ord(c)%32 for c in string.ascii_lowercase], string.ascii_lowercase))
	if char * 26 < total or char > total:
		print("impossible")
	else:
		avg = total//char
		rem = total%char
		out = ""
		for x in range(0,char):
			if rem != 0:
				out += alpha[avg+1]
				rem -= 1
			else:
				out += alpha[avg]
		print(out)

if __name__ == "__main__":
	main()
