#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //is this needed?


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Check that they all chars are digits
        int j = 0;
        string key = argv[1];
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (isdigit(key[i]))
            {
                j++;
            }
        }
        // Convert according to the key typed
        if (j == strlen(key))
        {

            int k = atoi(argv[1]);
            //ask user for string
            string txt = get_string("Plaintext: ");
            printf("Ciphertext: ");

            for (int l = 0, m = strlen(txt); l < m; l++)
            {
                // Converts plaintext to cipher
                if islower(txt[l])
                {
                    //including wraparound by using ascii numbers
                    printf("%c", (((txt[l] - 97) + k) % 26) + 97);
                }
                else if isupper(txt[l])
                {
                    //same as above but for lowercase
                    printf("%c", (((txt[l] - 65) + k) % 26) + 65);
                }
                else
                {
                    printf("%c", txt[l]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        //if number not pressed after typing
        printf("Please type './caesar' and provide the key in a numerical value.\n");
        return 1;
    }
}