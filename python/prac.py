def solution(arr):
    leng = len(arr)
    
    answer = []
    f, e = 0, 1         # from, end
    while(True) :

        print(answer)

        # 탈출 조건 마지막 숫자는 e가 마지막 인덱스를 넘었다면 append
        if e >= leng-1 :
            answer.append(arr[f])
            break
        
        # 만약 f와 e가 같다면 e를 증가
        if arr[f] == arr[e] :
            e += 1
        # 그렇지 않다면 새로운 숫자가 나온 것이고 먼저 이전의 숫자를 append하고
        # 다음 숫자에 대해서 진행
        else :
            answer.append(arr[f])
            f = e
            e += 1
            
    return answer

    arr = [1, 2, 3, 4, 5]
    answer = solution(arr)
    print(answer)