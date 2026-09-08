// Roll No : MT26145
// Name : Soham Biswas

#include "basicIO.h"

extern "C" long syscall3(
    long number,
    long arg1,
    long arg2,
    long arg3
);

extern "C" long syscall6(
    long number,
    long arg1,
    long arg2,
    long arg3,
    long arg4,
    long arg5,
    long arg6
);

class NameList {
private:
    char (*names)[100];
    int count;

public:
    NameList(int n) {
        count = n;
        names = 0;

        
        if ((unsigned long)n >
            18446744073709551615UL / 100UL) {
            return;
        }

        unsigned long size =
            (unsigned long)n * 100UL;

       
        long result = syscall6(
            9,
            0,
            (long)size,
            3,
            34,
            -1,
            0
        );

        if (result < 0) {
            names = 0;
        }
        else {
            names = (char (*)[100])result;
        }
    }

    ~NameList() {
        if (names != 0) {
            unsigned long size =
                (unsigned long)count * 100UL;

            syscall6(
                11,
                (long)names,
                (long)size,
                0,
                0,
                0,
                0
            );
        }
    }

    bool isValid() {
        return names != 0;
    }

    void inputNames() {
        for (int i = 0; i < count; i++) {

            io.outputstring("Enter name ");
            io.outputint(i + 1);
            io.outputstring(": ");

            io.inputstring(names[i], 100);

            if (names[i][98] != '\0') {
                char ch;

                while (true) {
                    long bytes = syscall3(
                        0,
                        0,
                        (long)&ch,
                        1
                    );

                    if (bytes <= 0 || ch == '\n') {
                        break;
                    }
                }
            }
        }
    }

    void displayNames() {
        io.outputstring("\nNames entered:\n");

        for (int i = 0; i < count; i++) {
            io.outputint(i + 1);
            io.outputstring(". ");
            io.outputstring(names[i]);
            io.outputstring("\n");
        }
    }
};

int main() {
    io.activateInput();

    io.outputstring("Enter number of names: ");

    int n = io.inputint();

    if (n <= 0) {
        io.outputstring("Invalid number of names.");
        io.terminate();
        return 0;
    }

    NameList list(n);

    if (!list.isValid()) {
        io.outputstring("Memory allocation failed.");
        io.terminate();
        return 0;
    }

    list.inputNames();
    list.displayNames();

    io.terminate();

    return 0;
}
