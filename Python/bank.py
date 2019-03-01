a,time = map(int, input().split())
c = {}
for x in range(a):
	m,t = map(int, input().split())
	if t not in c.keys():
		c[t]=[]
	c[t].append(m)
total = 0
for x in range(time,-1,-1):
	d = {}
	for y in range(x,time+1):
		if y in c.keys() and len(c[y]) > 0:
			d[y] = (max(c[y]))	
	maxM = -1
	index = -1
	for y in d.keys():
		if maxM < d[y]:
			maxM = d[y]	
			index = y
	if index >= 0:
		total+=d[index]
		c[index].remove(d[index])	
print(total)
	
