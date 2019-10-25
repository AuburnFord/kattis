#[mobitel]
#[0123456]

def rev(word, one, two):
	return word[one::-1] + word[two:one:-1] + word[:two:-1]
	
def main():
	string = input()
	pos_loc = len(string) - 1
	cur = "z"*len(string)
	for i in range(0, pos_loc-1):
		for j in range(i + 1, pos_loc):
			reved = rev(string,i,j)
			if reved < cur:
				cur = reved
	print(cur)
	
if __name__ == "__main__":
	main()
