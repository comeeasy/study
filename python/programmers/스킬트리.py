skill = "CBD"
skill_trees = ["BACDE", "CBADF", "AECB", "BDA", "AAA", "BDA"]
answer = 0

def isCorrect(skill, skill_tree) :
    priority = 0
    for sk in skill_tree :
        if sk in skill :
            if sk == skill[priority] :
                priority += 1
            else :
                return 0
    return 1

for skill_tree in skill_trees :
    answer += isCorrect(skill, skill_tree)
    
print(answer)
        

