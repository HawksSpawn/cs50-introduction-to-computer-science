// Print an adjacent pyramids of hashes separated by a "gap"

#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_pyramids(int height);

int main(void)
{
    int height = get_height("Height: ");
    print_pyramids(height);
}

// Prompt user for a positive integer between 1 and 8
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

// Print an adjacent pyramids of hashes of height 'height' separated by a "gap"
void print_pyramids(int height)
{
    // Print n rows
    for (int i = 0; i < height; i++)
    {
        // Formatting for right-alignment
        for (int j = 0; j < height - i - 1; j++)
        {
            printf("%s", " ");
        }

        // Print k hashes on each row of the first pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("%s", "#");
        }

        // Print a “gap” between adjacent pyramids equal to the width of two hashes
        printf("%s", "  ");

        // Print k hashes on each row of the second pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("%s", "#");
        }

        printf("%s", "\n");
    }
}
