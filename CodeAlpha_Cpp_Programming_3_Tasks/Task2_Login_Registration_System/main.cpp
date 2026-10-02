#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <limits>
using namespace std;

const string USER_FILE = "users.txt";

// Create a simple hash of the password before storing it.
// This avoids storing the password itself in the file.
string hashPassword(const string& password) {
    return to_string(hash<string>{}(password));
}

bool usernameExists(const string& username) {
    ifstream file(USER_FILE);
    string savedUsername, savedPassword;

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "\n===== Registration =====\n";
    cout << "Enter username: ";
    cin >> username;

    if (username.empty()) {
        cout << "Username cannot be empty.\n";
        return;
    }

    if (usernameExists(username)) {
        cout << "Username already exists. Please choose another one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (password.length() < 4) {
        cout << "Password must contain at least 4 characters.\n";
        return;
    }

    ofstream file(USER_FILE, ios::app);
    if (!file) {
        cout << "Unable to open the user database file.\n";
        return;
    }

    file << username << ' ' << hashPassword(password) << '\n';
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n===== Login =====\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file(USER_FILE);
    if (!file) {
        cout << "No registered users found. Please register first.\n";
        return;
    }

    string passwordHash = hashPassword(password);

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username && savedPassword == passwordHash) {
            cout << "Login successful! Welcome, " << username << ".\n";
            return;
        }
    }

    cout << "Login failed: invalid username or password.\n";
}

int main() {
    int choice;

    cout << "===== CodeAlpha Login & Registration System =====\n";

    do {
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Program closed. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
