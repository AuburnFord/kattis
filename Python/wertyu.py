def main():
	d = {'W':'Q','E':'W','R':'E','T':'R','Y':'T','U':'Y','I':'U','O':'I','P':'O','[':'P',']':'[','\\':']','1':'`','2':'1','3':'2','4':'3','5':'4','6':'5','7':'6','8':'7','9':'8','0':'9','-':'0','=':'-','S':'A','D':'S','F':'D','G':'F','H':'G','J':'H','K':'J','L':'K',';':'L','\'':';','X':'Z','C':'X','V':'C','B':'V','N':'B','M':'N',',':'M','.':',','/':'.'}
	while(True):
		out = ""
		try:
			line = input()		
		except:
			break
		for x in range(len(line)):
			if line[x] in d:
				out+=d[line[x]]	
			else:
				out+=line[x]
		print(out)
		

if __name__ == "__main__":
	main()
