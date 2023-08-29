import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    return teacher.drop_duplicates(subset=['teacher_id', 'subject_id']).groupby(['teacher_id'])[['subject_id']].count().reset_index().rename(columns={"subject_id": "cnt"})