#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // Asks user for their name
    string name = get_string("What is your name? ");
    // Prints hello, and the user's name
    printf("Hello, %s\n", name);
}

