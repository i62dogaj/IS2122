#include "../lib/helper.h"
#include "../lib/menu.h"

void printMenu()
{
    clearTerminal();

    cout << "MENU" << endl << endl;
    cout << "1: Print Users" << endl;
    cout << "2: Add a new User" << endl;
    cout << "3: Edit an User" << endl;
    cout << "4: Remove an User" << endl;
    cout << "7: Load Users from file" << endl;
    cout << "8: Save Users to file" << endl;
    cout << "0: Exit" << endl;

    cout << endl << ">> Option: ";
}

void printUsers(list<User> users)
{
    clearTerminal();

    if (users.size() == 0) {
        cout << "There are no users in the system." << endl << endl;

        return;
    }

    for (User user: users) {
        cout << "Username: " << user.getUserName() << endl;
        cout << "Password: " << user.getPassword() << endl;
        cout << "Name: " << user.getName() << endl;
        cout << "Email: " << user.getEmail() << endl;
        cout << "Type: " << user.getType() << endl << endl;
    }
}

void addUser(list<User> &users)
{
    clearTerminal();

    string username;
    string password;
    string name;
    string email;
    string type;

    cout << "Introduce username: ";
    cin >> username;

    cout << "Introduce password: ";
    cin >> password;

    cout << "Introduce name: ";
    cin >> name; 

    cout << "Introduce email: ";
    cin >> email;

    for (User user: users) {
        if (user.getUserName() == username || user.getEmail() == email) {
            clearTerminal();
            cout << "ERROR: DUPLICATE USERNAME AND/OR EMAIL." << endl;
            waitForUserInput();

            return;
        }
    }

    int option = -1;

    while (option != 1 && option != 2 && option !=3) {
        cout << "Select user type: " << endl;
        cout << "1: USER_ADMIN" << endl;
        cout << "2: SYSTEM_ADMIN" << endl;
        cout << "3: USER" << endl << endl;
        cout << ">> Option: ";
        cin >> option;
    }

    if (option == 1) {
        type = User::USER_ADMIN_TYPE;
    }
    else if (option == 2)
    {
        type = User::SYSTEM_ADMIN_TYPE;
    }
    else
    {
        type = User::USER_TYPE;
    }

    User user = User{username, password, name, email, type};

    users.push_back(user);

    clearTerminal();
    cout << "The user was created correctly." << endl << endl;

    waitForUserInput();
}

void editUser(list<User> &users)
{
    clearTerminal();

    if (users.size() == 0) {
        cout << "There are no users in the system." << endl << endl;
        waitForUserInput();

        return;
    }

    printUsers(users);

    string username;

    cout << "Introduce the username of the User you want to edit: ";
    cin >> username;

    User *userToEdit = NULL;

    for (User &user: users) {
        if (user.getUserName() == username) {
            userToEdit = &user;
            break;
        }
    }

    if (userToEdit == NULL) {
        clearTerminal();
        cout << "The user with username " << username << " doesn't exist." << endl << endl;
        waitForUserInput();

        return;
    }

    string password;
    string name;
    string email;
    int type = 0;

    int option = -1;

    while (option < 0 || option > 5) {
        clearTerminal();

        cout << "EDIT USER" << endl << endl;
        cout << "1: Edit Username" << endl;
        cout << "2: Edit Password" << endl;
        cout << "3: Edit Name" << endl;
        cout << "4: Edit Email" << endl;
        cout << "5: Edit Type" << endl;
        cout << "0: Go Back" << endl;

        cout << endl << ">> Option: ";
        cin >> option;
    } 

    switch (option)
    {
        case 1:
            cout << "Introduce the new username: ";
            cin >> username;
            for (User user: users) {
                if (user.getUserName() == username) {
                    clearTerminal();
                    cout << "ERROR: DUPLICATE USERNAME." << endl;
                    waitForUserInput();

                    return;
                }
            }
            userToEdit->setUserName(username);
            break;

        case 2:
            cout << "Introduce the new password: ";
            cin >> password;
            userToEdit->setPassword(password);
            break;

        case 3:
            cout << "Introduce the new name: ";
            cin >> name;
            userToEdit->setName(name);
            break;

        case 4:
            cout << "Introduce the new email: ";
            cin >> email;
            for (User user: users) {
                if (user.getEmail() == email) {
                    clearTerminal();
                    cout << "ERROR: DUPLICATE EMAIL." << endl;
                    waitForUserInput();

                    return;
                }
            }
            userToEdit->setEmail(email);
            break;

        case 5:
            while (type != 1 && type != 2 && type !=3) {
                clearTerminal();
                cout << "Select user type: " << endl;
                cout << "1: USER_ADMIN" << endl;
                cout << "2: SYSTEM_ADMIN" << endl;
                cout << "3: USER" << endl << endl;
                cout << ">> Option: ";
                cin >> type;
            }
            if (type == 1) {
                userToEdit->setType(User::USER_ADMIN_TYPE);
            }
            else if (type == 2)
            {
                userToEdit->setType(User::SYSTEM_ADMIN_TYPE);
            }
            else
            {
                userToEdit->setType(User::USER_TYPE);
            }
            break;
    
        case 0:
            return;
        default:
            cout << "INVALID OPTION";
            waitForUserInput();
            return;
    }

    clearTerminal();

    cout << "User edited successfully" << endl << endl;

    waitForUserInput();
}

void removeUser(list<User> &users)
{
    clearTerminal();

    if (users.size() == 0) {
        cout << "There are no users in the system." << endl << endl;
        waitForUserInput();

        return;
    }

    printUsers(users);

    string username;

    cout << "Introduce the username of the User you want to remove: ";
    cin >> username;

    User* userToRemove = NULL;

    for (User user: users) {
        if (user.getUserName() == username) {
            userToRemove = &user;
            break;
        }
    }

    if (userToRemove == NULL) {
        cout << "The user with username " << username << " doesn't exist." << endl;
        waitForUserInput();

        return;
    }

    string confirmation;

    cout << "Are you sure you want to completely remove the user from the system? (y/N)" << endl;
    cout << "Answer: ";
    cin >> confirmation;

    clearTerminal();

    if (confirmation != "Y" && confirmation != "y") {
        cout << "User not deleted." << endl << endl;
        waitForUserInput();

        return;
    }

    users.remove(*userToRemove);

    cout << "User removed successfully" << endl << endl;

    waitForUserInput();
}

list<User> loadUsers()
{
    clearTerminal();

    list<User> list;
    string filename;

    cout << "Introduce the file name: ";

    cin >> filename;

    list = User::loadFromFile(filename);

    clearTerminal();

    cout << list.size() << " user/s loaded." << endl << endl;

    waitForUserInput();

    return list;
}

void saveUsers(list<User> users)
{
    clearTerminal();

    string filename;

    cout << "Introduce the file name: ";

    cin >> filename;

    User::saveToFile(users, filename);

    clearTerminal();

    cout << users.size() << " user/s saved." << endl << endl;

    waitForUserInput();
}

void waitForUserInput()
{
    cout << "Press any key to continue." << endl;
    getchar();
    getchar();
}