/*Balance Brackets
A bracket is any of the following characters: (, ), {, }, [, or ].
We consider two brackets to be matching if the first bracket is an open-bracket, e.g., (, {, or [, and the second bracket is a close-bracket of the same type. That means ( and ), [ and ], and { and } are the only pairs of matching brackets.
Furthermore, a sequence of brackets is said to be balanced if the following conditions are met:
The sequence is empty, or
The sequence is composed of two or more non-empty sequences, all of which are balanced, or
The first and last brackets of the sequence are matching, and the portion of the sequence without the first and last elements is balanced.
You are given a string of brackets. Your task is to determine whether each sequence of brackets is balanced. If a string is balanced, return true, otherwise, return false
Signature
bool isBalanced(String s)
Input
String s with length between 1 and 1000
Output
A boolean representing if the string is balanced or not
Example 1
s = {[()]}
output: true
Example 2
s = {}()
output: true
Example 3
s = {(})
output: false
Example 4
s = )
output: false*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;
bool isMatch(char rightc, char leftc){
  switch(leftc){
      case '[':
            if(rightc == ']') return true;
      break;
    case '{':
            if(rightc == '}') return true;
      break;
      case '(':
            if(rightc == ')') return true;
      break;
    default:
      return false;
  }
  return false;
}

bool isLeftChar(char c){
  switch(c){
      case '[':
      case '{':
      case '(':
          return true;
      break;
    default:
      return false;
  }
  return false;
}
// Add any helper functions you may need here


bool isBalanced(string s) {
  // Write your code here
  stack<char> left;
  for(int i =0;i<s.size();i++){
    if(isLeftChar(s[i])){
      left.push(s[i]);
    }
    else{
      if(isMatch(s[i], left.top())){
        left.pop();
      }
      else
      {
        return false;
      }
    }
  }
  
  if(left.size()>0){
    return false;
  }
  
  return true;
  
  
}













// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}