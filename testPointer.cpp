#include <stdlib.h>
#include <iostream>
using namespace std;

void work_ref(int q){
    q++;
}
void work_ptr(int*& p){
    // int d = 9;
    // int* p_int = &d;
    // p = *p_int;
}

int main(){
    //reference example
    int a = 10;
    int &b = a;

    cout << a << " " << b << endl;
    work_ref(a);
    cout << a << " " << b << endl;


    // pointer example
    int x = 5;
    int* y = &x;
    int* z = nullptr;
    x = 6;
    z = 0;
    cout << x << " "<< &x << *y << z  << endl; 
    // work_ptr(z);
    // y* is get the value that y points to
    cout << x << " "<< &x << *y << z  << endl; 

    return 0;
}