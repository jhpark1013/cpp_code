#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

class RLE{
    
    public: 
    string key;
    vector<int> counts;

    // public:
    
    RLE( string word ){
        
        vector<int> sb;
        int prev = -1;
        int len = word.size();
        
        for(int i=0; i<len; i++){
            if(i==len-1 || word[i]!=word[i+1]){
                sb.push_back(word[i]);
                counts.push_back(i-prev);
                prev = i;
            }
        }

        for(int j=0; j<sb.size(); j++){
            key.push_back(sb[j]);
        }
        
    }

};

int expressive_words(string S, vector<string> words){
    vector<int> s;
    vector<int> s_count;
    int prev = -1;
    // RLE R = new RLE(S);
    return 0;
}

int main()
{
    string S = "heeellooo";
    vector<string> words = {"hello", "hi", "helo"};
    RLE R(S) ;
    int ans = 0;

    cout << R.key << endl;

    for(string word:words){
        RLE R2(word);
        if(R.key != R2.key) continue;
        for(int i=0; i<R.counts.size(); i++){
            int c1 = R.counts[i];
            int c2 = R2.counts[i];
            if(c1<3 && c1!=c2 || c1<c2) goto theEnd ;
        }
        ans++;
        theEnd:
            continue;
        
    }
    cout <<ans<<endl;
    return ans;

}