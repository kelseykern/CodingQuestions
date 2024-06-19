/*Matching Pairs
Given two strings s and t of length N, find the maximum number of possible matching pairs in strings s and t after swapping exactly two characters within s.
A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character that is present at the ith and jth index of s, respectively. The matching pairs of the two strings are defined as the number of indices for which s[i] and t[i] are equal.
Note: This means you must swap two characters at different indices.
Signature
int matchingPairs(String s, String t)
Input
s and t are strings of length N
N is between 2 and 1,000,000
Output
Return an integer denoting the maximum number of matching pairs
Example 1
s = "abcd"
t = "adcb"
output = 4
Explanation:
Using 0-based indexing, and with i = 1 and j = 3, s[1] and s[3] can be swapped, making it  "adcb".
Therefore, the number of matching pairs of s and t will be 4.
Example 2
s = "mno"
t = "mno"
output = 1
Explanation:
Two indices have to be swapped, regardless of which two it is, only one letter will remain the same. If i = 0 and j=1, s[0] and s[1] are swapped, making s = "nmo", which shares only "o" with t.*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int matchingPairs(string s, string t) {
  // Write your code here
  set <int> mis; //set of indices where mismatch occur
  int misses = 0;
  int potential = 0;
  
  //find mismatched indices, what about when we have 0 mismatches
  for(int i = 0;i<s.size();i++){
    if(s[i] != t[i]) mis.insert(i);
  }
  misses +=mis.size();
  
  if(misses == 0){
    return s.size() -2;
  }
  for(auto it = mis.begin();it!=mis.end();it++){
    for(auto it2 = mis.begin();it!=mis.end();it++){
       //check if a switch will give us +2 matches
       //s[i] == t[j] && s[j] == t[i]
       if(s[*it] == t[*it2] && s[*it2] == t[*it]){
         misses-=2;
         return s.size() - misses;
       }
       //check if a switch will give us +1 match
       //s[i] == t[j] || s[j] == t[i]
       else if (s[*it] == t[*it2] || (s[*it2] == t[*it])){
         potential = 1;
       }
      }       
    }

  
  if(potential == 1){
    misses-=1;
  }

  
//do we need to account for duplicates?  
//   //check if a switch will give us +0 match
//      //s[i] == s[j] && t[i] == t[j] && s[i] == t[i]
//  
//   //check if a switch will give us -1 match
//      //s[i] == s[j] && (s[i] == t[i] || s[j] == t[j] ) || 
//      //t[i] == t[j] && (s[i] == t[i] || s[j] == t[j] ) 

  
  return s.size()- misses;
  
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
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}