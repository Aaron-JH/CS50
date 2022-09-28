#include <stdio.h>

float square(float sq)
{
    return(sq * sq);
}
int main(void)
{
    int x = 5;
    square(x);
    printf("%i\n", x);
}

void square(int n)
{
    n = n * n;
}



#include <stdio.h>
int main(void)
{
    int x = 5;
    square(x);
    printf("%i\n", x);
}

void square(int n)
{
    n = n * n;
}