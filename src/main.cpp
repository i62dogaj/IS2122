#include <iostream>
#include "../lib/helper.h"
#include "../lib/login.h"
#include "../lib/menu.h"
#include "../lib/User.h"

using namespace std;

int main() {

    clearTerminal();

    int option = -1;

    list<User> *users = new list<User>();

    *users = User::loadFromFile("users.txt");

    if (users->size() == 0) {
        cout << "ERROR: NO USERS FOUND" << endl;

        exit(-1);
    }

    User currentUser = login(*users);

    while (option != 0) {
        
        if (currentUser.getType() != User::USER_ADMIN_TYPE) {
            clearTerminal();
            cout << "You must be USER ADMIN to use the application." << endl;

            return 0;
        }

        printMenu();
        cin >> option;

        switch (option)
        {
            case 1:
                printUsers(*users);
                waitForUserInput();
                break;

            case 2:
                addUser(*users);
                break;

            case 3:
                editUser(*users);
                break;

            case 4:
                removeUser(*users);
                break;

            case 7:
                *users = loadUsers();
                break;

            case 8:
                saveUsers(*users);
                break;
            
            default:
                break;
        }
    };

    return 0;
}