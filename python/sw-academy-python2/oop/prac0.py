'''
다음의 결과와 같이 국어, 영어, 수학 점수를 입력받아 
합계를 구하는 객체지향 코드를 작성하십시오.
이 때 학생 클래스의 객체는 객체 생성 시 국어, 영어, 수학 
점수를 저장하며, 총점을 구하는 메서드를 제공합니다.
'''

class Average_cal :
    def __init__(self, kor, eng, math) :
        self.kor  = kor
        self.eng  = eng
        self.math = math
    
    def total(self) :
        return self.kor + self.eng + self.math
    
    def __repr__(self) : 
        return "국어, 영어, 수학의 총점: {0}".format(self.total())
    
ranks = tuple(map(int, input().split(", ")))
a1 = Average_cal(*ranks)
print(a1)    