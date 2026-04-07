// valid Anagram Program (anagram is just two words or string having same characters but arrangement of words are different)

#include<iostream>
using namespace std;

// strings are a object so we dont need to take size while using it as parameter ( like we are taking for array and char)
bool isAnagram(string str1, string str2){

    if(str1.length() != str2.length()){
        cout<<"Not anagram";
        return false;
    }

    int count[26] = {0};                //creating array of size 26 (total alphabets are 26)

    for(int i = 0; i<str1.length(); i++){
        // int idx = str1[i] - 'a';            //getting index value of a perticular charater
        // count[idx]++;
        count[str1[i] - 'a']++;
    }

    for(int i = 0; i< str2.length(); i++){
        if(count[str2[i]- 'a'] == 0){                //if the count array is empty at perticular index containing value zero we can say it is not valid anagram
            cout<<"Not a valid anagram";
            return false;
        }
        count[str2[i]- 'a']--;
    }

    cout<<"This is valid anagram!";
    return true;

};

int main(){
    string str1 = "anagram";
    string str2 = "nagaram";

    isAnagram(str1,str2);
    return 0;
}