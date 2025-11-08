#include<bits/stdc++.h>
using namespace std;

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    // Remove '+' or '-' sign if present
    if (num[0] == '+' || num[0] == '-') num = num.substr(1);

    // Remove scientific part (like e-03)
    size_t ePos = num.find_first_of("eE");
    if (ePos != string::npos)
        num = num.substr(0, ePos);

    int count = 0;
    bool decimalPoint = false;
    bool nonZeroFound = false;

    for (int i = 0; i < num.size(); i++) {
        char c = num[i];
        if (c == '.') {
            decimalPoint = true;
        } else if (c != '0') {
            nonZeroFound = true;
            count++;
        } else if (nonZeroFound) {
            count++;
        }
    }

    // Remove trailing zeros after decimal point if any
    if (decimalPoint) {
        int i = num.size() - 1;
        while (i >= 0 && num[i] == '0') {
            count--;
            i--;
        }
    }

    if (count < 0) count = 0;
    cout << "Number of significant digits: " << count << endl;

    return 0;
}
