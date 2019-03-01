h = int(input())
if (h-5)%8==0 or h%8==0:
	print(h)
else:
	while (h-5)%8!=0 and h%8!=0:
		h+=1
	print(h)
