progresses = [93, 50, 55]	
speeds = [1, 30, 5]
answer = []

import math as m


'''
restDay = list(map(lambda  x, y: (100 - x) // y, progresses, speeds))
for i in range(1, len(restDay)) :
    if restDay[i] <= restDay[i-1] :
        answer[len(answer)-1] += 1
    else :
        answer.append(1)
'''

restDays = list(map(lambda  x, y: m.ceil((100-x) / y) , progresses, speeds))

print("ceil(7): {0}".format(m.ceil(7/1)))
print(restDays)

while(restDays) :
    firstReleaseDay = restDays.pop(0)
    cnt = 1

    while (restDays and restDays[0] <= firstReleaseDay) :
        restDays.pop(0)
        cnt += 1
    
    answer.append(cnt)
    
print(answer)



'''
def solution(progresses, speeds) :
    answer = [1]
    restDays = list(map(lambda  x, y: 100 - x // y, progresses, speeds))
    
    for i in range(1, len(restDays)) :
                   
        if restDays[i] <= restDays[i-1] :
            answer[len(answer)-1] += 1

        else :
            answer.append(1)
                   
    return answer

print(solution(progresses, speeds))
'''