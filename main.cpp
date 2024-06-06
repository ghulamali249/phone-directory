#include <iostream>
#include "PhoneDirectory.h"

using namespace std;

void displayMenu() {
    cout << "Phone Directory Application" << endl;
    cout << "1. Add New Contact" << endl;
    cout << "2. Edit Existing Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Display All Contacts" << endl;
    cout << "5. Search Contact" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    PhoneDirectory directory;
    int choice;
    string firstName, lastName, mobile, home, work, email, birthday, query;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the input buffer

        switch (choice) {
        case 1:
            cout << "Enter first name: ";
            getline(cin, firstName);
            cout << "Enter last name: ";
            getline(cin, lastName);
            cout << "Enter mobile number: ";
            getline(cin, mobile);
            cout << "Enter home number: ";
            getline(cin, home);
            cout << "Enter work number: ";
            getline(cin, work);
            cout << "Enter email address: ";
            getline(cin, email);
            cout << "Enter birthday: ";
            getline(cin, birthday);
            directory.addContact(firstName, lastName, mobile, home, work, email, birthday);
            cout << "Contact added successfully!" << endl;
            break;

        case 2:
            cout << "Enter first name of the contact to edit: ";
            getline(cin, firstName);
            cout << "Enter last name of the contact to edit: ";
            getline(cin, lastName);
            cout << "Enter new mobile number: ";
            getline(cin, mobile);
            cout << "Enter new home number: ";
            getline(cin, home);
            cout << "Enter new work number: ";
            getline(cin, work);
            cout << "Enter new email address: ";
            getline(cin, email);
            cout << "Enter new birthday: ";
            getline(cin, birthday);
            directory.editContact(firstName, lastName, mobile, home, work, email, birthday);
            break;

        case 3:
            cout << "Enter first name of the contact to delete: ";
            getline(cin, firstName);
            cout << "Enter last name of the contact to delete: ";
            getline(cin, lastName);
            directory.deleteContact(firstName, lastName);
            break;

        case 4:
            directory.displayContacts();
            break;

        case 5:
            cout << "Enter name or phone number to search: ";
            getline(cin, query);
            directory.searchContact(query);
            break;

        case 6:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

