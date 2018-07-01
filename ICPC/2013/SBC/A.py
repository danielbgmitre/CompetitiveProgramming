while 1:
	try:
		A, B, C = map(int, raw_input().split())
	except:
		break

	if (A == B != C):
		print "C"
	elif (A == C != B):
		print "B"
	elif (B == C != A):
		print "A"
	else:
		print "*"
