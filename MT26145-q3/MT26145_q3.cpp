// Roll No : MT26145
// Name : Soham Biswas

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
        io.outputstring("\n");

        io.outputstring("Age: ");
        io.outputint(age);
        io.outputstring("\n");
    }
};

bool isValidAge(const char* text, int& value) {
    if (text[0] == '\0') {
        return false;
    }

    int i = 0;
    long number = 0;

    while (text[i] != '\0') {

        if (text[i] < '0' || text[i] > '9') {
            return false;
        }

        number = number * 10 + (text[i] - '0');

        if (number > 2147483647) {
            return false;
        }

        i++;
    }

    value = (int)number;
    return true;
}

bool isYes(const char* text) {
    return text[0] == 'y' &&
           text[1] == '\0';
}

bool isNo(const char* text) {
    return text[0] == 'n' &&
           text[1] == '\0';
}

int main() {
    Person person;

    char nameInput[100];
    char ageInput[32];
    char response[10];

    io.activateInput();

    io.outputstring("Enter your name: ");
    io.inputstring(nameInput, 100);
    person.setName(nameInput);

    while (true) {
        io.outputstring("Enter your age: ");
        io.inputstring(ageInput, 32);

        int ageValue;

        if (isValidAge(ageInput, ageValue)) {
            person.setAge(ageValue);
            break;
        }

        io.outputstring("Invalid age. Please enter a number.\n");
    }

    io.outputstring("\nYou entered:\n");
    person.display();

    while (true) {
        io.outputstring("\nIs this information correct? (y/n): ");
        io.inputstring(response, 10);

        if (isYes(response)) {
            io.outputstring("Confirmed.\n");
            io.terminate();
            break;
        }

        if (isNo(response)) {
            io.outputstring("Not confirmed.\n");
            io.terminate();
            break;
        }

        io.outputstring("Invalid response. Please enter y or n.\n");
    }

    return 0;
}
