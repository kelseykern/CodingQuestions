/*
Reverse to Make Equal
Given two arrays A and B of length N, determine if there is a way to make A equal to B by reversing any subarrays from array B any number of times.
Signature
bool areTheyEqual(int[] arr_a, int[] arr_b)
Input
All integers in array are in the range [0, 1,000,000,000].
Output
Return true if B can be made equal to A, return false otherwise.
Example
A = [1, 2, 3, 4]
B = [1, 4, 3, 2]
output = true
After reversing the subarray of B from indices 1 to 3, array B will equal array A.*/


#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here    

//decrement value by 1 at the key specified in the map
void decrementValue(unordered_map<int,int>& mis, int key){
  mis[key] = mis[key] - 1;
}

void removeKey(unordered_map<int,int>& mis, int key){
  mis.erase(key);
}

void incrementValue(unordered_map<int,int>&  mis, int key){
    mis[key] = mis[key] + 1;
}

bool ifExistReduce(unordered_map<int,int>& mis, int key){
   if(mis.count(key) > 0){
        //remove from b_mis
        if(mis[key] > 1){
          //decrement key's value
          decrementValue(mis, key);
        }
        else
        {
          //remove the key from map
          removeKey(mis, key);
        }
     return true;
    }
  return false;
}

void addToKey(unordered_map<int,int>&  mis, int key){
      if(mis.find(key) != mis.end()){
        incrementValue(mis,key);
      }
      else
      {
         //otherwise add new key
         mis.insert({key,1});
      }
}


bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  // Write your code here
  
  //int key = character
  //int count = amount of that character
  unordered_map<int,int> a_mis;
  unordered_map<int,int> b_mis;
  
  //for each character in A
  for(int i =0;i<array_a.size();i++){

    addToKey(a_mis, array_a[i]);
    addToKey(b_mis, array_b[i]);
    
    //if they are not equal, add to map of mismatches
    //if(array_a[i]!=array_b[i]){
    //  bool add_a=true;
    //  bool add_b=true;   
    //  
    //  cout<<"do not match"<<endl;
    //  //Before adding, check if key exists in other arrays mismatch list
    //  if(ifExistReduce(b_mis, array_a[i]))
    //  {
    //    add_a=false;
    //  }
    //  
    //  if(ifExistReduce(a_mis, array_b[i]))
    //  {
    //    add_b = false;
    //  }
    //  
    //  //If we got here, the values need to be added to mismatch maps
    //  
    //  cout<<"add to map"<<endl;
    //  //if key already exists add to it
    //  if(add_a)addToKey(a_mis, array_a[i]);
    //  if(add_b)addToKey(b_mis, array_b[i]);
      
    //}
    //if they are equal skip to next element
  }

 // if(a_mis.empty() && b_mis.empty()){
 //   return true;
 // } 
  

  //compare the maps for equivilancy
  if(a_mis == b_mis) return true;
  
  return false;
  
  
  
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

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

int main(){
  vector <int> array_a_1{1, 2, 3, 4};
  vector <int> array_b_1{1, 4, 3, 2};
  bool expected_1 = true;
  bool output_1 = areTheyEqual(array_a_1, array_b_1); 
  check(expected_1, output_1); 

  vector <int> array_a_2{1, 2, 3, 4};
  vector <int> array_b_2{1, 4, 3, 3};
  bool expected_2 = false;
  bool output_2 = areTheyEqual(array_a_2, array_b_2); 
  check(expected_2, output_2); 


  // Add your own test cases here
  
  return 0; 
}