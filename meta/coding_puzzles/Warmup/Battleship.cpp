#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getHitProbability(int R, int C, vector<vector<int>> G) {
  
  double ships = 0;
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++){
      ships += G[i][j];
    }
  }
  
  
  return ships/(R*C);
}