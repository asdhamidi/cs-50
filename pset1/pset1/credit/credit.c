#include <stdio.h>
#include <cs50.h>

string cardType(long num)
{
    int firstNumber, i = 1;
    do
    {
        firstNumber = num%10;
        num = num / 10;
        i++;
    }
    while(num / 10 != 0);
    
    if(firstNumber == 3 && i == 15)
    {
        return "AMEX";
    }
    else if(firstNumber == 4 && (i == 13 || i == 16))
    {
        return "VISA";
    }
    else if(firstNumber == 5 && i == 16)
    {
        return "MASTERCARD";
    }
    else
    {
        return "INVALID";
    }
}

int main(void)
{
    long number = get_long("Number : ");
    string type = cardType(number);
    int sum = 0, sum1 = 0, sum2 = 0, i = 1;
    
    do
    {
        int rem = 0;
        rem = number%10;
        if(i % 2 == 0)
        {
            rem = rem * 2;
            if(rem / 10 == 0)
            {
                sum2 = sum2 + rem;
            }
            else
            {
                do
                {
                    int digit = 0;
                    digit = rem % 10;
                    sum2 = sum2 + digit;
                    rem = rem / 10;
                }
                while(rem != 0);
            }
        }
        else
        {
            sum1 = sum1 + rem;
        }
        number = number / 10;
        i++;
    }
    while(number != 0);
    
    sum = sum1 + sum2;
    
    if(sum % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

