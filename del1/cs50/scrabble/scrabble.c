#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int get_winner(string s, char characters[], int numbers[]);

int main(void)
{
    char characters[26] =
    {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z'
    };

    int numbers[26] =
    {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };

    string question1 = get_string("Player 1: ");
    string question2 = get_string("Player 2: ");

    int score_player1 = get_winner(question1, characters, numbers);
    int score_player2 = get_winner(question2, characters, numbers);

    if (score_player1 < score_player2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score_player1 > score_player2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_winner(string s, char characters[], int numbers[])
{
    int total = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (characters[j] == toupper(s[i]))
            {
                total += numbers[j];
            }
        }
    }

    return total;
}

