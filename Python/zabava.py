from sys import stdin,stdout

def dig_sum(n):
	return (n*(n+1))//2

def main():
	students, dorms, moves = map(int, stdin.readline().split())
	residents = [(0,0,0) for x in range(dorms)]
	for _ in range(students):
		cur = int(stdin.readline())-1
# tuples immutable
		residents[cur][1] = residents[cur][1] + 1
	for _ in range(dorms):
		residents[_][0] = dig_sum(residents[_][1])
	residents.sort()
	print(residents)

if __name__ == "__main__":
	main()
