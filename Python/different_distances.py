def main():
	while(True):
		inp = raw_input()
		if inp == "0":
			break
		x1,y1,x2,y2,p = [float(x) for x in inp.split()]
		dist = ((abs(x1-x2))**p + (abs(y1-y2))**p)**(1/p)
		print(dist)

if __name__ == '__main__':
	main()
