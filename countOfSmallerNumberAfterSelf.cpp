#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int countOfSmallerNumberAfterSelf(vector<int> A){
    int c=0;
    vector<int> m(A.size()+1);
    
    for(int i=0; i<A.size(); i++){
        // if 2nd pointer's next(++) is not in m,
        // if(m[A[i]]++ == 0){
        //     c++;
        // }
        
        cout << A[i] << endl;
        m[A[i]]++;
        for(int j=0; j<m.size(); j++){
            cout << m[j];
        }
        cout << endl;
    }
    return 0;
}

int main(){
    vector<int> A = {1,2,1,2,3};
    return countOfSmallerNumberAfterSelf(A);
}