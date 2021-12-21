#include <iostream>
#include "../lib/helper.h"
#include "../lib/login.h"
#include "../lib/menu.h"
#include "../lib/User.h"
#include <unistd.h>

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
        
        

        printMenu();
        cin >> option;

        switch (option)
        {
            case 1:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                printUsers(*users);
                waitForUserInput();
                break;

            case 2:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                addUser(*users);
                break;

            case 3:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                editUser(*users);
                break;

            case 4:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                removeUser(*users);
                break;

            case 7:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                *users = loadUsers();
                break;

            case 8:

                if (currentUser.getType() != User::USER_ADMIN_TYPE) {
                    clearTerminal();
                    cout << "You must be USER ADMIN to use this option." << endl;
                    usleep(2000000);
                    break;
                }

                saveUsers(*users);
                break;
            
            default:
                break;
        }
    };

    return 0;
}