#include "basicIO.h"

class Person {
private:
    char name[100];
    int age;

public:
    void setName(const char* input) {
        int i = 0;

        while (input[i] != '\0' && i < 99) {
            name[i] = input[i];
            i++;
        }

        name[i] = '\0';
    }

    void setAge(int inputAge) {
        age = inputAge;
    }

    void display() {
        io.outputstring("Name: ");
        io.outputstring(name);
        io.terminate();

        io.outputstring("Age: ");
        io.outputint(age);
        io.terminate();
    }
};

int main() {
    Person person;

    char nameInput[100];
    char response[10];

    io.activateInput();

    io.outputstring("Enter your name: ");
    io.inputstring(nameInput, 100);
    person.setName(nameInput);

    io.outputstring("Enter your age: ");
    int ageInput = io.inputint();
    person.setAge(ageInput);

    io.outputstring("\nYou entered:\n");
    person.display();

    while (true) {
        io.outputstring("\nIs this information correct? (y/n): ");
        io.inputstring(response, 10);

        if (response[0] == 'y' || response[0] == 'Y') {
            io.outputstring("Confirmed.");
            io.terminate();
            break;
        }

        if (response[0] == 'n' || response[0] == 'N') {
            io.outputstring("Not confirmed.");
            io.terminate();
            break;
        }

        io.outputstring("Invalid response. Please enter y or n.");
        io.terminate();
    }

    return 0;
}
