/*
 * @author Vecheka Chhourn
 * I have tested both on the server, and the virtual machine.
 * I have also added a substraction method to the program, please 
 * run the program using "gnu -std=gnu90 pr3.c -lm".
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_CHARACTER 52


/**Fucntion Declarations.**/
void initializeCharacters(char *);
void storeInArray(char * , char *);
void combineSets(char *,  char[],  char[]);
void addition(unsigned char[] , unsigned char[]);
void multiplication(unsigned char [], unsigned char [], unsigned char []);
void substraction(unsigned char[], unsigned char[], unsigned char []);
int getCharPosition(char, unsigned char[]);
int isCharacter(char []);
int isValidOperator(char);

/**
 * Main class to execute the program.
 * Pre-conditions: 
 * 1. It has valid number of inputs
 * 2. It has valid operator
 * 3. Input has to be characters
 * @param arg number of args
 * @param argv arguments type
 **/
int main(int arg, char * argv[]) {
  
  // unsigned char set1[NUM_CHARACTER] = {0};
  // unsigned char set2[NUM_CHARACTER] = {0};
  // unsigned char letters[NUM_CHARACTER];
  // unsigned char newSet[NUM_CHARACTER] = {0};
  
  // Initialize arrays
  char *_operator = (char *) malloc(sizeof(char) * 2);
  char * set1 = ( char *) malloc(sizeof(char) * NUM_CHARACTER);
  char * set2 = ( char *) malloc(sizeof(char) * NUM_CHARACTER);
  char * newSet = (char *) malloc(sizeof(char) * NUM_CHARACTER);
  char * letters = (char *) malloc(sizeof(char) * NUM_CHARACTER);
  initializeCharacters(letters);
  
  if (argv[1] == 0 || argv[2] == 0
			|| argv[3] == 0) {
	printf("invalid number of arguments\n");
	return 0;
  }
  
  storeInArray(set1, argv[1]);
  storeInArray(_operator, argv[2]);
  storeInArray(set2, argv[3]);
  
  /** This is another version that takes inputs from the users.**/
  // printf("Enter Two Set of Strings, and an operation (eg. ab + c): ");
  // scanf("%s  %c %s", set1, &operand, set2);
  // check for valid inputs
  //while (!isCharacter(set1) || !isCharacter(set2) || !isValidOperator(_operator)) {
    // reset arrays to null
   // memset(set1, 0, sizeof(set1));
   // memset(set2, 0, sizeof(set2)); 
    //printf("Please enter a string input or a valid operator (+, * or -): ");
   // scanf("%s  %c %s", set1, &operand, set2);
  //}
  
   

  if (!isCharacter(set1) || !isCharacter(set2)) {
	  printf("invalid operand\n");
	  return 0;
  } else if (!isValidOperator(_operator[0]) || _operator[1] > 0) {
	  printf("invalid operator\n");
	  return 0;
  }
  
  
  // do addition or multiplication
  if (_operator[0] == '+') {
    printf("%s + %s => ", set1, set2);
    combineSets(newSet, set1, set2);
    addition(letters, newSet);
  } else if (_operator[0] ==  'x') {
    printf("%s x %s => ", set1, set2);
    multiplication(letters, set1, set2);
  } else if (_operator[0] == '-') {
    printf("%s - %s => ", set1, set2);
    substraction(letters, set1, set2);
  }
  
  
  // free arrays' memories
  free(set1);
  free(set2);
  free(letters);
  free(newSet);
  free(_operator);
  
  return 0;
}

/**
 * Initialize characters in letters array.
 * @param theLetterArray array to add characters in
 **/
 void initializeCharacters(char * theLetterArray) {
  char ch;
  int index = 0;
  for (ch = 'a'; ch <= 'z'; ch++) {
    theLetterArray[index] = ch;
    index++;
    
  }
  index = NUM_CHARACTER / 2;
  for (ch = 'A'; ch <= 'Z'; ch++) {
    theLetterArray[index] = ch;
    index++;
    
  }
 }
 
 void storeInArray(char * theArray, char * theArgArray) {
	 int i;
	 for (i = 0; i < sizeof(theArgArray); i++) {
		 if (*theArgArray > 0) {
			 theArray[i] = *theArgArray++;
		 }
	 }
 }
 
 
 /**
  * Combine two strings as one string.
  * @param theNewSet new combined strings
  * @param theSet1 first string set
  * @param theSet2 second string set
  **/
  void combineSets(char * theNewSet, char theSet1[], char theSet2[]) {
    int i, index = 0;
    for (i = 0 ; i < NUM_CHARACTER; i++) {
      if (theSet1[i] > 0) {
        theNewSet[index] = theSet1[i];
        index++;
      }
    }
    
    for (i = 0 ; i < NUM_CHARACTER; i++) {
      if (theSet2[i] > 0) {
        theNewSet[index] = theSet2[i];
        index++;
      }
    }
    
  }



