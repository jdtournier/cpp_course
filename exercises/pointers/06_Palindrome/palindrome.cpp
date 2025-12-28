#include <iostream>

#include "palindrome.h"

// recursive function to check if word is palindrome
bool is_palindrome(const std::string& word)
{
    if (word.length() < 2)
        return true;
    else {
        if (word[0] != word[word.length()-1])
            return false;
        else
            return is_palindrome(word.substr(1, word.length()-2));
    }
}
