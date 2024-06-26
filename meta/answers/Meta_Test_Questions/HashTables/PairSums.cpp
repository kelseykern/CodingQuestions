/*
Pair Sums
Given a list of n integers arr[0..(n-1)], determine the number of different pairs of elements within it which sum to k.
If an integer appears in the list multiple times, each copy is considered to be different; that is, two pairs are considered different if one pair includes at least one array index which the other doesn't, even if they include the same values.
Signature
int numberOfWays(int[] arr, int k)
Input
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, 1,000,000,000].
k is in the range [1, 1,000,000,000].
Output
Return the number of different pairs of elements which sum to k.
Example 1
n = 5
k = 6
arr = [1, 2, 3, 4, 3]
output = 2
The valid pairs are 2+4 and 3+3.
Example 2
n = 5
k = 6
arr = [1, 5, 3, 3, 3]
output = 4
There's one valid pair 1+5, and three different valid pairs 3+3 (the 3rd and 4th elements, 3rd and 5th elements, and 4th and 5th elements).*/


#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
  void addtoMap(unordered_map <int,int> &intAndOccurence, int key){
    //add one to this map location
    auto it = intAndOccurence.find(key);
    if( it != intAndOccurence.end() ) {
       it->second = it->second + 1;
    }
    else {
        intAndOccurence.insert(std::make_pair(key,1));
    }
    
  }



int numberOfWays(vector<int>& arr, int k) {
unordered_map <int,int> m;
int count = 0;
  
for(int i=0;i<arr.size();i++){
  //construct map with key=the number and value=times it occurs
  addtoMap(m, arr[i]);
}

   //k = v1 + v2
   //v1 = k - v2
   for (auto it : m) {
     int key = it.first;
     // check if a key exists in our map that == k - v2
     if(m.find(k-key) != m.end()){//if k - that value is in our map, meaning key == (k - v2) exists in map
       if(k - key == key){ //this is a double
         count += m[key] * (m[key] - 1 ) /2;
       }
       else // not a double
       {
         count += m[key] * m[k-key] /2;
       }
     }
   }
  
  return count+1;
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

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}