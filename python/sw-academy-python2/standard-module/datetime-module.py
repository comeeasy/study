from datetime import datetime, timezone, timedelta

now = datetime.now()
print(now)

# 년, 월, 일, 시, 분, 초 의 포맷형식 지정
fmt = "%Y{0} %m{1} %d{2} %H{3} %M{4} %S{5}"

# datetime.now() 가 return 하는 객체를 str format으로 return하는 함수인거 같고
# 그 함수에 인자로 str 객체가 str.format()에 인자로 들어가는 형식인거 같고
# 그 형식에 format함수로 인자를 전달하는거 같음.. ㅠㅠ 
# * 가 들어가는 이유는 인자로 tuple을 전달하기 위함인듯
# 즉 Y뒤에 년 m뒤에 월, 이런식으로 들어가게 하기 위함
print(now.strftime(fmt).format(*"년월일시분초"))