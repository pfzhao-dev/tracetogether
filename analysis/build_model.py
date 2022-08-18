import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn_porter import Porter

# Read input
features = pd.read_csv('input.csv')
features = features.dropna()

# Features and Target column
labels = np.array(features['within_3m'])
features = features.drop('within_3m', axis=1)
features = features.drop('receiver_id', axis=1)
features = features.drop('sender_id', axis=1)

feature_list = list(features.columns)
features = np.array(features)
print(feature_list)

train_features, test_features, train_labels, test_labels = train_test_split(features, labels, test_size=0.25, random_state=42)

print('Training Features Shape:', train_features.shape)
print('Training Labels Shape:', train_labels.shape)
print('Testing Features Shape:', test_features.shape)
print('Testing Labels Shape:', test_labels.shape)

dt = DecisionTreeClassifier(random_state=42)

dt.fit(train_features, train_labels)

predictions = dt.predict(test_features)

correct_predictions = 0
total_predictions = len(test_labels)

for i in range(len(test_labels)):
    if predictions[i] == test_labels[i]:
        correct_predictions += 1

print('Correct Predictions:', correct_predictions)
print('Total Predictions:', total_predictions)
print('Correct Percentage:', correct_predictions / total_predictions)

# Export:
porter = Porter(dt, language='c')
output = porter.export(embed_data=True)
f = open("model.c", "w")
f.write(output)
f.close()
