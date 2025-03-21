#include <stdio.h>
#include <math.h>  // Added for fabs()
#include "version.h"
#include "calc_ops.h"
#include "ui.h"
#ifdef _WIN32
#include <conio.h>
#endif

int main(void)
{
    float x, y;
    int c;

    printf("CalcuBoris v%d.%d.%02d -- Press Enter", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    c = getchar();
    while (c != '\n' && c != EOF) c = getchar();

    do {
        int ret;
        do {
            printf("Please enter your first number: ");
            ret = scanf("%f", &x);
            if (ret != 1) {
                printf("Invalid input - numbers only\n");
                while (getchar() != '\n');
            }
        } while (ret != 1);
        
        do {
            printf("Please enter your second number: ");
            ret = scanf("%f", &y);
            if (ret != 1) {
                printf("Invalid input - numbers only\n");
                while (getchar() != '\n');
            }
        } while (ret != 1);
        
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

        printf("To exit press 'q', to perform another calculation, press Enter\n");
        while (getchar() != '\n');
#ifdef _WIN32
        c = _getch();
#else
        c = getchar();
#endif
    } while (c != 'q');
    
    return 0;
}