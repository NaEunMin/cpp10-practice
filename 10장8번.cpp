/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Comparable{
    public:
    virtual bool operator > (Comparable& op2) = 0;
    virtual bool operator < (Comparable& op2) = 0;
    virtual bool operator == (Comparable& op2) = 0;
};


class Circle : public Comparable{
    int radius;
    public:
    Circle(int radius = 1){ this->radius = radius; }
    int getRadius() {return radius;}
    bool operator > (Comparable& op2){
        Circle *p = (Circle*)&op2;   //다운캐스팅
        if(this->radius > p->getRadius()) return true;
        else return false;
    }
    bool operator < (Comparable& op2){
        Circle *p = (Circle*)&op2;  //다운캐스팅
        if(this->radius < p->getRadius()) return true;
        else return false;
    }
    bool operator == (Comparable& op2){
        Circle *p = (Circle*)&op2;  //다운캐스팅
        if(this->radius==p->getRadius()) return true;
        else return false;
    }
};

template <class T>
T bigger(T a, T b){
    if(a > b) return a;
    else return b;
}

int main()
{
    int a = 20, b = 50, c;
    c = bigger(a,b);
    cout << "20과 50중 큰 값은 " << c << endl;
    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);
    cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
    
    return 0;
}
