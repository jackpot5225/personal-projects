#include <iostream>

int countdown (int number) { // function that recursively counts down from number to 1

    if (number == 0) { // checks for base case

        std::cout << "Happy recursion!" << '\n';
        return 0;

    } else { // calls itself

        std::cout << "recursing... number = " << number << '\n';
        return countdown(number - 1);

    }

}

int factorial (int number) { // function that recursively calcualtes the factorial of a number

    if (number == 1) { // checks for base case

        return 1;

    } else { // calls itself

        return number * factorial(number - 1);

    }

}

int fibonacci (int number) { // function the recursively calulates the number-th fibonacci number

    if (number == 1) { // checks for base case

        return 0;

    } else if (number == 2) { // checks for base case

        return 1;

    } else { // calls itself

        return fibonacci(number - 1) + fibonacci(number - 2);

    }

}

void reverse (int array[], int start, int end) { // function that recursively reverses an array. Also takes the first and last index of the array as parameters
   
    if (start >= end) { // checks for base case
    
    return;
    
    }
     
    int temp = array[start]; // swaps opposite values of the array
    array[start] = array[end];
    array[end] = temp;
     
    reverse(array, start + 1, end - 1); // calls itself

}

int main () {
    
    return 0;

}