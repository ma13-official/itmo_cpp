#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Incorrect number of arguments." << endl;
        cout << "Example: \"" << argv[0] << "\" -a/-m operand1 operand2" << endl;
        return 1;
    }

    char *flag = argv[1];
    int operand1 = atoi(argv[2]);
    int operand2 = atoi(argv[3]);
    int result = 0;

    if (strncmp(flag, "-a", 2) == 0) {
        result = operand1 + operand2;
        cout << "Sum: " << result << endl;
    } else if (strncmp(flag, "-m", 2) == 0) {
        result = operand1 * operand2;
        cout << "Product: " << result << endl;
    } else {
        cout << "Invalid flag. U" << endl;
        return 1;
    }

    return 0;
}
