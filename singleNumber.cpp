#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums){
    int res = 0;
    int first[32]={0}, second[32]={0};
    
    for(int num:nums) {
        for(int i=0; i<32; i++){
            // cout << num << endl;
            int bit = (num >> i) & 1;
            
            // if(bit){
            //     //second is opposite to bit
            //     //first is changed to the opposite 
            //     //of it which is is xor 
            //     if(first[i]==0 && second[i]==0) {
            //         first[i]=1;
            //     } else if(first[i] && second[i]==0){
            //         first[i]=0;
            //         second[i]=1;
            //     }else if(first[i]==0 && second[i]==1){
            //         second[i]=0;
            //     }
            // } 
            if(bit & (second[i]^bit)) first[i]^=bit;
            if(bit & (first[i]^bit)) second[i]^=bit;
            cout << bit ;
        }
        cout << endl;
    }
    int result = 0;
    for (int i=0; i<32; i++){
        //signed bit
        if(first[i]^first[31]) result += 1 << i;
    }
    //complement - 1
    return first[31] ? ~result : result;    
    // return res;
}

int main(){
    vector<int> nums = {2,2,3,2};
    return singleNumber(nums);
}