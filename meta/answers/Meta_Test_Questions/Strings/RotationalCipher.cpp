/*Rotational Cipher
One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.
Given a string and a rotation factor, return an encrypted string.
Signature
string rotationalCipher(string input, int rotationFactor)
Input
1 <= |input| <= 1,000,000
0 <= rotationFactor <= 1,000,000
Output
Return the result of rotating input a number of times equal to rotationFactor.
Example 1
input = Zebra-493?
rotationFactor = 3
output = Cheud-726?
Example 2
input = abcdefghijklmNOPQRSTUVWXYZ0123456789
rotationFactor = 39
output = nopqrstuvwxyzABCDEFGHIJKLM9012345678
*/

#include <bits/stdc++.h>
#include <ctype.h>
// Add any extra import statements you may need here
/*
"Zebra-493?"
rotationFactor=3  
"Cheud-726?"
*/
using namespace std;

const int max_upper_decimal =90;
const int min_upper_decimal =65;
const int max_digit_decimal =57;
const int min_digit_decimal =48;

// Add any helper functions you may need here
char getRotatedVal(char c, int rotationFactor){
  char newVal = c;
  
  //if alphanumeric
  //could use isupper islower isapha isdigit
  if(isalnum(newVal)){
     if(isdigit(newVal)){
       newVal = '0' + ((newVal - '0' + rotationFactor) % 10);
     }
     else{
       bool lower = islower(newVal);
       if(lower){
         newVal = toupper(c);
       }
       
       // 65 + ((('X' - 'A') + rotationFactor ) % 26 )
       //offset = 'X' - 'A' = 88-65 =  23
       //new base 0 index = 23 + rotationFactor = 23 + 50 = 73
       //account for wrap around = 73 % 26 = 4
       //add new base index to ascii base 65 = 65 + 4 = 69 = 'E'
       newVal = 'A' + (((newVal - 'A' ) + rotationFactor) % 26);
       
       if(lower) newVal = tolower(newVal);
     }
  }
  
  return newVal;
}

string rotationalCipher(string input, int rotationFactor) {
  if(rotationFactor < 1) return input;
  
  // For Each character in string
  for(int i =0; i<input.length();i++){
    //Rotated that character
    char newVal = getRotatedVal(input[i], rotationFactor);
    //Replace character in string
    input[i]=newVal;
  }
  return input;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}