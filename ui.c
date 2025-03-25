#include <stdio.h>
#include "ui.h"

#define MIN 1
#define MAX 4

void show_menu(void)
{
    printf("\nSelect your desired operation \n\n");
    printf("(1) Add (2) Subtract\n");
    printf("(3) Multiply (4) Divide\n\n");
}

int get_operation(void)
{
    int op;
    int first_try = 1;
    int ret;
    do
    {
        if (first_try)
        {
            printf("Please select desired operation: ");
        }
        else
        {
            printf("Invalid Input. Please enter 1-4: ");
        }
        
        ret = scanf("%d", &op);
        if (ret != 1) {
            printf("Invalid input - numbers only\n");
            while (getchar() != '\n');
        }
        first_try = 0;
    } while (op < MIN || op > MAX || ret != 1);
    return op;
}

float get_number(const char *prompt) {
    float num;
    int ret;
    do {
        printf("%s", prompt);
        ret = scanf("%f", &num); 
        if (ret != 1) {
            printf("Invalid input - numbers only\n");
            while (getchar() != '\n');
        }
    } while (ret != 1);
    return num;
}