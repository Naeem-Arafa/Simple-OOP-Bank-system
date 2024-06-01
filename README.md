# Simple-OOP-Bank-System

This C++-based project provides a solid foundation for a banking system, focusing on Object-Oriented Programming principles and critical thinking using my lib. While it does't have a GUI, it's designed in a modular way so that you can easily adapt it to a console-based interface to concentrate on OOP concepts.

## Features

### Login
Before accessing the main menu, users are required to log in. The login mechanism ensures security, closing the application after three consecutive failed login attempts.

### Main Menu
Upon successful login, users are presented with a Main Menu offering various functionalities:

- **Show Client List**: Display the list of all clients.
- **Add New Client**: Add a new client using their primary account number.
- **Delete Client**: Remove a client by their account number.
- **Update Client Info**: Modify client information based on their account number.
- **Find Client**: Retrieve and display details for a specific client by their account number.
- **Transactions**: Perform various transactions including deposit, withdraw, checking total balances, and transferring funds.
- **Manage Users**: Administrate users with options such as listing, adding, deleting, updating, and finding users.
- **Login Register**: Register user login times and names, displaying a list of users registered throughout the program's lifecycle.
- **Currency Exchange**: Handle currency-related operations such as listing currencies, finding currencies, updating exchange rates, and currency conversion.
- **Logout**: Logout from the system.

## Currency Exchange
- **List Currencies**: Display a list of currencies along with their country codes and names.
- **Find Currency**: Search for a currency by either its country name or code.
- **Update Rate**: Update the exchange rate for a specific currency.
- **Currency Calculator**: Calculate the difference between currencies of two countries.

## Security
The system implements a login mechanism and closes the application after three consecutive failed login attempts. Special permissions are required for administrative actions, ensuring security and control over critical functionalities. Passwords stored in text files (e.g., `Users.txt`) are encrypted for enhanced security.

## Data Files
The system utilizes the following data files for storing relevant information:

- **Clients.txt**: Stores information about clients.
- **Currencies.txt**: Contains data about various currencies.
- **LoginRegister.txt**: Logs user login times and names.
- **TransferLog.txt**: Logs all transfer transactions.
- **Users.txt**: Stores user credentials and permissions.

## Usage
To utilize the Simple OOP Bank System, follow these steps:

1. Clone the repository to your local machine.
2. Compile and run the application using your preferred C++ compiler.
3. Log in with your credentials to access the main menu.
4. Navigate through the menu options to perform desired banking operations.
5. For administrative tasks, ensure proper permissions are granted.

## Recommendations
1. **Use the App at VS Community**: There are functionalities that only work on Visual Studio Community edition.
2. **Open Project**: When you open the app folder, click on `BankSystem2.sln` to open the project. It is organized with filter folders for better navigation.
3. **Full Access Login**: You can log in with full access to the project using the username `Admin` and password `1234`. You can find other users in `users.txt`. `-1` means full access, and other numbers indicate specific access based on Bitwise Operation, which you can explore yourself.


