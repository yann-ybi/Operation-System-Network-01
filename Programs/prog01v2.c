// Yann Youbi
// this program take either one or two strictly positive integer argument. When a single argument is provided, the behavior should be the same as that of Version 1.
// When two arguments are provided, then the program should print out all prime integers found in the range defined by the two arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// called when there is not only 1 argument beside the program name
// This function extract the program name from its path and print an error message to standard output
void extractProgName(char *progPath) {
    char *progName;
    char *pathElement = strtok(progPath, "/");
    
    while(pathElement != NULL) {
        pathElement = strtok(NULL, "/");
        if (pathElement != NULL) { progName = pathElement; }
    }
    printf("Proper usage: %s <strictly positive integer>", progName);
}
// this function takes an argument, returns true if it is strictly positive and false if it is not
bool argIsValid(char *arg) {
    float argf = atof(arg); unsigned int argi = argf;
    unsigned int argiClone = argi; unsigned int counter = 0;
    while (argiClone > 0) {
        argiClone /= 10;
        counter++;
    }
    if (argi == 0 || argi != argf || strlen(arg) != counter) { return false; }
    else { return true; }
}

//  This function only prints out the first prime number as well as the number of prime to be printed
void printFirstPrime(unsigned int numOfPrime) {
    char *inLetters[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    if (numOfPrime == 1) {
        printf("The first prime number is: 2.");
    }
    else if (numOfPrime < 20) {
        printf("The first %s prime numbers are: 2, ", inLetters[numOfPrime - 1]);
    } 
    else { printf("The first %d prime numbers are: 2, ", numOfPrime); }
}

// This function prints the whole list of prime numbers based on a numOfPrime deciding the number of prime number to print
void printListPrimes(unsigned int numOfPrime) {
    printFirstPrime(numOfPrime);
    unsigned int newPrime = 2;
    int currNumber;
    currNumber = newPrime + 1;
    int counter = 1; 
    while(counter != numOfPrime) {
        bool prime = true;
        for (int j = 2; j < (currNumber / 2 + 1); j++) {
            if (currNumber % j == 0 && currNumber) {
                prime = false;
                continue;
            }
        }
        if (prime == true) { 
            newPrime = currNumber;
            counter++;
            if (counter != numOfPrime) { printf("%u, ", newPrime); }
            else { printf("%u.", newPrime); }
        }
        currNumber++;
    }
}

// called when 2 arguments are passed in beside the name of the program
// this function prints out the list of prime numbers between the arguments passed in (strictly positive)
void printListPrimes2(unsigned int arg1, unsigned int arg2) {
    unsigned int minVal, maxVal;
    if (arg1 < arg2) {
        minVal = arg1; maxVal = arg2;
    } else {
        minVal = arg2; maxVal = arg1;
    }
    unsigned int currNumber = minVal;
    unsigned int primeCounter = 0;
    unsigned int results[maxVal - minVal];
    while(currNumber <= maxVal) {
        bool prime = true;
        for (int j = 2; j < (currNumber / 2 + 1); j++) {
            if (currNumber % j == 0) {
                prime = false;
                continue;
            }
        }
        if (prime == true && currNumber != 1) {
            results[primeCounter] = currNumber;
            primeCounter++;
        }
        currNumber++;
    } 
    char *inLetters[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    switch (primeCounter) 
    {
    case 0:
        printf("There is no prime number between %u and %u.", arg1, arg2); 
        break;
    case 1:
        printf("There is only one prime number between %u and %u: %u.", arg1, arg2, results[0]);
        break;
    default:
        if (primeCounter < 20) {
            printf("There are %s prime numbers between %u and %u: ", inLetters[primeCounter - 1], arg1, arg2);
        } else {
            printf("There are %u prime numbers between %u and %u: ", primeCounter, arg1, arg2);
        }
        for (int i = 0  ; i < primeCounter; i++) {
            if (i != primeCounter - 1) {
                printf("%u, ", results[i]);
            }
            else {
                printf("%u.", results[i]);
            }
        }
        break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 3) {
        extractProgName(argv[0]);
    }
    else if (argc == 2) {
        if (argIsValid(argv[1])) {
            printListPrimes(atoi(argv[1])); 
        } else {
            printf("The argument is not a strictly positive integer.");
        }
    } else {
        bool valid1 = argIsValid(argv[1]);
        bool valid2 = argIsValid(argv[2]);
        
        if (valid1 == false && valid2 == false) {
            printf("The first and second argument are not a strictly positive integer.");
        } else if (valid1 == false) {   
            printf("The first argument is not a strictly positive integer.");
        } else if (valid2 == false) {
            printf("The second arument is not a strictly positive integer.");
        } else {
            unsigned int arg1 = atoi(argv[1]);
            unsigned int arg2 = atoi(argv[2]);
            printListPrimes2(arg1, arg2); // print primes in the interval arg1 arg2
        }
    }
}