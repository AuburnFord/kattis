def get_dist(locs,cap):
	tot_dist = 0
	to_fulfill = sorted(locs.keys())
	tcap = cap
	last = 0
	while to_fulfill:
		cur = to_fulfill.pop()
		if tcap != cap:
			if locs[cur] < tcap:
				tcap -= locs[cur]
				locs[cur] = 0
			else:
				locs[cur]-=tcap
				tcap = cap
		tot_dist += cur*2*(locs[cur]//cap)
		if locs[cur]%cap != 0:
			tot_dist+=cur*2
			tcap = cap - locs[cur]%cap
	return tot_dist

def main():
	addr,cap = map(int,input().split())
	n_addr = dict()
	p_addr = dict()
	for x in range(addr):
		loc,need = map(int,input().split())
		if loc < 0:
			n_addr[-1*loc] = need
		else:
			p_addr[loc] = need
	print(str(get_dist(n_addr,cap)+get_dist(p_addr,cap)))
		

if __name__ == "__main__":
	main()
