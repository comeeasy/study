import pandas as pd

df = pd.read_csv('mall_business_info.csv', delimiter='|')

address_list = ['도로명주소', '건물명', '신우편번호', '동정보', '층정보', '호정보']
total_columns = ['주소', '상호명', '상권업종중분류명']
goyang = df[df.loc[:, '도로명주소'].str.contains('경기도 고양시')]

goyang1 = goyang[['상호명','상권업종중분류명'] + address_list]]
goyang1.head