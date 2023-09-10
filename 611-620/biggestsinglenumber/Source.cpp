import pandas as pd

def biggest_single_number(my_numbers: pd.DataFrame)->pd.DataFrame:
filtered_df = my_numbers.drop_duplicates(subset = ['num'], keep = False)
if len(filtered_df) == 0 :
    return pd.DataFrame([None], columns = ['num'])

    return pd.DataFrame([filtered_df.num.max()], columns = ['num'])