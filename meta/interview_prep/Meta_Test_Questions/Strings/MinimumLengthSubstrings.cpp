/*Minimum Length Substrings
You are given two strings s and t. You can select any substring of string s and rearrange the characters of the selected substring. Determine the minimum length of the substring of s such that string t is a substring of the selected substring.
Signature
int minLengthSubstring(String s, String t)
Input
s and t are non-empty strings that contain less than 1,000,000 characters each
Output
Return the minimum length of the substring of s. If it is not possible, return -1
Example
s = "dcbefebce"
t = "fd"
output = 5
Explanation:
Substring "dcbef" can be rearranged to "cfdeb", "cefdb", and so on. String t is a substring of "cfdeb". Thus, the minimum length required is 5.*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;


bool hasRequiredCharacters(string s, int sstart, int slast, string requiredChars){
  bool found = false;
  set<int>usedIndex;
  for(int j=0;j<requiredChars.size();j++){
      found = false;
      char required = requiredChars[j];
      for(int i =sstart; i<=slast;i++){
        if(required == s[i] && usedIndex.find(i) == usedIndex.end()){
          found = true;
          usedIndex.insert(i);
        }
    }
    if (found == false) return false;
  }
  
  return true;
}

bool isRequired(char c, string required){
  for(int i =0;i<required.size();i++){
    if (required[i] == c) return true;
  }
  
  return false;
}

int minLengthSubstring(string s, string t) {
  
  int first = 0;
  int last = s.size()-1;
  int i = first;
  int j = last;
  bool firstDone = false;
  bool lastDone = false;
  
  if(false == hasRequiredCharacters(s,first,last,t)) return -1;
  
    do{
     //incremement left until we reach a required character    
     if(firstDone == false){
        i = first+1;
        while(i<last && false == isRequired(s[i], t)){
          i++;
        }
        if(i==last || !hasRequiredCharacters(s,i,last,t)){
             firstDone = true; 
        }
        else first = i;
     } 

     if(lastDone == false){
        j = last-1;
        //decrement right until we reach a required character
        while(j>first && false == isRequired(s[j], t)){
          j--;
        }

        if(hasRequiredCharacters(s,first,j,t)) last = j;  
        else lastDone = true;
      }

    }while(firstDone == false && lastDone == false);
  

  return (last - first) + 1;
  
}



// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}