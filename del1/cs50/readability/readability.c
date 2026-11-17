#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int words = 0;
    int letters = 0;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
    }

    // Last word never gets counted, as the text never ends with a space
    words += 1;

    const float L = (float) letters / words * 100;
    const float S = (float) sentences / words * 100;

    const float INDEX = (0.0588 * L) - (0.296 * S) - 15.8;

    if (INDEX >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (INDEX < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(INDEX));
    }
}
