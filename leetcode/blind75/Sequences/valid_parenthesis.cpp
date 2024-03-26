bool isLeftBracket(char bracket){
if (bracket == '('||
    bracket == '['||
    bracket == '{') 
    return true;
else 
    return false;
}

bool bracketsMatch(char left, char right){
  if(left == '(') return (right == ')');
  else if(left == '[') return (right == ']');
  else if(left == '{') return (right == '}');
  else return false;
}

bool isValid(string s) {
 stack<int> myStack;
        
 for(auto bracket : s) {
    if(isLeftBracket(bracket)){
        myStack.push(bracket);
    }
    else if(myStack.empty()){
        return false;
        }
    else if(bracketsMatch(myStack.top(), bracket)){
        myStack.pop();
    }else{
       return false;
    }
  }

  return myStack.empty();
        
    }

