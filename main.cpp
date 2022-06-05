#include <iostream>

using namespace std;

struct User {
    bool Case;
    // false - Admin true - Customer
    char name[256];
    union {
        struct {
            int id;
            char position[256];
            char department[256];
        } Admin;

        struct {
            int customerID;
        } Customer;
    };
};

void printUser(User user) {
    cout << "User info below -------------------------- User info below" << endl
    << "name is: " << user.name << endl;

    if (user.Case) {
        cout << "Customer ID is: " << user.Customer.customerID << endl;
    } else {
        cout << "Admin ID id: " << user.Admin.id << endl
        << "Position is: " << user.Admin.position << endl
        << "Department: " << user.Admin.department << endl;
    }
    cout << "User info atop -------------------------- User info atop" << endl << endl << endl;
}

User getNewUserFromConsole() {
    User newUser{};

    cout << "input 1 if user is admin end 2 if user is customer";
    cin >> newUser.Case;

    cout << "Enter name:   ";
    cin >> newUser.name;

    if (!newUser.Case) {
        cout << "Enter id:   " << endl;
        cin >> newUser.Admin.id;

        cout << "Enter position:   " << endl;
        cin >> newUser.Admin.position;

        cout << "Enter department:   " << endl;
        cin >> newUser.Admin.department;
    } else {

        cout << "Enter customer ID:   " << endl;
        cin >> newUser.Customer.customerID;
    }

    return newUser;
}


int main() {

    User DB[30];
    User temp{true, "temp", {1234}};

    for (int i = 0; i < 30; i++) {
        DB[i] = temp;
    }

    while (true) {
        int action;
        cout << "DataBase actions:           (input appropriate number)" << endl
             << "( 1 )  Get user info via array index" << endl
             << "( 2 )  Get all info" << endl
             << "( 3 )  Add User" << endl
             << "( 4 )  Delete user via array index" << endl
             << "( 5 )  End session" << endl;
        cin >> action;
        cout << endl;

        switch (action) {
            case 1: {
                cout << "Input index number from 0 to 29:" << endl;
                int index;
                cin >> index;

                printUser(DB[index]);
                break;
            }
            case 2: {
                for (int i = 0; i < 30; i++) {
                    printUser(DB[i]);
                }
                break;
            }
            case 3: {
                int index;
                cout << "input position to put new user in from 0 to 29:" << endl;
                cin >> index;

                User newUsr = getNewUserFromConsole();

                DB[index] = newUsr;
                break;
            }
            case 4: {
                int index;
                cout << "input position to delete user from 0 to 29:" << endl;
                cin >> index;

                DB[index] = temp;
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Wrong number! Try one more time" << endl;
                break;
            }
        }
    }
}
