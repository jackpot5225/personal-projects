#include <iostream>
#include <string>
#include <bitset>
#include <cstring>

void scrambler(char wordChar[], std::string *wordPtr); // declares a function to scramble the word

int main() {
    std::string word; // creates string variable to hold the word
    std::cout << "Enter the word to be scrambled: ";
    std::getline(std::cin, word); // fields user input and assigns word as that input
    char wordChar[word.length() + 1]; // creates a char array to hold the word
    std::string *wordPtr = &word; // creates a pointer to the string variable
    std::strcpy(wordChar, wordPtr->c_str()); // copies word into char array
    std::cout << "\n";
    scrambler(wordChar, wordPtr); // passes char array and word pointer to scrambler function
    std::cout << "Scrambling... \n\n";
    std::cout << word; // prints the scrambled word
    return 0;
}

void scrambler(char wordChar[], std::string *wordPtr) {
    std::bitset<8> tempBitset; // declares a temporary bitset
    std::string tempString; // declares a temporary string
    for(int i = 0; i < wordPtr->length(); ++i) { // assigns each char to a tempoaray bitset, bitshifits it, and puts it in the temporary string
        tempBitset = wordChar[i]; // can't get this line to work GAAAAHHHH
        std::cout << "It's working " << i;
        tempBitset >>= 4;
        tempString[i] = static_cast<char>(tempBitset.to_ulong());
    }
    *wordPtr = tempString;
}