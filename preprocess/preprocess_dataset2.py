import pandas as pd
from multiprocessing import Pool
from tqdm import tqdm

def process_line(line):
    parts = line.strip().split(' ', 1)
    if len(parts) < 2:
        return None
    label, sentence = parts
    
    sentiment = 'positive' if label == '__label__1' else 'negative'
    return {'sentence': sentence, 'sentiment': sentiment}

def main():
    input_file = 'dataset/train.ft.txt'
    output_file = 'dataset/train_tp.csv'

    with open(input_file, 'r',encoding='utf-8') as file:
        total_lines = sum(1 for line in file)

    with open(input_file, 'r',encoding='utf-8') as file, Pool() as pool:
        results = list(tqdm(pool.imap(process_line, file), total=total_lines, desc="Processing lines"))

    results = [r for r in results if r is not None]

    df = pd.DataFrame(results)
    df.to_csv(output_file, index=False)

if __name__ == '__main__':
    main()
