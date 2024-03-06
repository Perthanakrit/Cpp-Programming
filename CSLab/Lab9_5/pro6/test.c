#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, n = 5;
    char input[n];

    while (1)
    {
        printf("input> ");
        fgets(input, 5, stdin);
        if (input[0] == 'q')
            break;
        printf("input: %s", input);
    }

    return 0;
}
