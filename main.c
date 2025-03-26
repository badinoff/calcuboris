#include <stdio.h>
#include <math.h>
#include "calc_ops.h"
#include "ui.h"
#ifdef _WIN32
#endif

int main(void)
{
    if (init_app()) return 0; // ESC exits, Enter continues 

    do {
        float x = get_number("\nPlease enter your first number: ");
        float y = get_number("Please enter your second number: ");

        show_menu();
        int op = get_operation();

        float result;
        switch (op) {
            case 1: 
                result = add(x, y); 
                if (fabs(result - (int)result) < 0.000001) printf("\nResult: %.0f\n", result); 
                else printf("\nResult: %.5f\n", result); 
                break;
            case 2:
                result = subtract(x, y); 
                if (fabs(result - (int)result) < 0.000001) printf("\nResult: %.0f\n", result); 
                else printf("\nResult: %.5f\n", result); 
                break;
            case 3:
                result = multiply(x, y); 
                if (fabs(result - (int)result) < 0.000001) printf("\nResult: %.0f\n", result); 
                else printf("\nResult: %.5f\n", result); 
                break;
            case 4: 
                if (y == 0) {
                    printf("Division by 0 is not allowed\n");
                } else {
                    result = divide(x, y); 
                    if (fabs(result - (int)result) < 0.000001) printf("\nResult: %.0f\n", result); 
                    else printf("\nResult: %.5f\n", result); 
                }
                break;
            default: printf("That's not an option. Try again\n"); break;
        }

    } while (continue_calc());
    
    return 0;
}