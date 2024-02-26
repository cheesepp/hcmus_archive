import pandas as pd

# Create a sample DataFrame
data = {'Name': ['Alice', 'Bob', 'Charlie'],
        'Age': [25, 30, 22],
        'Location': ['New York', 'Los Angeles', 'Chicago']}
df = pd.DataFrame(data)

# Convert the DataFrame to a dictionary using the 'records' format
dictionary_records = df.to_dict(orient='records')
print("Dictionary in 'records' format:")
print(dictionary_records)

# Convert the DataFrame to a dictionary using the 'list' format
dictionary_list = df.to_dict(orient='list')
print("\nDictionary in 'list' format:")
print(dictionary_list)

# Convert the DataFrame to a dictionary using the 'split' format
dictionary_split = df.to_dict(orient='split')
print("\nDictionary in 'split' format:")
print(dictionary_split)

# Convert the DataFrame to a dictionary using the 'series' format
dictionary_series = df.to_dict(orient='series')
print("\nDictionary in 'series' format:")
print(dictionary_series)

# Convert the DataFrame to a dictionary using the 'index' format
dictionary_index = df.to_dict(orient='index')
print("\nDictionary in 'index' format:")
print(dictionary_index)
