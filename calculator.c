#include <stdio.h>
#include "version.h"
//#include <cs50.h>

#define MIN 1
#define MAX 4


//math functions prototypes
float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

//existing prototypes
int get_operation(void);
void show_menu(void);

int main(void)
    {
        float x, y;

        printf("CalcuBoris v%d.%d.%02d -- Press Enter", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
        int c = getchar();
        while (c != '\n' && c != EOF) c = getchar();

        int valid_input;

        do
        {
            printf("Please enter your first number: ");
            valid_input = scanf("%f", & x);
            while (getchar() != '\n');
        } while (valid_input != 1);
        
        do
        {
            printf("Please enter your second number: ");
            valid_input = scanf("%f", & y);
            while (getchar() != '\n');
        } while (valid_input != 1);
        
show_menu();
        
        int op = get_operation();

        float result;
        switch (op)
        {
            case 1:
                result = add(x, y); // Returns float
                printf("\nResult: %.5f\n", result); // %f for float
            break;

            case 2:
                result = subtract(x, y); // Returns float
                printf("\nResult: %.5f\n", result); // %f for float
            break;

            case 3:
                result = multiply(x, y); // Returns float
                printf("\nResult: %.5f\n", result); // %f for float
            break;

            case 4:
                result = divide(x, y); // Returns float
                printf("\nResult: %.5f\n", result); // %f for float
            break;

        default:
            break;
        }
        return 0;
        
    }

int get_operation(void)
    {
        int op;
        int first_try = 1;
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
        
           scanf("%d", & op);
           first_try = 0;            
        } while (op < MIN || op > MAX);
        return op;
    }

void show_menu(void)
    {
        printf("Select your desired operation \n\n");
        printf("(1) Add (2) Subtract\n");
        printf("(3) Multiply (4) Divide\n\n");
    }

float add(float x, float y)
    {
        return x + y;
    }

float subtract(float x, float y)
    {
        return x - y;
    }

float multiply(float x, float y)
    {
        return x * y;
    }

float divide(float x, float y)
    {
        return x / y;
    }

    // Test v1.1.02
