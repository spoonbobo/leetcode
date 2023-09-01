import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    df = activities.drop_duplicates().groupby(['sell_date']).agg(['count', lambda x : ",".join(x)])
    df.columns = ['num_sold', 'products']
    df['products'] = df['products'].apply(lambda x: ",".join(sorted(x.split(','))))
    return df.reset_index()
