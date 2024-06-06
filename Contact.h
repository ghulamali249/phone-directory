#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact {
private:
    string firstName;
    string lastName;
    string mobileNumber;
    string homeNumber;
    string workNumber;
    string emailAddress;
    string birthday;

public:
    Contact(const string& firstName, const string& lastName,
            const string& mobileNumber, const string& homeNumber,
            const string& workNumber, const string& emailAddress,
            const string& birthday);

    // Getter methods
    string getFirstName() const;
    string getLastName() const;
    string getMobileNumber() const;
    string getHomeNumber() const;
    string getWorkNumber() const;
    string getEmailAddress() const;
    string getBirthday() const;

    // Setter methods
    void setMobileNumber(const string& mobile);
    void setHomeNumber(const string& home);
    void setWorkNumber(const string& work);
    void setEmailAddress(const string& email);
    void setBirthday(const string& bday);

    // Convert contact information to a string for saving to a file
    string toString() const;

    // Create a contact from a string
    static Contact fromString(const string& contactStr);
};

#endif // CONTACT_H

