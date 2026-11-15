#include <cs50.h>
#include <stdio.h>

// Prototype
int get_height(void);

int main(void)
{
    int height;

    // get the user's input while it's less than or equal to 0 or more than 8
    do
    {
        height = get_height();
    }
    while (height <= 0 || height > 8);

    int h_spaces = height - 1; // we do this since the amount of spaces for the first row is height minus one

    for (int col = 0; col < height; col++)
    {

        for (int spaces = 0; spaces < h_spaces; spaces++) // for each row we print spaces
        {
            printf(" ");
        }

        for (int row = 0; row <= col; row++) // then left hashes
        {
            printf("#");
        }

        printf("  "); // then we add a gap

        for (int row = 0; row <= col; row++) // and then right hashes
        {
            printf("#");
        }

        printf("\n"); // make sure we add a new line
        h_spaces--;
    }
}

int get_height(void)
{
    int height = get_int("Height: ");
    return height;
}
