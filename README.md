# IMT Bank System
This project is a simple console-based banking system implemented in C. It allows users to create new bank accounts, open existing accounts, and perform various operations such as making transactions, changing account passwords, getting cash, and depositing money.

## Features
Create new bank accounts with the following information:
Full name
Full address
Age
National ID (14 digits)
Guardian National ID (optional, only for users under 21)
Balance
Bank account ID (automatically generated)
Password (automatically generated)
Open existing bank accounts using the bank account ID
Perform various operations on bank accounts:
Make transactions
Change account password
Get cash
Deposit money
## Requirements
A C compiler (e.g. gcc)
A terminal or command prompt to run the compiled program
## Usage
Compile the program using a C compiler:
Copy code
gcc -o imt_bank imt_bank.c
Run the compiled program:
Copy code
./imt_bank
Follow the on-screen instructions to use the various features of the IMT Bank System.
## Code Structure
The code is organized into the following sections:

clear_screen(): Clears the screen using a platform-specific command
displayMainMenu(): Displays the main menu of the IMT Bank System
displayAdminMainMenu(): Displays the main menu for admin users
displayClientMainMenu(): Displays the main menu for client users
getch(): Gets a character from the standard input without waiting for the user to press enter
gotoxy(): Moves the cursor to a specific position on the screen
SetConsoleCursorPosition(): Sets the cursor position using the Windows API
GetStdHandle(): Gets a standard handle using the Windows API
bankIDGenerator(): Generates a unique bank account ID
randomPasswordGenerator(): Generates a random password of a given length
no_of_spaces(): Counts the number of spaces in a string
isNumber(): Checks if a string contains only digits
createNewAccount(): Creates a new bank account with user-provided information
saveAccount(): Saves a bank account to a file using the bank account ID as the filename
openExistingAccount(): Opens an existing bank account using the bank account ID
## Limitations
The program does not include any error handling or input validation beyond the basic checks implemented in the code.
The program does not include any database or persistence layer, so all data is lost when the program exits.
The program is designed for a console-based interface and may not work correctly in other environments.
## License
This project is licensed under the MIT License - see the LICENSE file for details.ef{imt_bank.c}
