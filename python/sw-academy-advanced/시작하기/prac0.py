# binary 는 formatting 하여 int형식으로 출력할 수 있다

T = int(input())

for i in range(1, T+1) :
    N, hex_num = input().split(' ')
    N = int(N)
    hex_num = int(hex_num, base=16)

    print('#{0}'.format(i), end=' ')
    for i in range(4*N-1, -1, -1) :
        print('1' if hex_num & (1 << i) else '0', end='')
    print()