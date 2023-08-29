import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    if len(orders) == 0: 
        return pd.DataFrame(columns=['customer_number'])

    df = orders.groupby(['customer_number']).count().reset_index()
    max_order = max(df.order_number)
    return df[df['order_number'] == max_order][['customer_number']]