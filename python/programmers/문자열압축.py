def findPattern(s, patternLength, startIdx) :
    searchIdx = startIdx + patternLength
    cnt = 1

    # recurse escape condition
    if startIdx >= len(s) : 
        return ''
    elif startIdx > len(s) - patternLength :
        return s[startIdx:]
    else :
        while(searchIdx <=len(s) - patternLength) :
            if all(s[startIdx + i] == s[searchIdx + i] for i in range(patternLength)):
                cnt += 1
                searchIdx += patternLength
            else :
                break
    
        if cnt > 1 : 
            return str(cnt) + s[startIdx:startIdx + patternLength] + findPattern(s, patternLength, searchIdx)
        else :
            return s[startIdx:startIdx + patternLength] + findPattern(s, patternLength, startIdx + patternLength)

'''
def solution(s) :
    for patternLength in range(1, s // 2 + 1) :
        

    return answer
'''

s = "aaaaaaaaaaaaakkkkkkkkkkkkkkkkkkkk" * 100

ans = []
ansLen = []
for patternLength in range(1, len(s)) :
    res = findPattern(s, patternLength, 0)
    ans.append(res)
    ansLen.append(len(res))
    

print(ans[ansLen.index(min(ansLen))])
