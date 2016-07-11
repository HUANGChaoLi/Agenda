#include "User.h"
#include <string>

User::User() {}
User::User(std::string userName, std::string userPassword,
           std::string userEmail, std::string userPhone) {
    name_ = userName; password_ = userPassword;
    email_ = userEmail; phone_ = userPhone;
}


std::string User::getName() const {
    return name_;
}
std::string User::getPassword() const {
    return password_;
}
std::string User::getEmail() const {
    return email_;
}
std::string User::getPhone() const {
    return phone_;
}


void User::setName(std::string name) {
    name_ = name;
}
void User::setPassword(std::string password) {
    password_ = password;
}
void User::setEmail(std::string email) {
    email_ = email;
}
void User::setPhone(std::string phone) {
    phone_ = phone;
}

