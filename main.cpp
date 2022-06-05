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
    cout << "User info atop -------------------------- User info atop" << endl;
}

User getNewUserFromConsole(bool Case) {
    User newUser{};
    newUser.Case = Case;

    cout << "Enter name: ";
    cin >> newUser.name;

    if (!Case) {
        cout << "Enter id: ";
        cin >> newUser.Admin.id;

        cout << "Enter position: ";
        cin >> newUser.Admin.position;

        cout << "Enter department: ";
        cin >> newUser.Admin.department;
    } else {

        cout << "Enter customer ID: ";
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

    cout << admn.name;
    return 0;
}
