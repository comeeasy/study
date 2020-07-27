# 서드파티 모듈 (외부 모듈)
#   : 다른 누군가에 의해 만들어져 배포되고 공유되는 모듈

# pip install 모듈명
# pip uninstall 모듈명

# pytz 모듈을 사용해보자
# 이미 깔려 있어서 그대로 사용

from datetime import datetime
from pytz import common_timezones, timezone, utc

# 타임존 정보 출력
for tz in list(common_timezones) :
    if tz.lower().find("paris") >= 0 :
        print(tz)
        
tz_utc = timezone(utc.zone)
tz_seoul = timezone("Asia/Seoul")
tz_pacific = timezone("US/Pacific")
tz_paris = timezone("Europe/Paris")

fmt = "%Y-%m-%d %H:%M:%S %Z%z"

# UTC 현재 시각
now_utc = datetime.now(tz_utc)
print(now_utc.strftime(fmt))

# Asia/Seoul 타임존
now_seoul = now_utc.astimezone(tz_seoul)
print(now_seoul.strftime(fmt))