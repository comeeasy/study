'''
단어를 콤마(,)로 구분해 입력하면 그 단어들을 사전순으로 정렬해 출력하는 프로그램을 작성하시시오.
'''

words = input().split(', ')
print(', '.join(sorted(words)))