#data Frame
name  = c('john', 'jaehee', 'juliet', 'james')
gender= c('f', 'f', 'f', 'm')
occup = c('athlete', 'doctor', 'ceo', 'analysist')
age   = c(40, 35, 43, 29)

# print data-frame
# name, age, gender, occup are column
	data.frame(name, age, gender, occup)

# 멤버라는 객체에 data.frame의 형태로 할당
	member = data.frame(name, age, gender, occup)

# print member
	member

# print name[3]
	name[3]

# print member[1]
	member[1]

# print if word matches with somwhow index's str
# print that column
	member$name
	member$
	  
# print member[name][1]
	member[1, 1]

	member[1, 3] = "m"
	member
