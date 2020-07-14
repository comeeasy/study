# -*- coding: utf-8 -*-
# 다음의 결과와 같이 가상의 두 사람이 가위 바위 보 중 
# 하나를 내서 승패를 가르는 가위 바위 보 게임을 작성하십시오. 
# 이 때 ["가위", "바위", "보"] 리스트를 활용합니다.

rock_scissor_paper = ["가위", "바위", "보"]

man1 = input()
man2 = input()

if man1 == rock_scissor_paper[0] :
    if man2 == rock_scissor_paper[0] :
        print("Result : Draw")
    elif man2 == rock_scissor_paper[1] :
        print("Result : Man2 Win!")
    elif man2 == rock_scissor_paper[2] :
        print("Result : Man1 Win!")
elif man1 == rock_scissor_paper[1] :
    if man2 == rock_scissor_paper[1] :
        print("Result : Draw")
    elif man2 == rock_scissor_paper[2] :
        print("Result : Man2 Win!")
    elif man2 == rock_scissor_paper[0] :
        print("Result : Man1 Win!")
elif man1 == rock_scissor_paper[2] :
    if man2 == rock_scissor_paper[2] :
        print("Result : Draw")
    elif man2 == rock_scissor_paper[0] :
        print("Result : Man2 Win!")
    elif man2 == rock_scissor_paper[1] :
        print("Result : Man1 Win!")

