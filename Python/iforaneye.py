rel = {
	'at':'@',
	'and':'&',
	'one':'1',
	'won':'1',
	'to':'2',
	'too':'2',
	'two':'2',
	'for':'4',
	'four':'4',
	'bea':'b',
	'be':'b',
	'bee':'b',
	'sea':'c',
	'see':'c',
	'eye':'i',
	'oh':'o',
	'owe':'o',
	'are':'r',
	'you':'u',
	'why':'y'}

upper = {'b', 'c', 'i', 'o', 'r', 'u', 'y'}

def main():
	lines = int(input())
	out = []
	for i in range(lines):
		line = input()	
		print(convert(line))

def convert(line):
	out = ""
	x = 0
	while x < len(line):
		if x <= len(line) - 4:
			temp = line[x:x+4].lower()
			if temp in rel:
				conv = rel[temp]
				out += conv
				x += 4	
				continue
		if x <= len(line) - 3:
			temp = line[x:x+3].lower()
			if temp in rel:
				conv = rel[temp]
				if line[x].isupper() and conv in upper:
					conv=conv.upper()
				out += conv
				x += 3
				continue
		if x <= len(line) - 2:
			temp = line[x:x+2].lower()
			if temp in rel:
				conv = rel[temp]
				if line[x].isupper() and conv in upper:
					conv=conv.upper()
				out+= conv
				x+=2
				continue
		out+=line[x]
		x += 1
	return out
	
if __name__ == "__main__":
	main()
