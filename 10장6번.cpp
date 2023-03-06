/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template <class T>
T *remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize){
    T *tmp = new T[sizeSrc+sizeMinus];
    int i=0;
    int j=0;
    for(i=0; i<sizeSrc; i++){
        for(j=0; j<sizeMinus; j++){
            if(src[i]==minus[j])
            break;
        }
        if(j==sizeMinus) //만약 minus[]검사에서 끝까지 패스했다면
        tmp[retSize++]=src[i]; //tmp에 해당 src원소 대입  retSize는 main에서 참조한 변수이므로 직접 늘려주어야한다.
        
    }
    return tmp;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1,2};
    int retSize = 0;
    int *c = remove(a, 5, b, 2, retSize);
    for(int i=0; i<retSize; i++){
        cout << c[i] << " ";
    }
    return 0;
}
