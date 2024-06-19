/*1 Billion Users
We have N different apps with different user growth rates. At a given time t, measured in days, the number of users using an app is g^t (for simplicity we'll allow fractional users), where g is the growth rate for that app. These apps will all be launched at the same time and no user ever uses more than one of the apps. We want to know how many total users there are when you add together the number of users from each app.
After how many full days will we have 1 billion total users across the N apps?
Signature
int getBillionUsersDay(float[] growthRates)
Input
1.0 < growthRate < 2.0 for all growth rates
1 <= N <= 1,000
Output
Return the number of full days it will take before we have a total of 1 billion users across all N apps.
Example 1
growthRates = [1.5]
output = 52
Example 2
growthRates = [1.1, 1.2, 1.3]
output = 79
Example 3
growthRates = [1.01, 1.02]
output = 1047*/

#include <bits/stdc++.h>

using namespace std;

int getBillionUsersDay(vector <float> growthRates) {
  int days = 0;
  
  //logbase(growthRates[0]) of (1000000000) = days
  //log₁.₅(1000000000) = days
  //log₁₀(1000000000) / log₁₀(1.5) = days
  //days needed to reach 1 billion users per app
  //days = ceil(log10(1000000000) / log10(growthRates[0]));
  
  //we need running total of each day to know when the sum is 1 billion
  int min_days = 1;
  int max_days = 2000; //assumed upper limit of day
  int target = 1000000000;
  
  //get mid days
   while(min_days<max_days){ 
      //for mid many days, what is total users
      float total = 0;
      int middays = min_days + (max_days - min_days) / 2; 
      for(int i=0;i<growthRates.size();i++){
         total+=pow(growthRates[i], middays);//(growthRates[i])^middays; g^t
      }
      
      if(total == target){
        return middays;
      }
      
      if(total < target){
        min_days = middays + 1;
      }
      else{
        max_days = middays;
      }
  }
  
  
  return min_days;
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
  vector <float> test_3{1.5};
  int expected_3 = 52;
  int output_3 = getBillionUsersDay(test_3);
  check(expected_3, output_3);
  
  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}