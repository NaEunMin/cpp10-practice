/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int x;
    int sum=0;
    while(true){
    cout << "정수를 입력하세요(0을 입력하면 종료)>>";
    cin >> x;
    if(x==0)
    break;
    v.push_back(x);
    sum += x;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "평균 = " << (double)sum/v.size() << endl;
}   
    return 0;
}
