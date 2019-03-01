a = int(input())
while a!=0:
	bits = {} 
	for x in range(a):
		command = input().split()	
		if command[0] == "SET":
			bits[int(command[1])] = 1
		elif command[0] == "CLEAR":
			bits[int(command[1])] = 0
		elif command[0] == "OR":
			i = int(command[1])
			j = int(command[2])
			if i in bits.keys() and j in bits.keys():
				bits[i] = bits[i] | bits[j]		
			elif j in bits.keys() and bits[j] == 1:	
				bits[i] = 1
			elif i in bits.keys() and bits[i] == 0:
				del bits[i]	
		elif command[0] == "AND":
			i = int(command[1])
			j = int(command[2])
			if i in bits.keys() and j in bits.keys():
				bits[i] = bits[i] & bits[j]		
			elif j in bits.keys() and bits[j] == 0:	
				bits[i] = 0
			elif i in bits.keys() and bits[i] == 1:
				del bits[i]	
	for x in range(31,-1,-1):
		if x not in bits.keys():
			print("?", end="")
		else:
			print(bits[x],end="")
	print()
	a = int(input())
