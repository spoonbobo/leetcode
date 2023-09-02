import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    products = products.set_index('product_id')
    res_df = pd.DataFrame(columns=["store", "price"])
    for store_i in range(1, 4):
        tmp_df = products[[f'store{store_i}']].rename(columns={f'store{store_i}' : 'price'})
        tmp_df['store'] = f'store{store_i}'
        res_df = pd.concat([res_df, tmp_df], axis=0)
    return res_df.reset_index().dropna(subset=['price']).rename(columns={"index": "product_id"})