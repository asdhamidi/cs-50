from cs50 import get_float
change = get_float("Change owed: ")  # Takes input from the user.

if change < 0:
    while change < 0:
        change = get_float("Change owed: ")  # If input is invalid, ask the user repeatedly to give a valid input.
        
cents = int(change * 100)  # Change the input in dollars into cents.

# Initialize the counter for various types of coins.
totalCoins = 0
coins25 = 0
coins10 = 0
coins5 = 0
coins1 = 0

# A nested if-else will determine how many of each coins are needed.
if cents % 25 == 0:
    coins25 = cents / 25
else:
    coins25 = int(cents / 25)
    cents = cents - (coins25 * 25)
    if cents % 10 == 0:
        coins10 = coins10 + (cents / 10)
    else:
        coins10 = int(cents / 10)
        cents = cents - (coins10 * 10)
        if cents % 5 == 0:
            coins5 = coins5 + (cents / 5)
        else:
            coins5 = int(cents / 5)
            cents = cents - (coins5 * 5)
            coins1 = cents

totalCoins = coins25 + coins10 + coins5 + coins1  # Add all the coins.
print(int(totalCoins))
