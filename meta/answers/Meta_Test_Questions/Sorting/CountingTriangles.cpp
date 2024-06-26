/*Counting Triangles
Given a list of N triangles with integer side lengths, determine how many different triangles there are. Two triangles are considered to be the same if they can both be placed on the plane such that their vertices occupy exactly the same three points.
Signature
int countDistinctTriangles(ArrayList<Sides> arr)
or 
int countDistinctTrianges(int[][] arr)
Input
In some languages, arr is an Nx3 array where arr[i] is a length-3 array that contains the side lengths of the ith triangle. In other languages, arr is a list of structs/objects that each represent a single triangle with side lengths a, b, and c.
It's guaranteed that all triplets of side lengths represent real triangles.
All side lengths are in the range [1, 1,000,000,000]
1 <= N <= 1,000,000
Output
Return the number of distinct triangles in the list.
Example 1
arr = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
output = 2
The first two triangles are the same, so there are only 2 distinct triangles.
Example 2
arr = [[8, 4, 6], [100, 101, 102], [84, 93, 173]]
output = 3
All of these triangles are distinct.
Example 3
arr = [[5, 8, 9], [5, 9, 8], [9, 5, 8], [9, 8, 5], [8, 9, 5], [8, 5, 9]]
output = 1
All of these triangles are the same.*/

#include <bits/stdc++.h>
#include <unordered_set>
// Add any extra import statements you may need here

using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};


// Add any helper functions you may need here
string sortSides(sides & s){
  long long tmp;
  if(s.b < s.a){
      tmp = s.a;
      s.a = s.b;
      s.b = tmp;
    }
  if(s.c < s.b){
      tmp = s.c;
      s.c = s.b;
      s.b = tmp;
  }
  if(s.b < s.a){
      tmp = s.a;
      s.a = s.b;
      s.b = tmp;
  }

  return to_string(s.a) + to_string(s.b) + to_string(s.c);
  
}

int countDistinctTriangles(vector <sides> arr) {
  // Write your code here
  //create map where key is the triangle and value is the count
  
  unordered_set<string> s;
  string ns = "1000000000X1000000000X1000000000";
  
  //create map
  for(int i =0; i<arr.size();i++){ //O(N)
    sides tmp = arr[i];
    //put struct in ascending order
    ns = sortSides(tmp); //O(1)
    s.insert(ns); //O(logn)
  }
  return s.size();
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

  vector<sides> arr_1 = {{7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}};
  int expected_1 = 3;
  int output_1 = countDistinctTriangles(arr_1);
  check(expected_1, output_1);

  vector<sides> arr_2 = {{3, 4, 5}, {8, 8, 9}, {7, 7, 7}};
  int expected_2 = 3;
  int output_2 = countDistinctTriangles(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}