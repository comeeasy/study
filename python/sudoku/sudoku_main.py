from sudoku import *

T = int(input())
for testCase in range(1, T+1) :
    # sdk 입력, 빈 list 인자로 줌
    sdk = sudoku([])
    for row in range(N) :
        ithRow = list(map(int, list(input())))
        # 스도쿠에 loc들을 삽입
        sdk.matrix.append([loc(row, column, ithRow[column]) for column in range(N)])

    print('=== testCase {0} ==='.format(testCase))
    print('---------- before -------------')
    sdk.print()

    get_candidate(sdk.matrix)
    for l in get_empty_loc(sdk.matrix) :
        print('({0}. {1}), len: {2}'.format(l.row, l.column, len(l.candidate)))

    #play_sdk(sdk.matrix)

    print('\n---------- after -------------')
    sdk.print()

