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

def noneFindPattern(s, patternLength) :
    searchIdx = noneFindPattern.startIdx + patternLength
    cnt = 1

    if noneFindPattern.startIdx > len(s) - patternLength :
        noneFindPattern.startIdx = len(s)
        return s[noneFindPattern.startIdx:]
    else :
        while(searchIdx <= len(s) - patternLength) :
            if all(s[noneFindPattern.startIdx] == s[searchIdx + i] for i in range(patternLength)):
                cnt += 1
                searchIdx += patternLength
            else :
                noneFindPattern.startIdx += 1
                break
    
    if cnt > 1 : 
        return str(cnt) + s[noneFindPattern.startIdx:noneFindPattern.startIdx + patternLength]
    else :
        return s[noneFindPattern.startIdx:noneFindPattern.startIdx + patternLength]

s = "ababcdcdababcdcd"

ans = []
ansLen = []
for patternLength in range(1, len(s)) :
    noneFindPattern.startIdx = 0
    res = noneFindPattern(s, patternLength)
    ans.append(res)
    ansLen.append(len(res))
    
print(ans)
print(ans[ansLen.index(min(ansLen))])
