#include <iostream>
#include <string>

int beforeDecimalZeros (std::string const &number); // helper function of trailingZeros

int beforeAndAfterDecimalZeros (std::string const &number); // helper function of trailingZeros

int nonZeros (std::string const &number); // subfunction, counts nonzeros

int intermediateZeros (std::string const &number); // subfunction, counts intermediate zeros

int significantTrailingZeros (std::string const &number); // subfunction, counts significant trailing zeros

int countSigFigs (std::string const &number) { // master function, counts all sigfigs

    return nonZeros(number) + intermediateZeros(number) + significantTrailingZeros(number);

}

int nonZeros (std::string const &number) { // function to count nonzeros

    int count = 0;
    
    for (int i = 0; i < number.length(); ++i) { // loops through the number and counts all nonzero numbers

        if ( (number[i] != '0') && (number[i] != '.') && (number[i] != '-') ) { // checks that number[i] isnt 0, ., or -

            ++count;

        }
    }
    return count;
}

int intermediateZeros (std::string const &number) { // really gross code that counts the intermediate zeros

    int count = 0;
    
    for (int i = 0; i < number.length() - 1; ++i) { //loops through the number

        if ( (number[i] != '0') && (number[i] != '.') && (number[i] != '-') ) { // checks for nonzero values
            
            if ( (number[i + 1] == '0') || ( (number[i + 1] == '.') && (number[i + 2] == '0') ) ) { // checks if the next value is either 0 or .0
            
                int temp = 0; // creates a temporary counter variable that will only be added to count if the zeros are between nonzeros
                
                for (int j = i + 1; j < number.length(); ++j) {

                    if ( (number[j] == '.') || (number[j] == '-') ) { // makes sure . and - aren't counted

                        continue;

                    } else if (number[j] != '0') { // if nonzero digit is reached, add temp to count and leave the loop

                        count += temp;
                        break;

                    } else { // increments the temporary counter

                        ++temp;

                    }               
                }
            }
        }
    }
    return count;
}

int significantTrailingZeros (std::string const &number) { // function that counts significant trailing zeros

    if (number.find('.') == -1) { // checks if there is no decimal

        return 0;

    }
    
    for (int i = 0; i < number.length(); ++i) { // loop that checks if the number contains any nonzero numbers

        if ( (number[i] != '0') && (number[i] != '.') && (number[i] != '-') ) { // checks if a nonzero digit has been reached

            break;

        }

        if ( ( (number[i] == '0') || (number[i] == '.') ) && (i == number.length() - 1) ) { // checks if the are no nonzero digits

            return 0;

        }
    }
    
    if (number[number.length() - 1] == '.') { // checks if the there are any digits after the decimal

        return beforeDecimalZeros(number);

    } else {

        return beforeAndAfterDecimalZeros(number);

    }
}

int beforeAndAfterDecimalZeros (std::string const &number) { // function that counts trailing significant zeros before and after the decimal

    int count = 0;
    
    for (int i = number.length() - 1; i >= 0; --i) { // loops backwards to count significant trailing zeros

        if ( (number[i] != '0') && (number[i] != '.') ) { // checks for nonzero digits

            break;

        } else if (number[i] == '.') { // skips counting the .

            continue;

        } else { // increments count

            ++count;

        }
    }
    return count;
}

int beforeDecimalZeros (std::string const &number) { // function that counts trailing significant zeros only before the decimal

    int count = 0;
    
    for (int i = number.length() - 2; i >= 0; --i) { // loops backwards to count significant trailing zeros

        if ( (number[i] != '0') && (number[i] != '.') && (number[i] != '-') ) { // checks for nonzero digits

            break;

        } else { // increments count

            ++count;

        }
    }
    return count;
}

int main () { // driver code

    std::string number;
    std::cout << "Enter the number: ";
    std::cin >> number;
    std::cout << '\n';
    std::cout << "There are " << countSigFigs(number) << " SigFigs. \n\n";
    std::cout << "Enter any character to exit: ";
    char exitChar;
    std::cin >> exitChar;
    return 0;

}