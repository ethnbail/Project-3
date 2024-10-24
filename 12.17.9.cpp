/**
      Project id: Group Project C 
      Project Name: Group 3
      Problem: 12.17.9
      Programmer: [Ethan Bailey]
      Date: October 23, 2024
      Version: 1.1  
      Description: This code compares two file names so that it
      is easier for a human to read it.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to extract a number from a string starting at a given position
int extractNumber(const string& str, size_t pos) {
    int num = 0;
    while (pos < str.length() && isdigit(str[pos])) {
        num = num * 10 + (str[pos] - '0');
        ++pos;
    }
    return num;
}

// Function to compare two filenames
int compareFileNames(const string& f1, const string& f2) {
    int pos1 = -1;
    int pos2 = -1; 

    // Find the position of the first digit in f1
    for (size_t pos = 0; pos < f1.length(); ++pos) {
        if (isdigit(f1[pos])) {
            pos1 = pos; // Store position and exit loop
            break;
        }
    }

    for (size_t pos = 0; pos < f2.length(); ++pos) {
        if (isdigit(f2[pos])) {
            pos2 = pos; 
            break;
        }
    }

    // If either filename has no digits, compare as normal strings
    if (pos1 == -1 || pos2 == -1) {
        return f1.compare(f2); // Compare lexicographically
    }

    // Compare the parts before the digits
    int cmp = f1.substr(0, pos1).compare(f2.substr(0, pos2));
    if (cmp == 0) {
        // Extract numbers from both filenames and compare them as integers
        int num1 = extractNumber(f1, pos1);
        int num2 = extractNumber(f2, pos2);

        if (num1 != num2) {
            return num1 - num2; // Compare numeric parts as integers
        }

        // If the numeric parts are equal, compare the remaining parts lexicographically
        return f1.substr(pos1).compare(f2.substr(pos2));
    } else {
        return cmp; // Return comparison for the parts before the digits
    }
}

int main() {
    string file1 = "sec3_14.txt";
    string file2 = "sec10_1.txt";

    int result = compareFileNames(file1, file2);
    if (result < 0) {
        cout << file1 << " is less than " << file2 << endl;
    } else if (result > 0) {
        cout << file1 << " is greater than " << file2 << endl;
    } else {
        cout << file1 << " is equal to " << file2 << endl;
    }

    return 0;
}
