from sys import stdin,stdout
def main():
	obst, num = map(int, stdin.readline().split())
	got = set()
	for x in range(num):
		got.add(int(stdin.readline().strip()))
	out = []
	for x in range(obst):
		if x not in got:
			out.append(str(x))
	stdout.write("\n".join(out))
	stdout.write(" ".join(["\nMario got", str(len(got)), "of the dangerous obstacles.\n"]))

if __name__ == "__main__":
	main()
