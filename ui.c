#include <stdio.h>
#include "ui.h"
#include "version.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#define MIN 1
#define MAX 4
#define ENTER_KEY '\n'
#define ESC_KEY 27
#define WIN_ENTER_KEY 13
#define EXIT_CODE 1
#define CONTINUE_CODE 0

static int get_key(void) {
#ifdef _WIN32
    return _getch();  // Windows: raw key
#else
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;  // Linux: termios
#endif
}

static int check_key(int c, int is_init) {
    int platform_enter = 
#ifdef _WIN32
        WIN_ENTER_KEY;
#else
        ENTER_KEY;
#endif
    if (is_init) {
        if (c == ESC_KEY) return EXIT_CODE;
        if (c == platform_enter) return CONTINUE_CODE;
        return -1;  // Loop again
    } else {
        if (c == ESC_KEY) return CONTINUE_CODE;
        if (c == platform_enter) return EXIT_CODE;
        return -1;  // Loop again
    }
}

void show_menu(void) {
    printf("\nSelect your desired operation \n\n");
    printf("(1) Add (2) Subtract\n");
    printf("(3) Multiply (4) Divide\n\n");
}

int get_operation(void) {
    int op;
    int first_try = 1;
    int ret;
    do {
        if (first_try) printf("Please select desired operation: ");
        else printf("Invalid Input. Please enter 1-4: ");
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
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid input - numbers only\n");
            while (getchar() != '\n');
        }
    } while (ret != 1);
    return num;
}

int init_app(void) {
    printf("CalcuBoris v%d.%d.%02d - Press Enter to begin or Esc to exit\n", 
           VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    int c, result;
    do {
        c = get_key();
        result = check_key(c, 1);  // ESC exits
    } while (result == -1);
    return result;
}

int continue_calc(void) {
    printf("\nPress Enter to continue or Esc to exit\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    int c, result;
    do {
        c = get_key();
        result = check_key(c, 0);  // Enter continues
    } while (result == -1);
    return result;
}