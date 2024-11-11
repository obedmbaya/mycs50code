//my cs50 solution code for a credit program
#include <cs50.h>
#include <stdio.h>

int checksum(long cardnum);
int cardlength(long cardnum);
string startingdigits(long cardnum, int cardcharlen);

int main(void)
{
    long cardnum = get_long("Number: ");

    // the below is to check a function that checks if the card is valid or not using Luhns algorithm
    int cardvalidity = checksum(cardnum);
    // the below function counts the number of characters in the card number
    int cardcharlen = cardlength(cardnum);
    // the below is a function that will determine what type of credit card the card is
    string final = startingdigits(cardnum, cardcharlen);
    if (cardvalidity == 1)
    {
        if (cardcharlen == 13 || cardcharlen == 15 || cardcharlen == 16)
        {
            printf("%s", final);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (cardvalidity == 0)
    {
        printf("INVALID\n");
    }
}

int checksum(long cardnum)
{

    long valueunsort = 0;
    // in valueunsort you are getting card number in descending order, one by one, check formula below
    int valuesort = 0;
    // this will be the single unit value of each position in card number(desceding order)
    long x = 10;
    // this is the modulos value
    int characters = 0;
    int sumofeven = 0;
    int sumofodd = 0;

    // string position;

    // do
    while (valueunsort != cardnum)
    {
        valueunsort = cardnum % x;
        valuesort = valueunsort / (x / 10);
        x *= 10;
        // printf("%i\n", valuesort);

        characters++;
        if ((characters % 2) == 0)
        {
            int mult = 10;
            // this is now applying Luhn's algorithm
            // printf("%i\n", valuesort);
            int valuesortmult = valuesort * 2;
            if (valuesortmult < 10)
            {
                sumofeven += valuesortmult;
            }
            else
            {
                for (int i = 0; i < 2; i++)
                {
                    int prodigit = valuesortmult;
                    int prodigitmod = prodigit % mult;
                    int prodigitunit = prodigitmod / (mult / 10);
                    sumofeven += prodigitunit;
                    mult *= 10;
                }
            }
        }

        else
        {
            sumofodd += valuesort;
        }
    }
    //while (valueunsort != cardnum);

    int total = sumofeven + sumofodd;

    if ((total % 10) == 0)
    {
        // position = "VALID";
        // return position;
        return 1;
    }
    else
    {
        // position = "INVALID";
        // return position;
        return 0;
    }
}

int cardlength(long cardnum)
{
    long valueunsort;
    // in valueunsort you are getting card number in descending order, one by one, check formula below
    int valuesort;
    // this will be the single unit value of each position in card number(desceding order)
    long x = 10;
    // this is the modulos value
    int characters = 0;
    // number of characters in the card number
    do
    {
        valueunsort = cardnum % x;
        valuesort = valueunsort / (x / 10);
        x *= 10;
        characters++;
    }
    while (valueunsort != cardnum);
    return characters;
}

string startingdigits(long cardnum, int cardcharlen)
{
    int firstdigit;
    int seconddigit;
    long modulovalue;
    // in the below, using if statements on the card length then seeing what type of card it is by first 2 digits or 1st digit
    if (cardcharlen == 16)
    {
        modulovalue = 10000000000000000;
        firstdigit = (cardnum % modulovalue) / (modulovalue / 10);
        seconddigit = (cardnum % (modulovalue / 10)) / (modulovalue / 100);
        if (firstdigit == 4)
        {
            return "VISA\n";
        }
        else if (firstdigit == 5)
        {
            if (seconddigit == 1 || seconddigit == 2 || seconddigit == 3 || seconddigit == 4 || seconddigit == 5)
            {
                return "MASTERCARD\n";
            }
            else
            {
                return "INVALID\n";
            }
        }
        else
        {
            return "INVALID\n";
        }
    }
    else if (cardcharlen == 13)
    {
        modulovalue = 10000000000000;
        firstdigit = (cardnum % modulovalue) / (modulovalue / 10);
        seconddigit = (cardnum % (modulovalue / 10)) / (modulovalue / 100);
        if (firstdigit == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else if (cardcharlen == 15)
    {
        modulovalue = 1000000000000000;
        firstdigit = (cardnum % modulovalue) / (modulovalue / 10);
        seconddigit = (cardnum % (modulovalue / 10)) / (modulovalue / 100);
        if (firstdigit == 3)
        {
            if (seconddigit == 4 || seconddigit == 7)
            {
                return "AMEX\n";
            }
            else
            {
                return "INVALID\n";
            }
        }
        else
        {
            return "INVALID\n";
        }
    }
    else
    {
        return "INVALID\n";
    }
}