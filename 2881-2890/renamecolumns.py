import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns=dict(zip(students.columns, ["student_id", "first_name", "last_name", "age_in_years"])))