/*Slow Sums
Suppose we have a list of N numbers, and repeat the following operation until we're left with only a single number: Choose any two numbers and replace them with their sum. Moreover, we associate a penalty with each operation equal to the value of the new number, and call the penalty for the entire list as the sum of the penalties of each operation.
For example, given the list [1, 2, 3, 4, 5], we could choose 2 and 3 for the first operation, which would transform the list into [1, 5, 4, 5] and incur a penalty of 5. The goal in this problem is to find the highest possible penalty for a given input.
Signature:
int getTotalTime(int[] arr)
Input:
An array arr containing N integers, denoting the numbers in the list.
Output format:
An int representing the highest possible total penalty.
Constraints:
1 ≤ N ≤ 10^6
1 ≤ Ai ≤ 10^7, where *Ai denotes the ith initial element of an array.
The sum of values of N over all test cases will not exceed 5 * 10^6.
Example
arr = [4, 2, 1, 3]
output = 26
First, add 4 + 3 for a penalty of 7. Now the array is [7, 2, 1]
Add 7 + 2 for a penalty of 9. Now the array is [9, 1]
Add 9 + 1 for a penalty of 10. The penalties sum to 26.*/

#include <bits/stdc++.h>
#include <map>
#include <algorithm>
// Add any extra import statements you may need here

using namespace std;

void addToMap(map<int,int> & map, int key){
  //increment count at this key by 1
  if(map.find(key) != map.end()){
    map[key] = map[key] + 1;
  }
  else
  {
    map.insert({key, 1});
  }
}

bool removeOneMakesEmpty(map<int,int> & map, int key){
  if ( map[key] <= 1){
    map.erase(key);
    return true;
  }
  else
  {
    map[key] = (map[key]) - 1;
    return false;
  }
}

int remove2FromMap(map<int,int> & map){
  //remove top 2 and return sum of those 2 numbers
  
  //it pointing to highest key
  auto it = map.rbegin();
  int newSum = 0;
  
  newSum = it->first;
  if(removeOneMakesEmpty(map, it->first)){
    //reset out it to new highest
    it = map.rbegin();
  }
  newSum += it->first;
  removeOneMakesEmpty(map, it->first);
  
  return newSum;
}

int getElements(map<int,int> map){
  //return count of every key's values
  auto it = map.begin();
  int count = 0;    
  for(;it!=map.end();it++){
    count += it->second;
  }
  
  return count;
}

//int getTotalTime(vector <int> arr) {
//
//  map<int,int> numbers;
//  int total = 0;
//  
//  //loop through and create map
//  // m[num] = numcount  
//  for(int i=0;i<arr.size();i++){
//      addToMap(numbers, arr[i]);
//  }
//  
//  
//  while(getElements(numbers) > 1){
//    //remove top 2 elements and add new element
//    int newSum = remove2FromMap(numbers);
//    total += newSum;
//    addToMap(numbers, newSum);
//  }
//  
//  return total;
//}



int getTotalTime(vector <int> arr) {
  int sum = 0;
  int total = 0;
  
  //sort the array
  sort(arr.begin(), arr.end()); //n log n
  
  while(arr.size()>1){ // n
    sum = arr[arr.size()-2] + arr[arr.size()-1]; 
    //remove last 2 elements
    arr.pop_back();
    arr.pop_back();
    //insert new element ideally with binary insertion log n, we will use sort for now which is n log n
    arr.push_back(sum);
    sort(arr.begin(), arr.end());
    total += sum;

  }
  
   //N log N with binary insertion
   //N log N ^2 with sort() each time
  
  
  
  return total;
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

  vector <int> arr_1{4, 2, 1, 3};
  int expected_1 = 26;
  int output_1 = getTotalTime(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 3, 9, 8, 4};
  int expected_2 = 88;
  int output_2 = getTotalTime(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}