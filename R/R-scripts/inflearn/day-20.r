# tapply function

class(mtcars)
str(mtcars)

new_data = mtcars[1:2]
new_data$cyl == 4
# get rows satisfying under condition
new_data[new_data$cyl==4,]
mpg_4 = new_data[new_data$cyl==4,]
mpg_6 = new_data[new_data$cyl==6,]
mpg_8 = new_data[new_data$cyl==8,]

# bind over three means as a row
cbind(mean(mpg_4$mpg), mean(mpg_6$mpg), mean(mpg_8$mpg))

# We're gonna use new_data$mpg, by new_data$cyl
# to get mean respectly
tapply(new_data$mpg, new_data$cyl, mean)
tapply(mtcars$gear, mtcars$cyl, mean)

# if str of data were list, should use lapply
# if str of data were dataframe, should use tapply