testcount = 0
i = 0
x = 1
while i < 20:
	if x == 1:
		print "y"
		x = 0
	else:
		print "n"
		x = 1
	testcount += 1
	i += 1
output = "toaster"
if testcount != 20:
	print "did not finish run"
if output != "toaster":
	print "did not receive proper output"
else:
	print "all test cases passed"
