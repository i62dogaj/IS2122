#ifndef USER_H
#define USER_H

#include <list>
#include <string>


using namespace std;

class User
{
    private:
        string username;
        string password;
        string name;
        string email;
        string type;

    public:
        static const string USER_ADMIN_TYPE;
        static const string SYSTEM_ADMIN_TYPE;
        static const string USER_TYPE;
        
        User(string username, string password, string name, string email, string type);

        string getUserName() {return username;};
        void setUserName(string username) {this->username = username;};

        string getPassword() {return password;};
        void setPassword(string password) {this->password = password;};

        string getName() {return name;};
        void setName(string name) {this->name = name;};

        string getEmail() {return email;};
        void setEmail(string email) {this->email = email;};

        string getType() {return type;};
        void setType(string type) {this->type = type;};

        static list<User> loadFromFile(string filename);

        static void saveToFile(list<User> users, string filename);

        bool operator == (const User& u) const { return username == u.username || email == u.email; }
        bool operator != (const User& u) const { return !operator==(u); }
};

#endif