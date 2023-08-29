import pandas as pd

def contain_diabetes(x):
    x = x.split()
    for diag in x:
        if diag.startswith('DIAB1'):
            return True
    return False

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    patients['positive'] = patients.conditions.apply(contain_diabetes)
    patients = patients[patients.positive]
    return patients.drop('positive', axis=1)