#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a number
bool is_numeric(string str);

int main(int argc, string argv[])
{
    // Check if the correct number of command line arguments is provided
    if (argc != 2 || !is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key to an integer
    int k = atoi(argv[1]);

    // Ensure the key is non-negative
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get the plaintext input from the user
    string text = get_string("Text: ");

    printf("ciphertext: ");

    // Iterate over each character in the plaintext
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            // For uppercase letters
            if (isupper(text[i]))
            {
                char cipher_char = ((text[i] - 'A' + k) % 26) + 'A';
                printf("%c", cipher_char);
            }
            // For lowercase letters
            else if (islower(text[i]))
            {
                char cipher_char = ((text[i] - 'a' + k) % 26) + 'a';
                printf("%c", cipher_char);
            }
        }
        else
        {
            // Print non-alphabetic characters as is
            printf("%c", text[i]);
        }
    }

    // Print a newline at the end
    printf("\n");
    return 0;
}

// Function to check if a string is a number
bool is_numeric(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
