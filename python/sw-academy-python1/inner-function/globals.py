# globals() 
# 현재의 전역 심볼 테이블을 보여주는 딕셔너리를 return
# 전역 변수와 함수, 클래스의 정보 포함

# locals()
# 현재의 지역 심볼 테이블을 보여주는 딕셔너리를 return
# 지역 변수와 중첩 함수의 정보 포함

class my_class :
    pass

def test_fn(param) :
    def inner_fn() :
        pass
    val1 = 5
    val2 = 8
    for item in locals().items() :
        print("\t{0} : {1}".format(item[0], item[1]))
        
value1 = 10
value2 = 20

obj1 = my_class()
g = dict(globals())

print("globals()")
for item in g.items() :
    print("\t{0} : {1}".format(item[0], item[1]))
    
print("local()")
test_fn(10)