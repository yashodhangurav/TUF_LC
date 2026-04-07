#include<iostream>
using namespace std;

int countOnes(int decNum){
    int n = decNum;
    int count = 0;
    while(n>0){
        int rem = n%2; 
        if(rem == 1){
            count++;
        }
        n = n/2;
    }
    return count;
}
int main(){
    int n = 2147483645;
    cout<<countOnes(n);
}