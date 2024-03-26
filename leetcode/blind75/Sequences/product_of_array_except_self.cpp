vector<int> productExceptSelf(vector<int>& nums) {
  int size = nums.size();
  vector<int> leftproducts(size,0);
  vector<int> rightproducts(size,0);
  vector<int> finalproducts(size,0);

 // populate left array
  leftproducts[0] = nums[0];
  for(int i=1;i<size;i++){
    leftproducts[i] = leftproducts[i-1]*nums[i];
  }

 // populate right array
  rightproducts[size-1] = nums[size-1];
  for(int i=size-2;i>0;i--){
    rightproducts[i] = rightproducts[i+1]*nums[i];
  }
  
 // populate final array
 finalproducts[0] = rightproducts[1];
 finalproducts[size-1] = leftproducts[size-2];
 for(int i=1;i<size-1;i++){
    finalproducts[i] = 
            leftproducts[i-1] * rightproducts[i+1];
  }
  return finalproducts;
}

