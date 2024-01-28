/******************************************************************/
/*   Author     : Mazen Nagy Mansour   */
/*   Description : IMT Bank System                                */
/*   Date        : 26 Jan 2024                                     */
/*   Version     : V1.1                                          */
/******************************************************************/
#include <stdlib.h>
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// #include <windows.h>
#define atoa(x) #x
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_MAC
// macOS includes go here
#include <CoreFoundation/CoreFoundation.h>
#include <pthread.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
// Add other necessary includes based on your needs
#endif
#endif

#define STD_OUTPUT_HANDLE STDOUT_FILENO
#define STD_INPUT_HANDLE STDIN_FILENO
#define STD_ERROR_HANDLE STDERR_FILENO

typedef struct bank_account
{
    char *full_name; // must enter at least first four names
    char *address;
    char national_id[15]; // national id must consist of 14 digit numbers
    int age;
    int bank_acc_id;
    char guardian_nat_id[15]; // guardian national id must consist of 14 digits numbers
    char status[11];
    float balance;
    char password[9]; // Random Password will be generated for each account during creation of it
} Bank_Account;
typedef struct
{
    short X;
    short Y;
} COORD;
/****************************************/
/*         Functions Prototypes         */
/****************************************/

void gotoxy(int x, int y);
void displayMainMenu();
void displayAdminMainMenu();
void displayClientMainMenu();
// int getLatestBankID();
// void saveLatestBankID(int id);
int bankIDGenerator();
char *randomPasswordGenerator(int N);
int no_of_spaces(char *name);
int isNumber(char s[]);
Bank_Account createNewAccount();
Bank_Account openExistingAccount();
void saveAccount(Bank_Account acc);

