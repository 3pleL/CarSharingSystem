import pandas

###############################################################################
# Import CSV source file to analyze
###############################################################################
csv = pandas.read_csv('datafile.csv')
numbers_of_csv_entries = csv.index.stop
print("CSV Dataset Entries: "+ str(numbers_of_csv_entries))

#create empty working dataframe
df = pandas.DataFrame(columns=['ID','Distance'])

###############################################################################
# Scan different IDs in CSV, append them to dataframe
###############################################################################
for i in range(numbers_of_csv_entries):
    if not (csv['ID'][i] in df.values):
        df=df.append({'ID': csv['ID'][i], 'Distance': 0}, ignore_index=True)   

###############################################################################
# Calculate distance per ID
###############################################################################
numbers_of_users_in_csv = df.index.stop
for i_df in range(numbers_of_users_in_csv):
    for i_csv in range(numbers_of_csv_entries):
        if csv['ID'][i_csv] == df['ID'][i_df]:
            df['Distance'][i_df]+=csv['Distance'][i_csv]
            
###############################################################################
# Print results
###############################################################################
print(df)


