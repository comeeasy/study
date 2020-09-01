talk = []

for i in range(1, 8) :
    file_name = 'talk{0}.txt'.format(i)   
    f = open(file_name, 'r')
    
    print(file_name)
    
    while True :
        line = f.readline().split()
        
        # 두번 이상 공백이 나오면 종료
        if len(line) == 0 :
            line = f.readline().split()
            if len(line) == 0 :
                line = f.readline().split()
                if len(line) == 0 :
                    line = f.readline().split()
                    if len(line) == 0 :
                        break
        
        if '귀염둥이' in line :
            for i in range(line.index('귀염둥이') + 1) :
                del line[0]
    
            for word in line :
                talk.append(word)
    
    f.close()
    
    
talkSet = set(talk)
talkDict = {word: talk.count(word) for word in talkSet}
talkTuple = list(talkDict.items())

talk = sorted(talkTuple, key=lambda x: x[1])
talk.reverse()

for word, count in talk :
    print("{0} : {1} 번".format(word, count))
    
    