/**
 * Add two sets of strings, and get a new set of string.
 * @param theLetterArray an array of characters
 * @param theString string to manipulate
 **/
 void addition(unsigned char theLetterArray[], unsigned char theString[]) {
  // unsigned int counter[NUM_CHARACTER] = {0};
   int * counter = (int *) malloc(sizeof(int) * NUM_CHARACTER);
   
  unsigned int i, index;
  for (i = 0 ; i < NUM_CHARACTER; i++) {
    for (index = 0; index < NUM_CHARACTER; index++) {
      if (theString[i] == theLetterArray[index]) {
        counter[index] = counter[index] + 1;
        break;
      }
    }
  }
   
  // manipulate string to get a new string
  for (i = 0; i < NUM_CHARACTER; i++) {
    index = 0;
    if (counter[i] > 1) {
      unsigned int temp = counter[i];
      while (temp / 2 > 0) {
        index++;
        temp = temp / 2;
      }
      if (counter[i] % 2 == 0) counter[i] = 0;
      else counter[i] = 1;
      counter[i + index]++;
    }
  }
  
  // print new string to the console
  i = 0;
  for (i = 0; i < NUM_CHARACTER; i++) {
    if (counter[i] > 0) {
      printf("%c", theLetterArray[i]);
    }
  }
  printf("\n"); 
  free(counter);
 }


/**
 * Mutiply two sets of strings, and get a new set of string.
 * @param theLetterArray set of characters
 * @param theSet1 first set of string
 * @param theSet2 second set of string
 **/
 void multiplication(unsigned char theLetterArray[], unsigned char theSet1[], unsigned char theSet2[]) {
  // unsigned char newString[NUM_CHARACTER] = {0}; 
   char * newString = (char *) malloc(sizeof(char) * NUM_CHARACTER);
   int i = 0, j, pos, index = 0;
   while (theSet1[i] > 0) {
     pos = getCharPosition(theSet1[i], theLetterArray);
     for (j = 0; j < NUM_CHARACTER; j++) {
       if (theSet2[j] > 0) {
         char newChar = theLetterArray[pos + getCharPosition(theSet2[j], theLetterArray)];
         newString[index] = newChar;
         index++;
       } 
     }
     i++;
   }
   
  addition(theLetterArray, newString);
  free(newString);
 }

/**
 * Substract two sets of strings, and get a new set of string.
 * @param theLetterArray set of characters
 * @param theSet1 first set of string
 * @param theSet2 second set of string
 **/
 void substraction(unsigned char theLetterArray[], unsigned char theSet1[], unsigned char theSet2[]) {
  // unsigned char newString[NUM_CHARACTER] = {0}; 
   char * newString = (char *) malloc(NUM_CHARACTER * sizeof(char));
   
   int i = 0, index = 0, j = 0;
   while (theSet1[i] > 0 && theSet2[i] > 0) {
     
     int result = pow(2, getCharPosition(theSet1[i], theLetterArray)) - pow(2, getCharPosition(theSet2[i], theLetterArray));
     if (result >  0) {
       while (result / 2 > 0) {
         index++;
         result =  result / 2;
       }
       newString[j] = theLetterArray[index];
       j++;
     }
     index = 0;
     i++;
     
   }
   
   // add remaining letters to the newString array
   while (theSet1[i] > 0) {
     newString[j] = theSet1[i];
     i++;
     j++;
   }
  
   printf("%s\n", newString);
   free(newString);
 }






/**
 * Get character position in the letters array.
 * @param theLetterArray set of characters
 * @param theChar character to check for
 **/
 int getCharPosition(char theChar, unsigned char theLetterArray[]) {
   int pos;
   for (pos = 0; pos < NUM_CHARACTER; pos++) {
     if (theChar == theLetterArray[pos]) {
       return pos;
     }
   }
 }

/**
* Check if it is a character from a-Z
* @param theArray array to check
* @return 1 if it is character from a-Z
**/
int isCharacter(char theArray[]) {
  char ch;
  int i, result = 1;
  for (i = 0; i < NUM_CHARACTER; i++) {
    if (theArray[i] > 0 ) {
      if ((theArray[i] >= 'a' && theArray[i] <= 'z')) result = 1;
      else if((theArray[i] >= 'A' && theArray[i] <= 'Z')) result = 1;
      else return 0;
    } 
  }
   
  return result;
}

/**
 * Check if it is a valid operator.
 * @param theOperator operator type to check.
 * @return true if it is valid
 **/
 int isValidOperator(char theOperator) {
   return theOperator == '+' || theOperator == 'x'
            || theOperator == '-';
 }