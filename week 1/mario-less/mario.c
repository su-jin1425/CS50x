#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt user for a height between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row of the pyramid
    for (int row = 1; row <= height; row++)
    {
        // Calculate the number of spaces for the current row
        int num_spaces = height - row;

        // Print the required number of spaces
        for (int i = 0; i < num_spaces; i++)
        {
            printf(" ");
        }

        // Print the required number of hashes for the current row
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        // Move to the next line after printing all spaces and hashes for the current row
        printf("\n");
    }
}

