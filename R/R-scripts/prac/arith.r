main = function() {
	args = commandArgs(trailingOnly=T)
	a = as.numeric(args[1])
	b = as.numeric(args[3])
	op = args[2]

	if(op == '+') {
		cat(a+b, sep='\n')
	} else if(op=='-') {
		cat(a-b, sep='\n')
	}
}

main()
	
