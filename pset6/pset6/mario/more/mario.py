from cs50 import get_int

height = get_int("Height: ")  # Takes the input of the user.

if height > 8 or height < 1:
    while (height > 8) or (height < 1):  # If the input is greater than 8 or less than 1, a loop will run until required input is given.
        height = get_int("Height: ") 
    
height = height
m = height
for i in range(height):  # For printing rows
    for l in range(0, m-1):  # For printing blanks
        print(" ", end="")
    
    for j in range(0, i+1):  # For printing first pyramid of hashes.
        print("#", end="")
        
    print(" ", end=" ")  # For putting spaces in between
        
    for k in range(0, i+1):  # For printing the second pyramid of hashes.
        print("#", end="")
    print("")
    m = m - 1