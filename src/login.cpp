#include <iostream>
#include "../lib/login.h"

User login(list<User> users)
{
    string username;

    cout << "Introduce your username: ";
    cin >> username;

    User *currentUser = NULL;

    for (User user: users) {
        if (user.getUserName() == username) {
            currentUser = &user;
            break;
        }
    }

    if (currentUser == NULL) {
        cout << "ERROR: USER NOT FOUND" << endl;
        
        exit(-1);
    }

    string password;

    cout << "Introduce your password: ";
    cin >> password;

    if (currentUser->getPassword() != password) {
        cout << "ERROR: WRONG PASSWORD" << endl;

        exit(-1);
    }

    return *currentUser;
}