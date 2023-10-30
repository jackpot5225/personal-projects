#include <iostream>
#include <cstdlib>
#include <ctime>

int B() { return std::rand() % 15 + 1; } // generates numbers for the B column

int I() { return std::rand() % 15 + 16; } // generates numbers for the I column

int N() { return std::rand() % 15 + 31; } // generates numbers for the N column

int G() { return std::rand() % 15 + 46; } // generates numbers for the G column

int O() { return std::rand() % 15 + 61; } // generates numbers for the O column

void cardmaker(int numOfCards) { // generates the cards
    for (int i = 0; i < numOfCards; ++i) {
        int Barray[5];
        int Iarray[5];
        int Narray[5];
        int Garray[5];
        int Oarray[5];

        for (int j = 0; j < 5; ++j) { // generates values
            Barray[j] = B();
            Iarray[j] = I();
            Narray[j] = N();
            Garray[j] = G();
            Oarray[j] = O();
        }
        
        bool condition = true;
        bool *pCondition = &condition;
        while (condition == true) {
            for (int k = 0; k < 5; ++k) { // checks for repeat Bs
                for (int l = 0; l < 5; ++l) {
                    if ( (l == k) || (Barray[k] != Barray[l]) ) {
                        *pCondition = false;
                        continue;
                    } else { // fixes repeats
                        bool subcondition = true;
                        bool *pSubcondition = &subcondition;
                        while (subcondition == true) {
                            Barray[k] = B();
                            for (int m = 0; m < 5; ++m) { // checks that fix isn't another repeat
                                if ( (m == k) || (Barray[m] != Barray[k]) ) {
                                    *pSubcondition = false;
                                    continue;
                                } else {
                                    *pSubcondition = true;
                                    break;
                                }
                            }
                        }
                        *pCondition = true;
                        break;
                    }
                }    
            }
        }

        condition = true;
        while (condition == true) {
            for (int k = 0; k < 5; ++k) { // checks for repeat Is
                for (int l = 0; l < 5; ++l) {
                    if ( (l == k) || (Iarray[k] != Iarray[l]) ) {
                        *pCondition = false;
                        continue;
                    } else { // fixes repeats
                        bool subcondition = true;
                        bool *pSubcondition = &subcondition;
                        while (subcondition == true) {
                            Iarray[k] = I();
                            for (int m = 0; m < 5; ++m) { // checks that fix isn't another repeat
                                if ( (m == k) || (Iarray[m] != Iarray[k]) ) {
                                    *pSubcondition = false;
                                    continue;
                                } else {
                                    *pSubcondition = true;
                                    break;
                                }
                            }
                        }
                        *pCondition = true;
                        break;
                    }
                }    
            }
        }

        condition = true;
        while (condition == true) {
            for (int k = 0; k < 5; ++k) { // checks for repeat Ns
                for (int l = 0; l < 5; ++l) {
                    if ( (l == k) || (Narray[k] != Narray[l]) ) {
                        *pCondition = false;
                        continue;
                    } else { // fixes repeats
                        bool subcondition = true;
                        bool *pSubcondition = &subcondition;
                        while (subcondition == true) {
                            Narray[k] = N();
                            for (int m = 0; m < 5; ++m) { // checks that fix isn't another repeat
                                if ( (m == k) || (Narray[m] != Narray[k]) ) {
                                    *pSubcondition = false;
                                    continue;
                                } else {
                                    *pSubcondition = true;
                                    break;
                                }
                            }
                        }
                        *pCondition = true;
                        break;
                    }
                }    
            }
        }

        condition = true;
        while (condition == true) {
            for (int k = 0; k < 5; ++k) { // checks for repeat Gs
                for (int l = 0; l < 5; ++l) {
                    if ( (l == k) || (Garray[k] != Garray[l]) ) {
                        *pCondition = false;
                        continue;
                    } else { // fixes repeats
                        bool subcondition = true;
                        bool *pSubcondition = &subcondition;
                        while (subcondition == true) {
                            Garray[k] = G();
                            for (int m = 0; m < 5; ++m) { // checks that fix isn't another repeat
                                if ( (m == k) || (Garray[m] != Garray[k]) ) {
                                    *pSubcondition = false;
                                    continue;
                                } else {
                                    *pSubcondition = true;
                                    break;
                                }
                            }
                        }
                        *pCondition = true;
                        break;
                    }
                }    
            }
        }

        condition = true;
        while (condition == true) {
            for (int k = 0; k < 5; ++k) { // checks for repeat Os
                for (int l = 0; l < 5; ++l) {
                    if ( (l == k) || (Oarray[k] != Oarray[l]) ) {
                        *pCondition = false;
                        continue;
                    } else { // fixes repeats
                        bool subcondition = true;
                        bool *pSubcondition = &subcondition;
                        while (subcondition == true) {
                            Oarray[k] = O();
                            for (int m = 0; m < 5; ++m) { // checks that fix isn't another repeat
                                if ( (m == k) || (Oarray[m] != Oarray[k]) ) {
                                    *pSubcondition = false;
                                    continue;
                                } else {
                                    *pSubcondition = true;
                                    break;
                                }
                            }
                        }
                        *pCondition = true;
                        break;
                    }
                }    
            }
        }

        std::cout << " B   I   N   G   O \n"; // prints the bingo card
        for (int j = 0; j < 2; ++j) {
            std::cout << Barray[j] << "  " << Iarray[j] << "  " << Narray[j] << "  " << Garray[j] << "  " << Oarray[j] << '\n';
        }
        std::cout << Barray[2] << "  " << Iarray[2] << ' ' << "FREE" << ' ' << Garray[2] << "  " << Oarray[2] << '\n';
        for (int j = 3; j < 5; ++j) {
            std::cout << Barray[j] << "  " << Iarray[j] << "  " << Narray[j] << "  " << Garray[j] << "  " << Oarray[j] << '\n';
        }
        std::cout << '\n';
    }
    return;
}

int main() {
    std::srand(std::time(NULL)); // seeds the std::rand() function using the time
    int cards;
    int close;
    std::cout << "How many cards? ";
    std:: cin >> cards; // takes user input on how many cards to generate
    std::cout << "\n \n";
    cardmaker(cards); // runs the card generator
    std::cin >> close;
    return 0;
}