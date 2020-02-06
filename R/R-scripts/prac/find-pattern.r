main = function() {
	args = commandArgs(trailingOnly=T)
	pattern = args[1]
	
	LIST = list.files(path="~/study/R/R-scripts/prac", pattern=pattern)
	for(f in LIST) {
		cat(f, sep='\n')
	}
}

main()
