# <rolling 2 dices>

roll = 10000000
dice = ceiling(runif(roll)*6) + ceiling(runif(roll)*6)
my_table = table(dice)
barplot(my_table)

my_table[1]
my_table[5]

my_table[6]/my_table[1]
my_table[11]
