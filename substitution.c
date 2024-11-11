#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //get the length of the string
    int length = strlen(argv[1]);
    //this will store the count for how many alphabetical letters there are in the word
    int alphabet_count = 0;

    //if you have only one or more than 2 arguments its an error
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        //if the length is not exactly 26 character its an error
        if (length != 26)
        {
            printf("Key must contain 26 characters!");
            return 1;
        }

        else
        {
            //this will check if the key has alphabets or not by counting how many alphabeticals there are (26)
            for (int i = 0; i < 26; i++)
            {
                if (isalpha(argv[1][i]))
                {
                    alphabet_count += 1;
                }
                else
                {
                    alphabet_count += 0;
                }
            }

            //if alphabetical count is not 26 it means not all of the 26 characters are 26 alphabetical characters which is an error
            if (alphabet_count != 26)
            {
                printf("Your key have have 26 alphabets from a-z or A-Z, no other characters are allowed");
                return 1;
            }

            else
            {
                //if alphabet count is 26 now we will check if there are any identical letters
                int findings = 0;
                for (int i = 0; i < 26; i++)
                {
                    //we are using a nested for loop and the selected character will run through the whole KEY
                    char letter = argv[1][i];
                    if (isupper(letter))
                    {
                        for (int k = 0; k < 26; k++)
                        {
                            if (letter == toupper(argv[1][k]))
                            {
                                findings++;
                            }

                            else
                            {
                                findings += 0;
                            }
                        }
                    }

                    else
                    {
                        for (int m = 0; m < 26; m++)
                        {
                            if (letter == tolower(argv[1][m]))
                            {
                                findings++;
                            }

                            else
                            {
                                findings += 0;
                            }
                        }
                    }

                }
                // if findings is not equal to 26 then its an error
                if (findings != 26)
                {
                    printf("Your key must not have identical letters, don't use one letter more than once");
                    return 1;
                }
                // findings is 26 this means that each letter is unique and there are no duplicates
                else
                {
                    string input = get_string("plaintext: ");
                    int input_length = strlen(input);
                    //the string we will use to copy
                    string copy = input;
                    // we will replace the necessary value with the right letters
                    for (int j = 0; j < input_length; j++)
                    {
                        if (isalpha(input[j]))
                        {
                            if (islower((input[j])))
                            {
                                copy[j] = tolower(argv[1][input[j] - 97]);
                            }
                            else
                            {
                                copy[j] = toupper(argv[1][input[j] - 65]);
                            }
                        }

                        else
                        {
                            copy[j] = copy[j];
                        }
                    }
                    printf("ciphertext: %s\n", copy);
                    return 0;
                }
            }
        }
    }
}