def maxPriority(priorities) :
    if priorities :
        max = priorities[0][0]
        for p in priorities :
            if p[0] > max :
                max = p[0]
        return max
    else :
        return 0

priorities = [1, 1, 9, 1, 1, 1]
location = 0

# 0: priority, 1: index of paper
priorities = list(zip((priorities), range(len(priorities))))

cnt = 1
while(True) :

    print(priorities)

    # 가장 앞에 있는 priority가 가장 높다면 출력
    # max 함수는 tuple이 있을 때 [0] index의 값을 key 값으로 여김
    print("max priority: {0}".format(maxPriority(priorities)))
    if priorities[0][0] >= maxPriority(priorities) :

        printed = priorities.pop(0)
        print("printed: {0}\n".format(printed))

        if printed[1] == location :
            print(cnt)
            break
        else :
            cnt += 1
    # 그렇지 않다면 고백
    else :
        priorities.append(priorities.pop(0))
        
print(cnt)
    

