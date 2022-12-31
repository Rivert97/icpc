def main():
	dictionary = {}
	try:
		while True:
			line = raw_input()
			key = ''.join(sorted(line))

			if not dictionary.has_key(key):
				dictionary[key] = " %-12s" %(line,)
			else:
				length = len(dictionary[key])
				if length != 0 and length % 65 == 0:
					dictionary[key] += "\n             "
				dictionary[key] += " %-12s" %(line,)
	except EOFError:
		pass

	for k in sorted(dictionary.keys()):
		print "%-12s:%s" %(k, dictionary[k])

if __name__ == "__main__":
	main()
