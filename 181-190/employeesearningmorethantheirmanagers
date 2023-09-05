import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    # self-join
    managers = employee.copy()
    managers = managers.drop('id', axis=1).rename(columns={'managerId': 'id'})
    merged = pd.merge( managers, employee, on='id')
    return merged[merged.salary_x > merged.salary_y][['name_x']].rename(columns={'name_x': "Employee"})