# -*- coding: utf-8 -*-
# 다음의 결과와 같이 입력된 영어 알파벳 문자에 대해 
# 대소문자를 구분하는 코드를 작성하십시오.

ch = input()
int_ch = ord(ch)

if int_ch >= ord("a") and int_ch <= ord("z") :
    print("%s 는 소문자 입니다." % (str(ch)))
elif int_ch >= ord("A") and int_ch <= ord("Z") :
    print("%s 는 대문자 입니다." % (str(ch)))
