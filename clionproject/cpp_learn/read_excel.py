import sys
import pandas as pd


path = sys.argv[1]
model = sys.argv[2]
sheet_index = int(sys.argv[3])

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.width', 1000)
pd.set_option('display.max_colwidth', 30)

if model == "r":
    df = pd.read_excel(path, sheet_name=sheet_index, engine='openpyxl')
    print(df)

# df = read_excel(r'C:\Users\曾立\Desktop\机电实验\电机堵转数据.xlsx')
# print(df)