/****************************************/
/*            Main Function             */
/****************************************/
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
int main()
{
    int window_choice, admin_choice, client_choice, choice;
    Bank_Account acc;

    home:
    clear_screen();
    displayMainMenu();
    scanf("%d", &window_choice);

    main_menu:
    clear_screen();
    gotoxy(55, 0);
    printf("IMT Bank System");
    gotoxy(55, 1);
    printf("---------------");

    switch (window_choice)
    {
        case 1:
            displayAdminMainMenu();
            scanf("%d", &admin_choice);

            clear_screen();
            gotoxy(55, 0);
            printf("IMT Bank System");
            gotoxy(55, 1);
            printf("---------------");

            switch (admin_choice)
            {
                case 1:
                    acc = createNewAccount();
                    saveAccount(acc);
                    printf("\n\nPress any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                case 2:
                    printf("Press any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                default:
                    goto home;
            }

            break;

        case 2:
            displayClientMainMenu();
            scanf("%d", &client_choice);

            switch (client_choice)
            {
                case 1:
                    printf("Press any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                case 2:
                    printf("Press any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                case 3:
                    printf("Press any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                case 4:
                    printf("Press any key to return to the main menu...");
                    getch();
                    goto main_menu;
                    break;

                default:
                    goto home;
            }
            break;

        default:
            exit(0);
    }
}

// int main_func()
//{
//     int option,choice;
//     Bank_Account acc;
//     char filename[15] , bank_account_id[11], national_id[15];
//     float amount;
//     FILE *fptr, *fptr;
//
//     if (option == 2){
//         clear_screen();
//
//		if(fptr == NULL){
//             printf("Account not registered");
//		}
//		else{
//		    fread(&acc,sizeof(acc),1,fptr);
//			fclose(fptr);
//             printf("Account registered\n");
////            //printf("%d",acc.age);
//            printf("\n1.Make transaction");
//            printf("\n2.Change Account Status");
//            printf("\n3.Get Cash");
//            printf("\n4.Deposite in Account");
//            printf("\n5.Return to Main Menu\n");
//            printf("\nEnter choice ");     //how
//            scanf("%d",&choice);
//            clear_screen();
//            if (choice == 1){
//                printf("\nMake transaction");
//                printf("\nEnter Bank Account ID to transfer to");
//                scanf("%s",national_id);
//                printf("\nEnter the transfer amount");
//                scanf("%f",&amount);
//                if (acc.balance < amount){
//                    printf("\nNot enough money to transfer");
//                }
//
////                else{
////                    fptr = fopen(strcat(national_id, ".dat","r"));     //ctr shift c
////                    if(fptr == Null){
////                        printf()
////                    }
////                }
//            }
//
//	}
//
//    }
//    else if (option == 3){
//        exit(0);
//    }
//
//    return 0;
//}

/****************************************/
/*        Functions Definitions         */
/****************************************/

void SetConsoleCursorPosition(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
}
int GetStdHandle(int nStdHandle)
{
    return nStdHandle;
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(x, y);
}

void displayMainMenu()
{
    gotoxy(50, 0);
    printf("Welcome to IMT Bank System\n");
    gotoxy(50, 1);
    printf("--------------------------\n");
    gotoxy(2, 3);
    printf("1- Login as an admin\n");
    gotoxy(2, 4);
    printf("2- Login as a client\n");
    gotoxy(2, 5);
    printf("3- Exit the System\n");
    gotoxy(2, 7);
    printf("Enter your choice: \n");
}

void displayAdminMainMenu()
{
    gotoxy(2, 3);
    printf("- Admin Main Menu:\n");
    gotoxy(2, 4);
    printf("------------------\n");
    gotoxy(4, 5);
    printf("1- Create New Account\n");
    gotoxy(4, 6);
    printf("2- Open Existing Account\n");
    gotoxy(4, 7);
    printf("3- Log out\n");
    gotoxy(4, 9);
    printf("Enter your choice: \n");
}

void displayClientMainMenu()
{
    gotoxy(2, 3);
    printf("- Client Main Menu:\n");
    gotoxy(2, 4);
    printf("-------------------\n");
    gotoxy(4, 5);
    printf("1- Make Transaction\n");
    gotoxy(4, 6);
    printf("2- Change Account Password\n");
    gotoxy(4, 7);
    printf("3- Get Cash");
    gotoxy(4, 8);
    printf("4- Deposit in Account\n");
    gotoxy(4, 9);
    printf("5- Log out\n");
    gotoxy(4, 11);
    printf("Enter your choice: \n");
}

/**********************************************************/

int bankIDGenerator()
{
    int ID = 1000000000;
    FILE *fptr;
    fptr = fopen("Bank_ID.txt", "r");

    if (fptr != NULL)
        ID = getw(fptr) + 1;
    fclose(fptr);

    fptr = fopen("Bank_ID.txt", "w");
    putw(ID, fptr);
    fclose(fptr);

    return ID;
}

char *randomPasswordGenerator(int N)
{
    int i = 0;
    int randomizer = 0;

    // Seed the random-number generator with current time so that the numbers will be different every time
    srand((unsigned int)(time(NULL)));

    char numbers[] = "0123456789";
    char letters[] = "abcdefghijklmnoqprstuvwyzx";
    char LETTERS[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    char *password = malloc(N + 1);

    for (i = 0; i < N; i++)
    {
        randomizer = rand() % 3;
        switch (randomizer)
        {
            case 0:
                password[i] = numbers[rand() % 10];
                break;
            case 1:
                password[i] = letters[rand() % 26];
                break;
            case 2:
                password[i] = LETTERS[rand() % 26];
                break;
        }
    }

    password[N] = '\0';
    return password;
}

int no_of_spaces(char *name)
{
    int spaces = 0;
    for (int i = 0; name[i] != '\0'; i++)
        if (name[i] == ' ')
            spaces++;
    return spaces;
}

int isNumber(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}

Bank_Account createNewAccount()
{
    Bank_Account acc;

    printf("\n Creating New Account:");
    printf("\n ---------------------\n\n");

    /*Full Name*/
    do
    {
        if (!acc.full_name || acc.full_name[0])
            printf("\x1b[A\x1b[A    *You must enter at least first four names");
        fflush(stdin);
        printf("\n\33[2K    Full Name: ");
        gets(acc.full_name);
    } while (no_of_spaces(acc.full_name) < 3);

    /*Full Address*/
    fflush(stdin);
    printf("\n\n    Full Address: ");
    gets(acc.address);

    /*Age*/
    printf("\n\n    Age: ");
    scanf("%d", &acc.age);
    printf("\n");

    /*National ID*/
    stpcpy(acc.national_id, "0");
    do
    {
        if (strlen(acc.national_id) > 1)
            printf("\x1b[A\x1b[A\33[2K    *National ID must consist of 14-digit Number");
        fflush(stdin);
        printf("\n\33[2K    National ID: ");
        scanf("%s", acc.national_id);
    } while ((strlen(acc.national_id) != 14) || (!isNumber(acc.national_id)));

    /*Guardian National ID*/
    stpcpy(acc.guardian_nat_id, "0");
    if (acc.age < 21)
    {
        printf("\n\n");
        do
        {
            if (strlen(acc.guardian_nat_id) > 1)
                printf("\x1b[A\x1b[A    *National ID must consist of 14-digit Number\n");
            fflush(stdin);
            printf("\33[2K    Guardian National ID: ");
            scanf("%s", acc.guardian_nat_id);
        } while ((strlen(acc.guardian_nat_id) != 14) || (!isNumber(acc.guardian_nat_id)));
    }

    /*Balance*/
    printf("\n\n    Balance: ");
    scanf("%f", &acc.balance);

    printf("\n\n Your automatically generated Bank Account Credentials:");

    acc.bank_acc_id = bankIDGenerator();
    printf("\n    Bank Account ID: %d", acc.bank_acc_id);

    stpcpy(acc.password, randomPasswordGenerator(8));
    printf("\n    Password: %s", acc.password);

    /*Account Status*/
    stpcpy(acc.status, "Active");

    return acc;
}

void saveAccount(Bank_Account acc)
{
    char filename[11];
    FILE *fptr;
    sprintf(filename, "%d", acc.bank_acc_id);
    fptr = fopen(strcat(filename, ".dat"), "w");
    fwrite(&acc, sizeof(acc), 1, fptr);
    if (fwrite != 0)
    {
        printf("\n\n Registered Succesfully");
    }
}

Bank_Account openExistingAccount()
{
    Bank_Account acc;
    int bank_account_id;
    FILE *fptr;
    char filename[50];

    printf("\n Enter Bank Account ID: ");
    scanf("%d", &bank_account_id);

    sprintf(filename, "%d", bank_account_id);
    strcat(filename, ".dat");

    fptr = fopen(filename, "r");
    if (fptr == NULL)
        printf("\n Account not registered!");
    else
    {
        if (fread(&acc, sizeof(acc), 1, fptr) != 1)
        {
            printf("\n Failed to read account data!");
        }
        fclose(fptr);
    }
    return acc;
}