#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //getting the input for height
        height = get_int("Enter the height:\n");
    }
    //input height requirement between 1 and 8
    while (height < 1 || height > 8);
    if ((height >= 1) && (height <= 8))
    {
        // for loops for size of pyriamid
        int i, space;
        for (i = 1; i <= height; i++)
        {
            for (space = 0; space < (height - i); space++)
            {
                printf(" ");
            }
            for (space = 1; space <= i; space++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}