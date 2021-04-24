from csv import reader, DictReader
from sys import argv

# Checks if command-line arguements are given or not.
if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

# Reading the dna sequence from the file.
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row

# Storing the dna sequence in a string for ease of checking.
dna = dnalist[0]
# Creating the dictionary to store the sequences for counting
sequences = {}

# Storing data from the database.
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

# Fill the dictionary with sequences.
for item in dnaSequences:
    sequences[item] = 1

# Looping over the dna to find repeated strings
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        # after having counted a sequence it skips at the end of it to avoid counting again
        while temp > 0:
            temp -= 1
            continue

        # If a sequence is found again, count starts.
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

            # Compares if count if more than the last recorded repetitions.
            if temp > tempMax:
                tempMax = temp

    # At last, we store the biggest count.
    sequences[key] += tempMax

# Comparing the repetitions with the database.
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # Checks for a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])  # Printing the found match 
            exit()

    print("No match")