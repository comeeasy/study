string = input()

def is_palindrome(string) :
    for i in range(0, len(string)) :
        if string[i] != string[-1-i] :
            return False
    return True
        
if is_palindrome(string) :
    print("입력하신 단어는 회문(Palindrome)입니다.")
else :
    print("입력하신 단어는 회문(Palindrome)이 아닙니다.")