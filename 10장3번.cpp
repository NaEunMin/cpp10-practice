/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template <class T>
void reverseArray(T *p, int size){
    T tmp;
    for(int i=0; i<size/2; i++){
        tmp = p[i];
        p[i] = p[size-1-i];
        p[size-1-i] = tmp;
    }
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x,5);
    for(int i=0; i<5; i++) cout << x[i] << ' ';
    return 0;
}
