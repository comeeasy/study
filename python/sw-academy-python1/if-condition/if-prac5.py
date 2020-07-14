# -*- coding: utf-8 -*-

# 다음의 결과와 같이 입력된 문자가 대문자일 경우 소문자로, 소문자일 경우 대문자로 변경하고,
# 알파벳이 아닐 경우엔 그냥 출력하는 코드를 작성하십시오.
# 출력 시 아스키코드를 함께 출력합니다.

ch = input()
int_ch = int(ord(ch))
gap = int(ord('A')) - int(ord('a'))

if int_ch >= int(ord('a')) and int_ch <= int(ord('z')) :
    print("%s(ASCII: %d) => %s(ASCII: %d)" % (ch, int_ch, chr(int_ch + gap), int_ch + gap ))
elif int_ch >= int(ord('A')) and int_ch <= int(ord('Z')) :
    print("%s(ASCII: %d) => %s(ASCII: %d)" % (ch, int_ch, chr(int_ch - gap), int_ch - gap))
else :
    print(ch)

