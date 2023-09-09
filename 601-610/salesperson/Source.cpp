import pandas as pd

def sales_person(sales_person: pd.DataFrame, company : pd.DataFrame, orders : pd.DataFrame)->pd.DataFrame:
red_id = None
for i, row in company.iterrows() :
    if row['name'] == 'RED' :
        red_id = row['com_id']
        break
        filtered_df = orders[orders.com_id == red_id]
        filtered_df['name'] = filtered_df['sales_id'].apply(lambda x : sales_person.loc[sales_person.sales_id == x]['name'].values[0])
        sales_person = sales_person[~(sales_person['name'].isin(filtered_df['name']))]
        return sales_person [['name']]