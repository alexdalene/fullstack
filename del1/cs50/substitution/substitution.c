#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int validate_key(string key, int N);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution [key]\n");
        return 1;
    }

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = argv[1];

    const int N = 26;

    // Exit program if wrong length
    if (strlen(key) != strlen(alpha))
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Make alphabetical characters uppercase
    for (int i = 0; i < N; i++)
    {
        if (isalpha(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }

    // Validate both the original alphabet and provided key
    if (validate_key(alpha, N) == 1 || validate_key(key, N) == 1)
    {
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    string ciphertext = plaintext;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Skip if not alphabetical character
        if (!(isalpha(plaintext[i])))
        {
            continue;
        }

        for (int j = 0; j < N; j++)
        {
            if (toupper(plaintext[i]) == alpha[j])
            {
                // Check if lower or upper alphabetical
                if (islower(plaintext[i]))
                {
                    ciphertext[i] = tolower(key[j]);
                    break;
                }
                else
                {
                    ciphertext[i] = key[j];
                    break;
                }
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}

int validate_key(string key, int N)
{
    for (int i = 0; i < N; i++)
    {
        // Exit program if not alphabetical
        if (!(isalpha(key[i])))
        {
            printf("Key must be only alphabetical characters\n");
            return 1;
        }

        for (int j = i + 1; j < N; j++)
        {
            // Exit program if each letter appears more than once
            if (key[i] == key[j])
            {
                printf("Key must contain each letter exactly once\n");
                return 1;
            }
        }
    }

    return 0;
}
