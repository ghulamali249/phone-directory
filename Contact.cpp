#include "Contact.h"
#include <sstream>

using namespace std;

Contact::Contact(const string& firstName, const string& lastName,
                 const string& mobileNumber, const string& homeNumber,
                 const string& workNumber, const string& emailAddress,
                 const string& birthday)
    : firstName(firstName), lastName(lastName), mobileNumber(mobileNumber),
      homeNumber(homeNumber), workNumber(workNumber), emailAddress(emailAddress),
      birthday(birthday) {}

string Contact::getFirstName() const { return firstName; }
string Contact::getLastName() const { return lastName; }
string Contact::getMobileNumber() const { return mobileNumber; }
string Contact::getHomeNumber() const { return homeNumber; }
string Contact::getWorkNumber() const { return workNumber; }
string Contact::getEmailAddress() const { return emailAddress; }
string Contact::getBirthday() const { return birthday; }

void Contact::setMobileNumber(const string& mobile) { mobileNumber = mobile; }
void Contact::setHomeNumber(const string& home) { homeNumber = home; }
void Contact::setWorkNumber(const string& work) { workNumber = work; }
void Contact::setEmailAddress(const string& email) { emailAddress = email; }
void Contact::setBirthday(const string& bday) { birthday = bday; }

string Contact::toString() const {
    return firstName + "," + lastName + "," + mobileNumber + "," + homeNumber + "," +
           workNumber + "," + emailAddress + "," + birthday;
}

Contact Contact::fromString(const string& contactStr) {
    stringstream ss(contactStr);
    string firstName, lastName, mobileNumber, homeNumber, workNumber, emailAddress, birthday;
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, mobileNumber, ',');
    getline(ss, homeNumber, ',');
    getline(ss, workNumber, ',');
    getline(ss, emailAddress, ',');
    getline(ss, birthday, ',');
    return Contact(firstName, lastName, mobileNumber, homeNumber, workNumber, emailAddress, birthday);
}

