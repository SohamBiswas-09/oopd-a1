#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter number of names: ";
    cin >> n;

    if (cin.fail() || n <= 0) {
        cout << "Invalid number of names." << endl;
        return 0;
    }

    const int MAX_NAME_LENGTH = 100;

    char (*names)[MAX_NAME_LENGTH];

    try {
        names = new char[n][MAX_NAME_LENGTH];
    }
    catch (...) {
        cout << "Memory allocation failed." << endl;
        return 0;
    }

    cin.ignore(100000, '\n');

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Enter name " << i + 1 << ": ";

            cin.getline(names[i], MAX_NAME_LENGTH);

            if (!cin.fail()) {
                break;
            }

            cin.clear();
            cin.ignore(100000, '\n');

            cout << "Name too long. Please enter a name with at most "
                 << MAX_NAME_LENGTH - 1 << " characters." << endl;
        }
    }

    cout << "\nNames entered:\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << names[i] << endl;
    }

    delete[] names;

    return 0;
}
