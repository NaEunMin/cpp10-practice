/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
    public:
    static int getMenu(){
        int menu;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
        cin >> menu;
        return menu;
    }
    static int getShapeType(){
        int shapetype;
        cout << "선:1, 원:2, 사각형:3>>";
        cin >> shapetype;
        return shapetype;
    }
    static int getDeleteShape(){
        int deleteshape;
        cout << "삭제하고자 하는 도형의 인덱스>>";
        cin >> deleteshape;
        return deleteshape;
    }

};

class GraphicEditor {
    Shape *pStart;
    Shape *pLast;
    int node_size;
    vector<Shape*>v;
    public:
    GraphicEditor(){ 
        pStart = NULL;
        node_size = 0;
    }
    int run(){
        cout << "그래픽 에디터입니다." << endl;
    while(true){
    int menuNumber = UI::getMenu();
    if(menuNumber==1){ //삽입파트
        int shapetypeNumber = UI::getShapeType();
        if(shapetypeNumber==1){
            v.push_back(new Line());
        }
        else if(shapetypeNumber==2){
            v.push_back(new Circle());
        }
        else if(shapetypeNumber==3){
            v.push_back(new Rectangle());
        }
    }
    else if(menuNumber==2){ //삭제파트
        int index = UI::getDeleteShape();
        vector<Shape*>::iterator it = v.begin();
        for(int i=0; i<index-1; i++){
            it++;
        }
        Shape *p = *it; //이 코드는 객체 삭제 후 객체 delete를 위해 존재
        it = v.erase(it);
        delete p;
    }
    else if(menuNumber==3){ //모두보기 파트
        for(int i=0; i<v.size(); i++){
            cout << i+1 << ":";
            v[i]->paint();
        }
    }
    else if(menuNumber==4){
        return 0;
    }
}
    } //run함수
};


int main(){

    GraphicEditor* GE = new GraphicEditor();
    GE->run();
    delete GE;
    return 0;
}
