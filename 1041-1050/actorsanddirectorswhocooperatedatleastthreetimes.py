import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    ct = Counter()
    coop = []
    for i, row in actor_director.iterrows():
        ct[(row['actor_id'], row['director_id'])] += 1
    for k, v in ct.items():
        if v >= 3: 
            coop.append(k)
    if len(coop) == 0:
        return pd.DataFrame(columns=["actor_id", "director_id"])
    return pd.DataFrame(coop, columns=["actor_id", "director_id"])