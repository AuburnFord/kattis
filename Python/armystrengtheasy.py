from sys import stdin, stdout
def main():
	tests = int(stdin.readline().strip())
	for x in range(tests):
		stdin.readline()
		ng, nmg = map(int, stdin.readline().split())	
		garmy = sorted([int(x) for x in stdin.readline().split()],reverse = True)
		mgarmy= sorted([int(x) for x in stdin.readline().split()],reverse = True)
#		print(garmy)
#		print(mgarmy)
		while len(garmy) > 0 and len(mgarmy) > 0:
			if garmy[-1] < mgarmy[-1]:
				garmy.pop()	
			else:
				mgarmy.pop()
		if len(garmy) > 0:
			print('Godzilla')
		elif len(mgarmy) > 0:
			print('MechaGodzilla')
		else:
			print('uncertain')

if __name__ == "__main__":
	main()
