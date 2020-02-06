mtcars

cars = rownames(mtcars)
nchar(cars)

# same with grep in linux
# value=F : return index; value=T: return value

# tolower function
# R is capital sensitive
grep("toyota", tolower(cars), value=T)

library(stringr)
cars

# str_count function in stringr library
# in given vectors, counting "char" and return its vector
str_count(tolower(cars), "t")
