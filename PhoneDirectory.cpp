#include "PhoneDirectory.h"
#include <iostream>
#include <algorithm>

using namespace std;

PhoneDirectory::PhoneDirectory() {
   
}

PhoneDirectory::~PhoneDirectory() {
    for (Contact* contact : contacts) {
        delete contact;
    }
}

void PhoneDirectory::addContact(const string& firstName, const string& lastName,
                                const string& mobileNumber, const string& homeNumber,
                                const string& workNumber, const string& emailAddress,
                                const string& birthday) {
    Contact* newContact = new Contact(firstName, lastName, mobileNumber, homeNumber, workNumber, emailAddress, birthday);
    contacts.push_back(newContact);
    lastNameMap[lastName].push_back(newContact);
   
}

void PhoneDirectory::displayContacts() const {
    if (contacts.empty()) {
        cout << "There are no contacts in the directory." << endl;
        return;
    }

    for (const Contact* contact : contacts) {
        cout << "Name: " << contact->getFirstName() << " " << contact->getLastName() << endl;
        cout << "Mobile Number: " << contact->getMobileNumber() << endl;
        cout << "Home Number: " << contact->getHomeNumber() << endl;
        cout << "Work Number: " << contact->getWorkNumber() << endl;
        cout << "Email Address: " << contact->getEmailAddress() << endl;
        cout << "Birthday: " << contact->getBirthday() << endl;
        cout << endl;
    }
}

void PhoneDirectory::editContact(const string& firstName, const string& lastName, const string& newMobile,
                                 const string& newHome, const string& newWork, const string& newEmail,
                                 const string& newBirthday) {
    for (Contact* contact : contacts) {
        if (contact->getFirstName() == firstName && contact->getLastName() == lastName) {
            contact->setMobileNumber(newMobile);
            contact->setHomeNumber(newHome);
            contact->setWorkNumber(newWork);
            contact->setEmailAddress(newEmail);
            contact->setBirthday(newBirthday);
            cout << "Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void PhoneDirectory::deleteContact(const string& firstName, const string& lastName) {
    auto it = remove_if(contacts.begin(), contacts.end(), [&](Contact* contact) {
        return contact->getFirstName() == firstName && contact->getLastName() == lastName;
    });

    if (it != contacts.end()) {
        for (auto iter = it; iter != contacts.end(); ++iter) {
            delete *iter;
        }
        contacts.erase(it, contacts.end());
        lastNameMap.erase(lastName);
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

void PhoneDirectory::searchContact(const string& query) const {
    vector<Contact*> results;
    auto it = lastNameMap.find(query);
    if (it != lastNameMap.end()) {
        results.insert(results.end(), it->second.begin(), it->second.end());
    }

    for (const Contact* contact : contacts) {
        if (contact->getFirstName() == query || contact->getMobileNumber() == query ||
            contact->getHomeNumber() == query || contact->getWorkNumber() == query) {
            results.push_back(const_cast<Contact*>(contact));
        }
    }

    if (!results.empty()) {
        cout << "Search results:" << endl;
        for (const Contact* contact : results) {
            cout << "Name: " << contact->getFirstName() << " " << contact->getLastName() << endl;
            cout << "Mobile Number: " << contact->getMobileNumber() << endl;
            cout << "Home Number: " << contact->getHomeNumber() << endl;
            cout << "Work Number: " << contact->getWorkNumber() << endl;
            cout << "Email Address: " << contact->getEmailAddress() << endl;
            cout << "Birthday: " << contact->getBirthday() << endl;
            cout << endl;
        }
    } else {
        cout << "Contact not found!" << endl;
    }
}

