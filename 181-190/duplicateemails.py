import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    return person[person.email.duplicated()].rename(columns={'email' : 'Email'})[['Email']].drop_duplicates()