main = function() {
	args = commandArgs(trailingOnly=T)

	for(filename in args) {
		dat = read.csv(file=filename, header=F)
		mean_per_patient = apply(dat, 1, mean)
		cat(mean_per_patient, sep="\n")
	}
}

main()
