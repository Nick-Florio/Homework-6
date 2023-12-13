//
//  main.cpp
//  Homework 6
//
//  Created by Nicholas Florio on 12/10/23.
//
#include <iostream>
#include <cctype> // for tolower()
#include <stdexcept> // for runtime_error

bool isAlpha(char c) {
    return std::isalpha(static_cast<unsigned char>(c)) != 0;
}

bool isPalindrome(const std::string& s) {
    // Base case: an empty string or a string with a single character is a palindrome
    if (s.length() <= 1) {
        return true;
    }

    // Check if the first and last characters are the same (case-insensitive)
    if (std::tolower(s[0]) == std::tolower(s.back())) {
        // Recursively check the substring without the first and last characters
        return isPalindrome(s.substr(1, s.length() - 2));
    } else {
        return false;
    }
}

int main() {
    try {
        // Get user input
        std::string user_input;
        std::cout << "Enter a string (letters only, no spaces, numbers, or special characters): ";
        std::getline(std::cin, user_input);

        // Remove non-alphabetic characters from the input string
        std::string cleaned_input;
        for (char c : user_input) {
            if (isAlpha(c)) {
                cleaned_input += c;
            }
        }

        // Check if the cleaned input is a palindrome
        if (isPalindrome(cleaned_input)) {
            std::cout << '"' << user_input << "\" is a palindrome!\n";
        } else {
            std::cout << '"' << user_input << "\" is not a palindrome.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
