'''
다음의 결과와 같이 회문(앞뒤 어느 쪽에서도 같은 단어, 말) 
여부를 판단하는 코드를 작성하십시오.
'''

string = input()
reverse_str = string[::-1]

print(string)
if reverse_str == string :
    print("입력하신 단어는 회문(Palindrome)입니다.")