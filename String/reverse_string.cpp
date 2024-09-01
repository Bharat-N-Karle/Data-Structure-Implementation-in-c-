#include <iostream>
#include <string>
using namespace std;

// Function to reverse the string
string reverseString(const string& s) {
    string reversed;
    int n = s.length();

    // Append characters from the end to the beginning
    for (int i = n - 1; i >= 0; --i) {
        reversed += s[i];
    }

    return reversed;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);  // Use getline to handle spaces in the input

    // Reverse the string
    string reversed = reverseString(s);

    // Display the reversed string
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
