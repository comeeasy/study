# -*- coding: utf-8 -*-

# 06-19.py
# 계산기 만들기

operand1, operator, operand2 = 0, "", 0

operand1 = int(input("첫 번째 숫자를 입력하세요. : "))
operator = input("연산자를 입력하세요. (+, -, *, /) : ")
operand2 = int(input("두 번째 숫자를 입력하세요. : "))

if operator == "+" :
    print("%d + %d = %d\n" % (operand1, operand2, operand1 + operand2))
elif operator == "-" :
    print("%d - %d = %d\n" % (operand1, operand2, operand1 - operand2))
elif operator == "*" :
    print("%d * %d = %d\n" % (operand1, operand2, operand1 * operand2)) 
elif operator == "/" :
    print("%d / %d = %.2f\n" % (operand1, operand2, operand1 / operand2))
elif operator == "**" :
    print("%d / %d = %d\n" % (operand1, operand2, operand1 ** operand2))
else :
    println("값이 올바르지 않잖아.. ")