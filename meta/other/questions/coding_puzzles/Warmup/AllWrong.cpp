#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

string getWrongAnswers(int N, string C) {
  // Write your code here
  
  //subtract 60 from each character
  //create string with opposite of 0 or 1
  //add 60 back to each character

  for(int i=0;i<N;i++)
  {
    if(C[i] == 'A') C[i] = 'B';
    else C[i] = 'A';
  }
  
  return C;
}