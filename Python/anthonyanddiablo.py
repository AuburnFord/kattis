from math import pi
def main():
	a,b = map(float, input().split())
	if b/2 >= a:
		print("Diablo is happy!")
	else:
		print("Need more materials!")

if __name__ == "__main__":
	main()
