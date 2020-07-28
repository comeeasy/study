'''
다음의 결과와 같이 임의의 URL 주소를 입력받아 
protocol, host, other(path, querystring, ...)로
구분하는 프로그램을 작성하십시오.

http://www.example.com/test?p=1&q=2

protocol: http
host: www.example.com
others: test?p=1&q=2
'''

url = input()
protocol = (url.split(':'))[0]
url = url.replace(protocol + "://", "")

host   = (url.split('/'))[0]
others = (url.split('/'))[1]

print("protocol:", protocol, sep=' ')
print("host:", host, sep=' ')
print("others:", others, sep=' ')