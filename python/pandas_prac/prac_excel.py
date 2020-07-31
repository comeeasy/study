# -*- coding : utf-8 -*-
# prac_excel.py

import pandas as pd
import numpy as np
# import matplotlib.pyplot as plt

df = pd.read_excel('data.xlsx')
line_1 = df[df['노선명'] == '1호선']

# label
line_type = sorted(list(set(df['노선명'])))

# index
dates = []
for time_stamp in pd.date_range(start='2017-11', periods=19, freq='MS') :
    dates.append("{0}-{1:02}".format(time_stamp.year, time_stamp.month))

# values
'''
new_df = []
for row in df.loc[:] :
    for line in line_type :
        to_insert_line = []
        for row in df[df['노선명'] == line] :
            to_insert_line.append(row[3])
'''
            
#print(df)
print(df[df['노선명'] == '1호선']['승차총승객수'].to_numpy())
