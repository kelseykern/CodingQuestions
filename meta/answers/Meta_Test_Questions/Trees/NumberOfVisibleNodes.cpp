/*
Number of Visible Nodes
There is a binary tree with N nodes. You are viewing the tree from its left side and can see only the leftmost nodes at each level. Return the number of visible nodes.
Note: You can see only the leftmost nodes, but that doesn't mean they have to be left nodes. The leftmost node at a level could be a right node.
Signature
int visibleNodes(Node root) {
Input
The root node of a tree, where the number of nodes is between 1 and 1000, and the value of each node is between 0 and 1,000,000,000
Output
An int representing the number of visible nodes.
Example
            8  <------ root
           / \
         3    10
        / \     \
       1   6     14
          / \    /
         4   7  13            
output = 4*/

#include <bits/stdc++.h>
#include <algorithm>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

// Add any helper functions you may need here
int countNodes(Node * current){
  if(current==nullptr) return 0;

  
  int maxright = countNodes(current->right);
  int maxleft = countNodes(current->left);
  
  if(maxright > maxleft)return 1 + maxright;
  else return 1 + maxleft;

}

int visibleNodes(Node* root) {
  // Write your code here
  Node * current = root;
  return countNodes(current);
  
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

  Node* root_1 = new Node(8); 
  root_1->left = new Node(3); 
  root_1->right = new Node(10); 
  root_1->left->left = new Node(1); 
  root_1->left->right = new Node(6); 
  root_1->right->right = new Node(14); 
  root_1->left->right->left = new Node(4); 
  root_1->left->right->right = new Node(7); 
  root_1->right->right->left = new Node(13); 
  int expected_1 = 4;
  int output_1 = visibleNodes(root_1);
  check(expected_1, output_1);

  Node* root_2 = new Node(10); 
  root_2->left = new Node(8);
  root_2->right = new Node(15);
  root_2->left->left = new Node(4);
  root_2->left->left->right = new Node(5);
  root_2->left->left->right->right = new Node(6);
  root_2->right->left = new Node(14);
  root_2->right->right = new Node(16);
  int expected_2 = 5;
  int output_2 = visibleNodes(root_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}