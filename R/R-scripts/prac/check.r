main = function() {
	args = commandArgs(trailingOnly=T)
	
	ref_file = read.csv(args[1], header=F)
	ref_row = dim(ref_file)[1]
	ref_col = dim(ref_file)[2]
	for(filename in args[-1]) {
		f = read.csv(filename, header=F)

		nrow = (dim(filename))[1]
		ncol = (dim(filename))[2]

		if(ref_row != nrow || ref_col != ncol ) {
			cat("Not all the data files have same dimensions.")
		}	
	}
}
main()
