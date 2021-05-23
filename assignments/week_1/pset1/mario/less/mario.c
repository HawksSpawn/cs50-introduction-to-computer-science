// Print a right-aligned pyramid of hashes

#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_pyramid(int height);

int main(void)
{
    int height = get_height("Height: ");
    print_pyramid(height);
}

// Prompt user for positive integer between 1 and 8
int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);

    return n;
}

// Print a right-aligned pyramid of hashes of height 'height'
void print_pyramid(int height)
{
    // Print n rows
    for (int i = 0; i < height; i++)
    {
        // Formatting for right-alignment
        for (int j = 0; j < height - i - 1; j++)
        {
            printf("%s", " ");
        }

        // Print k hashes on each row
        for (int k = 0; k <= i; k++)
        {
            printf("%s", "#");
        }

        printf("%s", "\n");
    }
}
