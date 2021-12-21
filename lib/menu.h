#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <list>
#include "User.h"

void printMenu();
void printUsers(list<User> users);
void addUser(list<User> &users);
void editUser(list<User> &users);
void removeUser(list<User> &users);
list<User> loadUsers();
void saveUsers(list<User> users);

void waitForUserInput();

#endif