import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return views.loc[(views.author_id == views.viewer_id)].rename(columns={"viewer_id": "id"})[["id"]].sort_values(by=["id"]).drop_duplicates()