def validNum(c):
	if c <= 0x39 and c >= 0x30 or c >= 0x41 and c <= 0x46:
		return True	
	return False

def main():
	while True:
		try:#how
			line = str(input())
		except:
			break
		i = 1
		while i < len(line):
			if line[i-1:i+1].upper() == "0X":
				j = i + 1
				while j < len(line) and j - i <= 8 and validNum(ord(line[j].upper())):
					j+=1
				print(line[i-1:j], " ", eval(line[i-1:j]))
			i+=1
	
if __name__ == '__main__':
	main()
