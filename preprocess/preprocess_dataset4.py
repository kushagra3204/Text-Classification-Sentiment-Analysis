import pandas as pd

df = pd.read_csv('./dataset/combined_emotion.csv')

sampled_df = df.groupby('emotion').apply(lambda x: x.sample(n=20, random_state=42)).reset_index(drop=True)

sampled_df.to_csv('./dataset/sampled_emotion_test_dataset.csv', index=False)

print("Sampled dataset created with 70 sentences per emotion.")
