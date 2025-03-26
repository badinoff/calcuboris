#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "ui.h"
#include "version.h"

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

float get_number(const char *prompt) {  //float input prompts (from main.c) and collection  
    float num;
    int ret;
    do {
        printf("%s", prompt);
        ret = scanf("%f", &num); 
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid input - numbers only\n");
            while (getchar() != '\n');
        }
    } while (ret != 1);
    return num;
}

int init_app(void) {
    struct termios oldt, newt;
    int c;

    printf("CalcuBoris v%d.%d.%02d - Press Enter to begin or Esc to exit\n", 
           VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

    tcgetattr(STDIN_FILENO, &oldt);         // Save current settings
    newt = oldt;                            // Copy for tweaking
    newt.c_lflag &= ~(ICANON | ECHO);       // No buffer, no echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply it

    do {
        c = getchar();                      // One key at a time
    } while (c != '\n' && c != 27);         // Enter or ESC

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Reset terminal

    return (c == 27) ? 1 : 0;               // 1 = ESC (exit), 0 = Enter (start)
}

int continue_calc(void)
{
    struct termios oldt, newt;
    int c;

    printf("\nPress Enter to continue or Esc to exit\n");
    while (getchar() != '\n' && getchar() != EOF); // Flush leftovers
    tcgetattr(STDIN_FILENO, &oldt);         // Save current settings
    newt = oldt;                            // Copy for tweaking
    newt.c_lflag &= ~(ICANON | ECHO);        // Buffer, echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply it

    do {
        
    c = getchar(); 
        
    } while (c != '\n' && c != 27);         // Enter or ESC

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Reset terminal

    return (c == 27) ? 0 : 1;               // 1 = Enter (continue), 0 = ESC (exit)
}