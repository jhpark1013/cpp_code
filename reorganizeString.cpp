#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

string reorganizeString(string str){
    int strSize = str.size();
    if(strSize<2) return str;

    // create a vector of frequency count 
    int freqChar, freqCharCount=-1, position=0;
    vector<int> freq(26,0);
    for(int i=0; i<strSize; i++){
        freq[str[i]-'a']++;
        if(freq[str[i]-'a'] > freqCharCount){
            freqCharCount = freq[str[i]-'a'];
            freqChar = str[i]-'a';
        }
    }
    // 
    if(freqCharCount > (strSize+1)/2 ) return ""; // in "aab" case, 3/2 = 1, 4/2 = 2

    for(int i=-1; i<26; i++){
        int curr = (i==-1) ? freqChar : i;
        
        while(freq[curr]-- > 0){
            // cout << curr << endl;
            str[position] = 'a' + curr;
            cout << str << endl;
            position = (position+2 >= strSize)? 1 : position+2;
        }
    }
    // cout << str << endl;
    return str;
}

int main(){
    string str = "aabccc";
    reorganizeString(str);
    return 0;
}
