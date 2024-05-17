#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt the user for height until a valid height (1 to 8 inclusive) is entered
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print the leading spaces for the left pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print the hashes for the left pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print the gap between the pyramids
        printf("  ");

        // Print the hashes for the right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}

