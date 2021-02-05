#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

int subarraysWithKDistinct(vector<int>& A, int K) {
    int c=0, i=0, j=0, prefix=0, res=0;
    vector<int> m(A.size()+1);

    for(int i=0; i<A.size(); i++){
        cout << "m0 " ;
        cout <<m[A[i]]<<endl;
        // if 2nd pointer's next(++) is not in m,
        // if 1st pointer is not in m
        //  [1,2,1,2,3]
        //  at   ^ i=2   A[2]=1 so m[1]
        // m[1] is zero ?? 
        if(m[A[i]]++ == 0){ // at this moment it's not 1 yet?????????
            // m[A[i]]++; not the same..
            c++;
        }
        cout << "m " ;
        cout <<m[A[i]]<<endl;

        if(c>K){
            m[A[j++]]--; 
            prefix=0; 
            c--;
        }

        while(m[A[j]]>1) {
            prefix++;
            m[A[j++]]--;
        }


        if(c==K){
            res+=prefix+1;
        }

        cout << prefix ;
        cout << " ";
        cout << c;
        cout << " ";
        cout << res << endl; 
        for(int k=0; k<m.size(); k++){
            cout << m[k] ;
        }
        cout << endl;

    }

    return res;
}


int main(){
    vector<int> A = {1,2,1,2,3};
    int K = 2;
    return subarraysWithKDistinct(A, K);

}