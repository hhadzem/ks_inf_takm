#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// Define number of rules
#define NUMBER_OF_RULES 7
#define RULE_1_LENGTH 11

// Boolean array to track which rules are activated
bool rules_activated[NUMBER_OF_RULES];

// Helper function to reset the rules array
void reset_rules_array() {
    for (int i = 0; i < NUMBER_OF_RULES; i++) {
        rules_activated[i] = false;
    }
}

// Rule 1: Minimum length (at least 8 characters)
bool rule1(const std::string& s) {
    return s.length() >= RULE_1_LENGTH;
}

// Rule 2: First character is lowercase letter (a-z)
bool rule2(const std::string& s) {
    if (s.empty()) return false;
    return std::islower(s[0]);
}

// Rule 3: Last character is a digit (0-9)
bool rule3(const std::string& s) {
    if (s.empty()) return false;
    return std::isdigit(s[s.length() - 1]);
}

// Rule 4: Either second or second-to-last character is a special character
bool rule4(const std::string& s) {
    if (s.length() < 2) return false;

    // Check second character
    char second = s[1];
    if (second == '!' || second == '@' || second == '#' || second == '$' ||
        second == '%' || second == '&' || second == '*' || second == '?' ||
        second == '_') {
        return true;
    }

    // Check second-to-last character
    char second_last = s[s.length() - 2];
    if (second_last == '!' || second_last == '@' || second_last == '#' || second_last == '$' ||
        second_last == '%' || second_last == '&' || second_last == '*' || second_last == '?' ||
        second_last == '_') {
        return true;
    }

    return false;
}

// Rule 5: At least 3 of 4 character categories
bool rule5(const std::string& s) {
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;

    for (char c : s) {
        if (c >= 'a' && c <= 'e') {
            has_lower = true;
        } else if (c >= 'A' && c <= 'E') {
            has_upper = true;
        } else if (c >= '0' && c <= '4') {
            has_digit = true;
        } else if (c == '!' || c == '@' || c == '#') {
            has_special = true;
        }
    }

    int count = (has_lower ? 1 : 0) + (has_upper ? 1 : 0) + (has_digit ? 1 : 0) + (has_special ? 1 : 0);
    return count >= 3;
}

// Rule 6: At least one character appears 4 or more times
bool rule6(const std::string& s) {
    std::vector<int> count(256, 0); // Assuming ASCII characters

    for (char c : s) {
        count[c]++;
        if (count[c] >= 4) {
            return true;
        }
    }

    return false;
}

// Rule 7: Repeated bigram (substring of length 2)
bool rule7(const std::string& s) {
    if (s.length() < 4) return false;

    for (size_t i = 0; i < s.length() - 3; i++) {
        char first_char = s[i];
        char second_char = s[i + 1];

        for (size_t j = i + 2; j < s.length() - 1; j++) {
            if (s[j] == first_char && s[j + 1] == second_char) {
                return true;
            }
        }
    }

    return false;
}

// Function that takes string and returns the score
int calculate_password_strength(const std::string& password) {
    // Reset the rules array
    reset_rules_array();

    // Check each rule and set the corresponding flag
    rules_activated[0] = rule1(password);
    rules_activated[1] = rule2(password);
    rules_activated[2] = rule3(password);
    rules_activated[3] = rule4(password);
    rules_activated[4] = rule5(password);
    rules_activated[5] = rule6(password);
    rules_activated[6] = rule7(password);

    // Calculate and return score
    int score = 0;
    for (int i = 0; i < NUMBER_OF_RULES; i++) {
        if (rules_activated[i]) {
            score++;
        }
    }

    return score;
}

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore(); // To ignore the newline

    for (int i = 0; i < T; i++) {
        std::string password;
        std::getline(std::cin, password);
        std::cout << calculate_password_strength(password) << std::endl;
    }

    return 0;
}
