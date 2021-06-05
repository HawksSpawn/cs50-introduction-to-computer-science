// Report (via printf) whether it is a valid American Express, MasterCard,
// or Visa card number, per the definitions of each’s format

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validate_credit_card(long number);
int get_first_two_digits(long number);
int get_length(long number);
void print_credit_card_type(long number);

int main(void)
{
    long credit_card_number = get_long("Number: ");
    print_credit_card_type(credit_card_number);
}

// https://en.wikipedia.org/wiki/Luhn_algorithm
// Determine if a credit card number is (syntactically) valid as follows:
// 1. Multiply every other digit by 2, starting with the number’s second-to-last digit,
//    and then add those products’ digits together.
// 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
// 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0),
//    the number is valid!
int validate_credit_card(long number)
{
    long tmp = number;
    int sum = 0;

    while (tmp > 0)
    {
        // Retrieve and add the rightmost digit to the sum the digits
        // that weren't multiplied by 2
        sum += tmp % 10;
        // Remove the rightmost digit
        tmp /= 10;
        int mul_digit = (tmp % 10) * 2;
        // If the result of the multiplied number is two digits
        // sum the number's digits (i.e. 13 become 4)
        sum += mul_digit >= 10 ? (mul_digit % 10) + (mul_digit / 10) : mul_digit;
        // Remove the rightmost digit
        tmp /= 10;
    }

    return sum % 10;
}

// Returns the first-two digits of the number (i.e. 4589 -> 45)
int get_first_two_digits(long number)
{
    long tmp = number;
    // Reduces the number to the first-two digits
    while (tmp >= 100)
    {
        // Remove the rightmost digit
        tmp /= 10;
    }

    return tmp;
}

// Returns the length of the number (i.e. 14568 -> 5)
int get_length(long number)
{
    return log10(number) + 1;
}

// Print the credit card type according to the following format definitions:
// American Express uses 15-digit numbers, all American Express numbers start with 34 or 37;
// MasterCard uses 16-digit numbers, most MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit numbers, all Visa numbers start with 4
// Note: MasterCard also have some other potential starting numbers
// which we won’t concern ourselves with for this problem
void print_credit_card_type(long number)
{
    int is_valid = validate_credit_card(number);
    int start_number = get_first_two_digits(number);
    int len_number = get_length(number);

    // Check if the credit card number is (syntactically) valid,
    // if so, determine credit card type
    if (!is_valid && len_number == 15 && (start_number == 34 || start_number == 37))
    {
        printf("AMEX\n");
    }
    else if (!is_valid && len_number == 16 && (start_number >= 51 && start_number <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (!is_valid && (len_number == 13 || len_number == 16) && (start_number >= 40 && start_number < 50))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
