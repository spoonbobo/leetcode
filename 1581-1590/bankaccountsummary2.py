import pandas as pd

def account_summary(users: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    inter = transactions.groupby("account")[['amount']].sum().reset_index()
    inter = inter[inter.amount > 10000].rename(columns={"amount": "BALANCE"})
    dct =  dict(zip(users.account, users.name))
    inter.account = inter.account.apply(lambda x: dct[x])
    return inter.rename(columns={"account": "name"})
    