def main():
	num_plays = int(input())
	plays = [int(x) for x in input().split()]
	down = 1
	down_loc = 20
	place = 20
	safety = False
	td = False
	for x in plays:
		if td or safety:
			break
		if down == 5:
			break
		next_place = place + x
		if next_place <= 0:
			safety = True	
		if next_place >= 100:
			td = True	
		if next_place >= down_loc+10:
			down = 0
			down_loc = next_place
		place = next_place
		down += 1
	if td:
		print("Touchdown")
	elif safety:
		print("Safety")
	else:
		print("Nothing")

if __name__ == "__main__":
	main()
