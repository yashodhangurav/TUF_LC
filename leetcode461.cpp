#include<iostream>
using namespace std;

int humingDistance(int x, int y){
     int count = 0;
    while(x!= 0 || y!=0){
        int bin1 = x%2;
        int bin2 = y%2;

        if(bin1 != bin2){
            count++;
        }
        x /= 2;
        y /= 2;
    }
   return count;
}

int main(){
    int x = 2, y=4;

    cout<<humingDistance(x,y);
    return 0;
}