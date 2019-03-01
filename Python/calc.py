#from __future__ import division

while True:
	try:
		print("%.2f" % eval(input()))#for py2 use raw_input() and uncomment import
	except EOFError:
		break
