# dev of r program dev programs
# that programs are packages

install.packages("ggvis")
library(ggvis)

# use attach function carefully
# == plot(mtcars$mpg, mtcars$wt)
plot(mpg, wt)

# pip line
# ~ is protocol
mtcars %>% ggvis(~mpg, ~wt) %>% layer_lines()
mtcars %>% ggvis(~mpg, ~wt) %>% layer_points()
mtcars %>% ggvis(~mpg, ~wt) %>% layer_bars()
mtcars %>% ggvis(~mpg, ~wt) %>% layer_smooths()

# in ggvis, we can draw graphs upon previous graph
# assigning variable as a parameter, ':' must be attached
# just right side of name of parameter just like bottom
mtcars %>% ggvis(~mpg, ~wt, fill:="red") %>% layer_points() %>% layer_smooths()

# we'd like to append a expression
# we want to fill with cyl variable
# ~ is protocol which must be attached to left side of name
mtcars %>% ggvis(~mpg, ~wt, fill=~cyl) %>% layer_points() %>% layer_smooths() 

# but cyl is recognized as numeric
# so we want to change str of cyl to integer
mtcars$cyl = factor(mtcars$cyl)

# you should check difference between these graphs

# add extra axis
mtcars %>% ggvis(~mpg, ~wt, fill=~cyl) %>% 
      layer_points() %>% layer_smooths() %>% 
      # add axises explicitly
      add_axis("x", title="MPG", values=c(10:35)) %>%
      # add axies tacitly
      add_axis("y", title="Weight", subdivide=4)










