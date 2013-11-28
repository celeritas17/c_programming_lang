from sys import argv

def squeeze(s1, s2):
	counts = {}
	for i in s1:
		counts[i] = 0;
	for i in s2:
		counts[i] += 1

	result = ""
	for i in s1:
		if counts[i] == 0:
			result += i

	return result


if len(argv) < 3:
	print "Usage python <script>.py <word to squeeze> <squeeze word>\n"
else:
	script, s1, s2 = argv
	print squeeze(s1, s2)
