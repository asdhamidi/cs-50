from cs50 import get_string

text = get_string("Text : ")  # Takes the input text from the user.

# Initializing counters for letters, words, and sentences.
letter = 0.0
words = 0.0
sentences = 0.0

# Loops over each character in the string.
# Checks if its a letter, a sentence terminator, or a blank space.
for c in text:
    if c.isalpha():
        letter = letter + 1
    elif c == "." or c == "!" or c == "?":
        sentences = sentences + 1
    elif c.isspace():
        words = words + 1
        
words = words + 1

# Calculates average of letters and sentences.
avglet = (letter / words) * 100.0
avgsent = (sentences / words) * 100.0

# Calculates the index.
index = 0.0588 * avglet - 0.296 * avgsent - 15.8
index = round(index)  # Rounding up the index.
level = int(index)

# Display of the final result.
if index < 1:
    print("Before Grade 1")
elif index <= 16 and index >= 1:
    print(f"Grade {level}")
else:
    print("Grade 16+")