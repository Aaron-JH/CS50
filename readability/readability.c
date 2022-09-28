#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //L = Number of letters per 100 words
    //S = number of sentences per 100 words

    int letters = 0;
    int words = 1;
    int sentences = 0;

    string txt = get_string("Text: ");

    //change i to counter, letters, words sentences

    //loop through text if a letter add 1 to counter
    for (int i = 0; i < strlen(txt); i++)
    {
        //using ascii to calculate between 65 & 90 for upper case OR beteween 97 & 122
        if ((txt[i] >= 97 && txt[i] <= 122) || (txt[i] >= 65 && txt[i] <= 90))
        {
            letters++;
        }
        //If there is a word check dictionary?
        //can count spaces +1
        else if (txt[i] == 32)
        {
            words++;
        }
        else if (txt[i] == 46 || txt[i] == 33 || txt[i] == 63)
        {
            sentences++;
        }


    }
    //has to be a float as division can cause decimal
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;


    //math.h included round() to have us round up
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");

    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }


}