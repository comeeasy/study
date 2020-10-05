priorities = [1, 1, 9, 1, 1, 1]
location = 0

priorities = list(enumerate(priorities))

cnt = 1
while True :

    print("priorities: ", priorities)

    if all(priorities[0][1] >= p[1] for p in priorities) :
        printed = priorities.pop(0)

        print("printed:", printed, end="\n\n")

        if printed[0] == location :
            break
        else :
            cnt += 1
    else :
        priorities.append(priorities.pop(0))

print(cnt)
