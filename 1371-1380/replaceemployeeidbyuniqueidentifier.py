import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(employees, employee_uni, on="id", how="left")
    df['id'] = df['unique_id']
    df.drop('unique_id', axis=1, inplace=True)
    return df.rename(columns={'id' : 'unique_id'})