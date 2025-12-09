#include <iostream>

using namespace std; 

int* createArray(int anz){
    int* fin= new int[anz](); 

    return fin; 
}

void releaseArray(int*& a){
    delete[] a; 
    a = nullptr; 
}

int main(void){
    int* a = createArray(5); 
    a[2] = 42; 
    cout<<a[2]<< '\n'; 

    releaseArray(a);
    cout<<(a == nullptr)<< '\n';  // 1 heißt true
}