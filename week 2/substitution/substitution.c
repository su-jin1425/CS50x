#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char lower_string[26];
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        lower_string[i] = tolower(argv[1][i]);
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (lower_string[i] == lower_string[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    int plain_length = strlen(plaintext);
    char ciphertext[plain_length + 1]; // Ensure there's enough space for the null terminator

    for (int i = 0; i < plain_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            int plain_index = plaintext[i] - 'A';
            ciphertext[i] = toupper(argv[1][plain_index]);
        }
        else if (islower(plaintext[i]))
        {
            int plain_index = plaintext[i] - 'a';
            ciphertext[i] = tolower(argv[1][plain_index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[plain_length] = '\0'; // Null-terminate the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
