import pandas as pd
import numpy as np

# Read input
features = pd.read_csv('input.csv')

correlation_matrix = np.corrcoef(features.values.T)

pd.DataFrame(correlation_matrix, columns=features.columns, index=features.columns).to_csv("./analysis.csv", sep="\t")
