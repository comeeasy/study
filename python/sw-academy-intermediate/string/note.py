pattern = 'abc'
toFindString = 'xxxxxabdxxxxx'

T = int(input())
for i in range(1, T+1) :
    pattern, toFindString = input().split()
    
    findIndex = len(pattern) - 1

    while(findIndex < len(toFindString)) :
        # 패턴문과 조사할 문자열을 차례대로 비교한다
        for i in range(0, len(pattern)) :
            # 만약 다른 문자가 있다면 해당 인덱스를 저장하고
            # 패턴문을 마지막 인덱스 (len(pattern) - 1) 에서부터 i번쨰
            # 에 있는 인덱스부터 시작하여 해당 인덱스까지 몇 칸을 shift해야하는지
            # 조사

            if pattern[i] != toFindString[len(pattern) - 1 -i] :
                wrongChInToFindString = toFindString[len(pattern) - 1 -i]

                for j in range(i-1, -1, -1) :
                    if pattern[j] == wrongChInToFindString :
                        skip = i - j + 1
                skip = len(pattern) - i
                findIndex += skip

            # 만약 마지막 문자까지 동일하다면 해당 패턴을 찾은것
            if i == len(pattern) - 1 :
               print('1')
            # 그렇지 않다면 새로운 findIndex부터 시작
            else :
               break
    # while문을 빠져나왔다면 찾지 못한 것이므로
    # return 0
    print('0')