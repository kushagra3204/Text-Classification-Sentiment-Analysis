import pandas as pd
import os

dirs = ["dataset/sentiment_analysis_evaluation_dataset","dataset/text_classification_for_sentiment_analysis"]

dataframes = []

for dirpath in dirs:
    for file in os.listdir(dirpath):
        print(file)
        df = pd.read_csv(os.path.join(dirpath,file), header=None, skiprows=1)  # Skip the first row
        dataframes.append(df)
        print(df.columns)

combined_df = pd.concat(dataframes, ignore_index=True)
combined_df.to_csv('combined.csv', index=False, header=["sentence","sentiment"])

# Preprocess Emotion Dataset - Combining Datasets
df1 = pd.read_csv('./combined_test.csv',header=None, skiprows=1)

df2 = pd.read_csv('./Emotion_classify_Data.csv',header=None, skiprows=1)

emotion_df = []
emotion_df.append(df1)
emotion_df.append(df2)
emotion_combine_df = pd.concat(emotion_df, ignore_index=True)
emotion_combine_df.to_csv('combine_emotion_df.csv',index=False,header=['sentence','emotion'])