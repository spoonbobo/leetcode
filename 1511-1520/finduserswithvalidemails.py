import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    users['validmail'] = users['mail'].str.match('^[A-Za-z]+[A-Za-z0-9\_\.\-]*@leetcode[.]com')
    users = users[users.validmail]
    users.drop('validmail', axis=1, inplace=True)
    return users