#include<stdio.h>
#include<cs50.h>
#include<math.h>

int sum_alg(int alg);
int luhn_algorithm(long number);
int count_digits(long card);
int check_initial(long card, int digits);

int main(void) 
{
    long number = get_long("Number: ");
    int total = luhn_algorithm(number);
    int digits = count_digits(number);
    int initial = check_initial(number, digits);
    if (total % 10 == 0)
    {
        // check if is a american express
        
        if (digits == 15 && (initial == 34 || initial == 37)) 
        {
            printf("AMEX\n");
        } 
        // check if is a mastercard
        else if (digits == 16 && (initial >= 51 && initial <= 55)) 
        {
            printf("MASTERCARD\n");
        } 
        // check if is visa
        else if ((digits == 13 || digits == 16) && initial / 10 == 4) 
        {
            printf("VISA\n");   
        }
        // invalid option
        else 
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}

// main algoritmh
int luhn_algorithm(long number)
{
    int total = 0, resto1, resto2;
    do 
    {
        resto1 = (number % 100) / 10;
        resto2 = (number % 10);
        total += sum_alg(resto1 * 2) + resto2;
        number /= 100;
    }
    while (number > 0);
    
    return total;
}

// sum alg in base 10
int sum_alg(int alg) 
{
    if (alg / 10 == 0) 
    {
        return alg;    
    }
    else 
    {
        return alg % 10 + alg / 10;
    }
}

// count the digits of the card
int count_digits(long card)
{
    int count = 0;
    while (card > 0)
    {
        card /= 10;
        count += 1;
    }
    return count;
}

// check initial number of the card
int check_initial(long card, int digits) 
{
    return card / pow(10, digits - 2);
}


