def main():
	s, capacity, window = map(int, input().split())
	socks = [int(x) for x in input().split()]
	mem = {}
	for sock in socks:
		if sock not in mem:
			mem[sock] = 0
		mem[sock]+= 1
	socks = sorted(mem.keys(), reverse=True)
	i = 0
	cur_cap = capacity
	start = socks[-1]
	washers = 0
	while len(socks) != 0:
		cur = socks.pop()
		if cur-start > window:
			if cur_cap != capacity:
				washers+=1
				cur_cap = capacity
			start = cur
		if mem[cur] > cur_cap:
			mem[cur] -= cur_cap
			washers += 1
			washers += mem[cur]//capacity
			cur_cap = capacity - mem[cur]%capacity
			start = cur
		elif mem[cur] == cur_cap:
			washers += 1
			cur_cap = capacity
		else:
			cur_cap = cur_cap-mem[cur]
	if cur_cap != capacity:
		washers+= 1
	print(washers)
				
if __name__ == "__main__":
	main()
