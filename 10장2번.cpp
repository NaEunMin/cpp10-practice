/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template <class T>
bool equalArrays(T x[], T y[], int size){
    for(int i=0; i<size; i++){
        if(x[i]!=y[i])
        return false;
    }
    return true;
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {1, 10, 100, 5 ,4};
    if(equalArrays(x,y, 5)) cout << "같다";
    else cout << "다르다";
    
    cout << endl;
    double a[] = {1.1, 2.2};
    double b[] = {3.3, 4.4};
    
    if(equalArrays(a,b,5)) cout << "같다";
    else cout << "다르다";

    return 0;
}
