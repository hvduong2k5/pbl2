#ifndef USER_H
#define USER_H

#include <string>
#include "Dictionary.h"

class Dictionary;

class User {
private:
    std::string account;
    std::string password;
    std::string gmail;
    std::string full_name;
    int role; // 1 = admin, 2 = normal user
