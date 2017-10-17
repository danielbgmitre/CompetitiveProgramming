

while 1:
	try:
		A, B = map(int, raw_input().split())
	except:
		break
		
	mergu = map(int, raw_input().split())
	mergu.sort()
	p = 0
	for i in range(1, A+1):
		if (p < len(mergu) and i == mergu[p]):
			p += 1
		else:
			print i,
	if len(mergu) == A:
		print "*"
	else:
		print ""
			

