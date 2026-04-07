// assignmentQ3 - Determine if two strings are close

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool closeStrings(string word1, string word2){

    int n = word1.size();
    int m = word2.size();

    if(n != m){
        return false;
    }

    // creating two arrays and keeping frequecy of all characters is zero
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);

    for(int i =0; i<n; i++){
        char ch1 = word1[i];
        char ch2 = word2[i];

        //increasing frequency of each word index
        freq1[ch1 - 'a']++;          
        freq2[ch2 - 'a']++;    
        
    }

    // check is perticular char is present in first string and not in second string and vice versa
     for(int i = 0; i<26; i++){
        if(freq1[i] > 0 && freq2[i]==0 || freq1[i]==0 && freq2[i] > 0){
            return false;
        }
    }

    //sorting
    sort( freq1.begin(), freq1.end() );
    sort( freq2.begin(), freq2.end() );

    if(freq1 == freq2)
        return true;
    else
        return false;

}

int main(){
    string str1 = "abc";
    string str2 = "bca";

    cout<<closeStrings(str1,str2);

    return 0;
}



// ------------------------------------------100% LeetCode-ready for Problem 1657 — Determine


//         bool closeStrings(string word1, string word2) {
            
//             if(word1.size() != word2.size())
//                 return false;
    
//             vector<int> freq1(26, 0), freq2(26, 0);
    
//             for(char c : word1)
//                 freq1[c - 'a']++;
    
//             for(char c : word2)
//                 freq2[c - 'a']++;
    
//             // Check if both words use the exact same set of characters
//             for(int i = 0; i < 26; i++){
//                 if((freq1[i] > 0 && freq2[i] == 0) ||
//                    (freq1[i] == 0 && freq2[i] > 0)){
//                     return false;
//                 }
//             }
    
//             // Sort frequency distributions
//             sort(freq1.begin(), freq1.end());
//             sort(freq2.begin(), freq2.end());
    
//             return freq1 == freq2;
//         };
  
    