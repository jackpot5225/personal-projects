#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> numberBitset = 5; //creates an 8 bit set of int 5
    std::bitset<8> charBitset = 'a'; //creates an 8 bit set of char a
    std::cout << numberBitset << '\n'; //outputs the binary of these sets
    std::cout << charBitset << '\n';
    numberBitset >>= 3; //shifts binary of these sets
    charBitset <<= 7;
    std::cout << numberBitset << '\n'; //outputs the new binary of these sets
    std::cout << charBitset << '\n';
    std::cout << static_cast<int>(numberBitset.to_ulong()) << '\n'; //first converts the bitset to an unsigned long and then to its type
    std::cout << static_cast<char>(charBitset.to_ulong()) << '\n';
    return 0;
}