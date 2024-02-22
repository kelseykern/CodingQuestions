
//return index of anagram
//"actor".anagrammedIndexOf("cat") = 0 (act)
//"actor".anagrammedIndexOf("rot") = 2 (tor)
//"actor".anagrammedIndexOf("car") = -1 

//O(n*m)

int anagramedIndexOf(string text, string query){

  for(int i = 0; i < text.length() - query.length() +1; i++)  //O(n)
  {
     if(isAnagramOf(query, text.substring(i, i + query.length())))
     {
         return i;
     }
  }
   return -1;
}



bool isAnagramOf(string str1, string str2)
{
    for(int i=0;i<str1.length();i++){
           match = false;
           for(int j=0;j<str1.length();j++){
             if(str1[i] == str2[j]){
                 match = true;
                 break;
             }
        }
        if(match == false)return false;
    }
    return true;
}



[1,2,2] anagram of [2,1,3]





bool isAnagramOf(string str1, string str2)
{
    char arr1[] = str1.toCharArray();
    char arr2[] = str2.toCharArray();
    int[] count = new int[26];
    for(int  i = 0; i < arr1.length; i++)
    {
        count[arr1[i] - 'a']++;
        count[arr2[i] = 'a']--;
    }
    for(i = 0; i <arr1.length; i++)
    {
        if (count[i] != 0) return false;
    }
    return true;
}