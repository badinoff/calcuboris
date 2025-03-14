    #include <stdio.h>
    #include "version.h"
    #ifdef _WIN32
    #include <conio.h>
    #endif

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
        int c;

        printf("CalcuBoris v%d.%d.%02d -- Press Enter", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
        c = getchar();
        while (c != '\n' && c != EOF) c = getchar();

        do {
            int valid_input;
            do {
                printf("Please enter your first number: ");
                valid_input = scanf("%f", &x);
                while (getchar() != '\n');
            } while (valid_input != 1);
            
            do {
                printf("Please enter your second number: ");
                valid_input = scanf("%f", &y);
                while (getchar() != '\n');
            } while (valid_input != 1);
            
            show_menu();
            int op = get_operation();

            float result;
            switch (op) {
                case 1: result = add(x, y); printf("\nResult: %.5f\n", result); break;
                case 2: result = subtract(x, y); printf("\nResult: %.5f\n", result); break;
                case 3: result = multiply(x, y); printf("\nResult: %.5f\n", result); break;
                case 4: 
                    if (y == 0) {
                        printf("Division by 0 is not allowed\n");
                    } else {
                        result = divide(x, y); printf("\nResult: %.5f\n", result);
                    }
                    break;
                default: printf("That's not an option. Try again\n"); break;
            }

            printf("To exit press 'q', to perform another calculation, press Enter\n");
            while (getchar() != '\n');  // Flush
    #ifdef _WIN32
            c = _getch();  // Instant q on Windows
    #else
            c = getchar();  // q+Enter on Linux
    #endif
        } while (c != 'q');
        
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


