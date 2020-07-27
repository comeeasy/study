'''
    모듈의 __name__  속성 
        : 실행 목적의 모듈
            -> __name__ <- __main__
        : 라이브러리 목적의 모듁
            -> __name_ <- 모듈명
'''

# ex) 
    if __name__ == "__main__" :
        print("plus(3, 2) => {0}".format(plus(3, 2)))
        print("minus(3, 2) => {0}".format(minus(3, 2))