/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Circle{
    string name;
    int radius;
    public:
    Circle(int radius, string name){
        this->radius = radius;
        this->name = name;
    }
    double getArea() { return 3.14*radius*radius; }
    string getName() { return name; }
};

int main()
{
    int menu;
    int radius;
    string name;
    vector<Circle*> v;
    cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
    while(true){
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4  >>";
        cin >> menu;
        if(menu == 1){
            cout << "생성하고자 하는 원의 반지름과 이름은 >>";
            cin >> radius >> name;
            v.push_back(new Circle(radius, name));
        }
        else if(menu == 2){
                cout << "삭제하고자 하는 원의 이름은 >> ";
                cin >> name;
                vector<Circle*>::iterator it = v.begin();
                while(it != v.end()){
                    Circle *p = *it;
                    if(p->getName() == name){
                        it = v.erase(it);
                        delete p;
                    }
                    else
                        it++;
                }
            }
        else if(menu == 3){
            for(int i=0; i<v.size(); i++){
                cout << v[i]->getName() << endl;
            }
        }
        else if(menu == 4){
            cout << "프로그램을 종료합니다.";
            return 0;
        }
    }
    return 0;
}
