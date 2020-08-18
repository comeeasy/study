'''
두 개의 문자열 str1과 str2가 주어진다. 문자열 str2 안에 str1과 일치하는 
부분이 있는지 찾는 프로그램을 만드시오.
예를 들어 두 개의 문자열이 다음과 같이 주어질 때, 첫 문자열이 두번째에 존재하면 1,
 존재하지 않으면 0을 출력한다.

ABC
ZZZZZABCZZZZZ

두번째 문자열에 첫번째 문자열과 일치하는 부분이 있으므로 1을 출력.

ABC
ZZZZAZBCZZZZZ

문자열이 일치하지 않으므로 0을 출력.


[입력]

첫 줄에 테스트 케이스 개수 T가 주어진다.  (1≤T≤50)
다음 줄부터 테스트 케이스 별로 길이가 N인 문자열 str1과 길이가 M인 str2가 각각 다른 줄에 주어집니다. (5≤N≤100, 10≤M≤1000, N≤M)

[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다
'''

# 비교할 문자열과 패턴을 비교하는데 패턴이 먼저 비교할 문자열보다
# 작아야할 것이며,
# 작다면 패턴문자열의 가장 마지막 인덱스부터 차례로 비교한다.
# 패턴의 첫번째 문자까지 같으면 패턴을 찾은 것이다.
# 그러나 다른 문자가 발생할 것이고, 발생했다면 주어진 패턴 안에서
# 해당 문자를 찾는다 이 문자는 여러개가 있을 수 있을것이고
# 해당 문자의 인덱스를 저장하여 차례로 비교한다.

# ex indeex     indeieindeex
#               indeex
# 먼저는 오른쪽에 있는 e에 맞추고, 다음에 왼쪽에 있는 e에 맞춰봄
#                indeex
#                 indeex
#                     indeex    -> 패턴 찾음

# 여기서 skip할 index를 list에 저장하여 차례대로 이동시키며 조사해야한다.
# skip할 index와 패턴을 조사할 마지막 인덱스와의 합이 조사할 문자열의 길이보다
# 크다면 return 0
# 찾으면 return 1
def boyer_moore_algo(pattern, toFindString) :
    findIndex = len(pattern) - 1
    
    while(findIndex < len(toFindString)) :
        # 패턴문과 조사할 문자열을 차례대로 비교한다
        
        #print('findIndex: {0}'.format(findIndex))
        
        for i in range(0, len(pattern)) :
            # 만약 다른 문자가 있다면 해당 인덱스를 저장하고
            # 패턴문을 마지막 인덱스 (len(pattern) - 1) 에서부터 i번쨰
            # 에 있는 인덱스부터 시작하여 해당 인덱스까지 몇 칸을 shift해야하는지
            # 조사

            #print('.' * (findIndex - i), '*', sep='')
            #print(toFindString)
            #print(' ' * (findIndex - len(pattern) + 1) ,pattern, sep='')

            # 만약 다른 문자라면!
            if pattern[len(pattern)-1-i] != toFindString[findIndex - i] :
                wrongChInToFindString = toFindString[findIndex - i]

                #print('pattern: {0}'.format(pattern[len(pattern)-1-i]))
                #print('toFindString: {0}'.format(toFindString[findIndex-i]))
                #print("wrong ch : {0}".format(wrongChInToFindString))
                
                # 패턴안에 존재하는지?
                skip = 0
                for j in range(len(pattern)-1-i, -1, -1) :
                    
                    #print('pattern[j: {0}] : {1}'.format(j, pattern[j]))
                    # 존재한다면 적절한 위치로 shift 하도록 findIndex 재조정
                    if pattern[j] == wrongChInToFindString :
                        break
                    skip += 1
                    
                     
                #print('skip: {0}'.format(skip))   
                findIndex += skip
                break

            # 만약 마지막 문자까지 동일하다면 해당 패턴을 찾은것
            if i == len(pattern) - 1 :
                return 1
            # 그렇지 않다면 새로운 findIndex부터 시작
        
        #print()
    # while문을 빠져나왔다면 찾지 못한 것이므로
    return 0


# sample_input0.txt 에 입력 자료가 있음
import sys
sys.stdin = open('sample_input0.txt', 'r')

T = int(input())
for i in range(1,T+1) :
    # 찾을 패턴
    pattern = input()
    # 주어진 string에서 패턴을 찾아야함
    toFindString  = input()
    
    # 보어 - 무이어 알고리즘을 이용할거고 이를 함수로 정의
    answer = boyer_moore_algo(pattern, toFindString)
    print("#{0} {1}".format(i, answer))