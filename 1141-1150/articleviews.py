# seems can be optimized

import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return views.loc[(views.author_id == views.viewer_id)].sort_values(by=["view_date"])[["viewer_id"]].drop_duplicates().rename(columns={"viewer_id": "id"}).sort_values(by=["id"])