#include <fstream>
#include <iostream>
#include <list>
#include "../lib/User.h"

const string User::USER_ADMIN_TYPE = "USER ADMIN";
const string User::SYSTEM_ADMIN_TYPE = "SYSTEM ADMIN";
const string User::USER_TYPE = "USER";

User::User(string username, string password, string name, string email, string type)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->email = email;
    this->type = type;
}

list<User> User::loadFromFile(string filename)
{
    list<User> users;
    ifstream file;

    file.open(filename);

    if (file) {
        while (!file.eof()) {
            string username;
            string password;
            string name;
            string email;
            string type;
            file >> username >> password >> name >> email;
            getline(file, type);
            getline(file, type);
            if (!username.empty()) {
                users.push_back(User{username, password, name, email, type});
            }
        }
        file.close();
    }

    return users;
}

void User::saveToFile(list<User> users, string filename)
{
    ofstream file;

    file.open(filename);

    for (User user: users) {
        file << user.getUserName() << endl;
        file << user.getPassword() << endl;
        file << user.getName() << endl;
        file << user.getEmail() << endl;
        file << user.getType() << endl;
    }

    file.close();
}