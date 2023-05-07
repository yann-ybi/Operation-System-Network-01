// Yann Youbi
// this program takes one strictly positive integer argument
// which is the number of prime integers to print out.

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
void printListofPrimes(unsigned int numOfPrime) {
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        extractProgName(argv[0]);
    }else {
        if (argIsValid(argv[1])) {
            printListofPrimes(atoi(argv[1]));
        } else {
            printf("The argument is not a strictly positive integer.");
        }
    }
}