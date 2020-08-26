# sudoku.py

'''
note.ipynb
에 프로그램에 대한 설명을 기술함
'''

import sys
sys.stdin = open('sample.txt', 'r')

# 위치의 클래스를 정의한다.
class loc() :
    def __init__(self, row, column, number) :
        self.row = row
        self.column = column
        self.number = number
        # 빈 후보의 리스트를 할당한다.
        self.candidate = []
        
    def __repr__(self) :
        return '{0}'.format(self.number)

# 해당 loc이 위치하는 3*3 n square 의 숫자들의 list return
def three_by_three_matrix(sudoku, row, column) :
    startRowIdx    = (row // 3) * 3
    startColumnIdx = (column // 3) * 3
    
    return [sudoku[row][column] for row in range(startRowIdx, startRowIdx+3)
                           for column in range(startColumnIdx, startColumnIdx+3)]

# 해당 loc의 column, row의 list들을 return
def column_list(sudoku, column) :
    return [sudoku[row][column] for row in range(N)]

def row_list(sudoku, row) :
    return [sudoku[row][column] for column in range(N)]

# sudoku에서 빈 loc들의 list를 
def get_empty_loc(sudoku)

# 스도쿠의 크기      
N = 9

# sudoku 입력
sudoku = []
for row in range(N) :
    ithRow = list(map(int, list(input())))
    # 스도쿠에 loc들을 삽입
    sudoku.append([loc(row, column, ithRow[column]) for column in range(N)])
 
# print input sudoku    
for row in range(N) :
    print(sudoku[row])

'''
print()
print(three_by_three_matrix(sudoku, 3, 3), end='\n\n')
print(column_list(sudoku, 3), end='\n\n')
print(row_list(sudoku, 5), end='\n\n')
'''


