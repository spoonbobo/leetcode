import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(report, id_vars=report.columns[0], value_vars=report.columns[1:]).rename(columns={"variable": "quarter", "value": "sales"})