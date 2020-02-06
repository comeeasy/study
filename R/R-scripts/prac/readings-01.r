main = function() {
	args = commandArgs(trailing=T)
	filename = args[1]
	dat = read.csv(file=filename, header=F)
	mean_per_patient = apply(dat, 1, mean)
	cat(mean_per_patient, sep='\n')
}

main()
