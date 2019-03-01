def calcTime(time):
	a = time.split(":")
	return int(a[0])*3600 + int(a[1])*60 + int(a[2])

def main():
	speed = 0
	pastTraveled = 0
	lastUpdate = 0
	while True:
		try:
			a = input().split()
		except EOFError:
			break
		if len(a)==2:
			newTime = calcTime(a[0])
			pastTraveled += (newTime - lastUpdate)*speed
			lastUpdate = newTime
			speed = int(a[1])/3600
		else:
			print(a[0] + " %.2f km" % (pastTraveled + speed*(calcTime(a[0])-lastUpdate)))
		
if __name__ == "__main__":
	main()	
