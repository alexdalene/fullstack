#include <cs50.h>
#include <stdio.h>
#include <string.h>

int first_batch(long n);
int second_batch(long n);
int get_card_length(long n);
string get_card_vendor(long n);
int check_card(int length, string vendor);

int main(void)
{
    long number = get_long("Number: ");

    int validate = (first_batch(number) + second_batch(number)) % 10;

    int card_length = get_card_length(number);

    string card_vendor = get_card_vendor(number);

    int is_valid = check_card(card_length, card_vendor);

    if (validate == 0 && is_valid == 1)
    {
        printf("%s\n", card_vendor);
    }
    else
    {
        printf("INVALID\n");
    }
}

int first_batch(long n)
{
    n = n / 10;
    int remainder;
    int total = 0;

    do
    {
        remainder = n % 10;

        remainder = remainder * 2;

        if (remainder >= 10)
        {
            int new = remainder / 10;

            remainder = remainder % 10;

            total = total + new + remainder;
        }
        else
        {
            total = total + remainder;
        }

        n = n / 10;
        n = n / 10;
    }
    while (n);

    return total;
}

int second_batch(long n)
{
    int remainder;
    int total = 0;

    do
    {
        remainder = n % 10;

        total = total + remainder;

        n = n / 10;
        n = n / 10;
    }
    while (n);

    return total;
}

int get_card_length(long n)
{
    int remainder;
    int card_length = 0;

    do
    {
        remainder = n % 10;

        remainder = (remainder * 0) + 1;

        card_length = card_length + remainder;

        n = n / 10;
    }
    while (n);

    return card_length;
}

string get_card_vendor(long n)
{
    int remainder;
    string card_vendor = "";

    do
    {
        if (n > 10 && n < 100)
        {
            if (n == 34 || n == 37)
            {
                card_vendor = "AMEX";
                break;
            }
            else if (n == 51 || n == 52 || n == 53 || n == 54 || n == 55)
            {
                card_vendor = "MASTERCARD";
                break;
            }
        }

        n = n / 10;

        if (n == 4)
        {
            card_vendor = "VISA";
            break;
        }
    }
    while (n);

    return card_vendor;
}

int check_card(int length, string vendor)
{
    int valid = 0;

    if (strcmp(vendor, "VISA") == 0 && (length == 13 || length == 16))
    {
        valid = 1;
    }
    else if (strcmp(vendor, "AMEX") == 0 && length == 15)
    {
        valid = 1;
    }
    else if (strcmp(vendor, "MASTERCARD") == 0 && length == 16)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    return valid;
}
