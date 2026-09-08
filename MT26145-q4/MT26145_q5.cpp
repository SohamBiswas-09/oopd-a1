#include "basicIO.h"

const int MAX_NAME_LENGTH = 100;

extern "C" long syscall6(long number, long arg1, long arg2,
                         long arg3, long arg4, long arg5, long arg6);


bool isYes(const char* text) {
    return text[0] == 'y' || text[0] == 'Y';
}


bool isNo(const char* text) {
    return text[0] == 'n' || text[0] == 'N';
}


void copyName(char* destination, const char* source) {
    int i = 0;

    while (source[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}


char (*allocateNames(int count))[MAX_NAME_LENGTH] {

    long size = (long)count * MAX_NAME_LENGTH;

    long address = syscall6(
        9,
        0,
        size,
        3,
        0x22,
        -1,
        0
    );

    if (address < 0) {
        return 0;
    }

    return (char (*)[MAX_NAME_LENGTH])address;
}


void freeNames(char (*names)[MAX_NAME_LENGTH], int count) {

    if (names == 0) {
        return;
    }

    long size = (long)count * MAX_NAME_LENGTH;

    syscall6(
        11,
        (long)names,
        size,
        0,
        0,
        0,
        0
    );
}


void enterNames(char (*names)[MAX_NAME_LENGTH], int start, int end) {

    for (int i = start; i < end; i++) {

        io.outputstring("Enter name ");
        io.outputint(i + 1);
        io.outputstring(": ");

        io.inputstring(names[i], MAX_NAME_LENGTH);
    }
}


void printNames(char (*names)[MAX_NAME_LENGTH], int n) {

    io.outputstring("\nNames entered:\n");

    for (int i = 0; i < n; i++) {

        io.outputint(i + 1);
        io.outputstring(". ");
        io.outputstring(names[i]);
        io.outputstring("\n");
    }
}


int main() {

    io.activateInput();

    io.outputstring("Enter number of names: ");

    int n = io.inputint();

    if (n <= 0) {

        io.outputstring("Invalid number of names.\n");

        io.terminate();
        return 0;
    }


    char (*names)[MAX_NAME_LENGTH] = allocateNames(n);

    if (names == 0) {

        io.outputstring("Memory allocation failed.\n");

        io.terminate();
        return 0;
    }


    enterNames(names, 0, n);

    printNames(names, n);


    char choice[10];

    io.outputstring(
        "\nDo you want to change the number of names? (y/n): "
    );

    io.inputstring(choice, 10);


    if (isYes(choice)) {

        io.outputstring("Enter new number of names: ");

        int newN = io.inputint();

        if (newN <= 0) {

            io.outputstring("Invalid number of names.\n");

            freeNames(names, n);

            io.terminate();
            return 0;
        }


        char (*newNames)[MAX_NAME_LENGTH] = allocateNames(newN);

        if (newNames == 0) {

            io.outputstring("Memory allocation failed.\n");

            freeNames(names, n);

            io.terminate();
            return 0;
        }


        int namesToKeep = n;

        if (newN < n) {
            namesToKeep = newN;
        }


        for (int i = 0; i < namesToKeep; i++) {
            copyName(newNames[i], names[i]);
        }


        if (newN > n) {
            enterNames(newNames, n, newN);
        }


        freeNames(names, n);

        names = newNames;
        n = newN;


        printNames(names, n);
    }
    else if (!isNo(choice)) {

        io.outputstring(
            "Invalid response. No change made.\n"
        );
    }


    freeNames(names, n);

    io.terminate();

    return 0;
}
