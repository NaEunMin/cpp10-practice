/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book{
    int year;
    string bookname;
    string writer;
    public:
    Book(int year, string bookname, string writer){
        this->year = year;
        this->bookname = bookname;
        this->writer = writer;
    }
    int getYear(){ return year; }
    string getBookName() { return bookname; }
    string getWriter() { return writer; }
};

int main()
{
    int year;
    string bookname;
    string writer;
    
    vector<Book> v;
    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while(true){
        cout << "년도>>";
        cin >> year;
        if(year == -1) break;
        
        cin.ignore(1, '\n');
        cout << "책이름>>";
        getline(cin, bookname);
        
        cout << "저자>>";
        getline(cin, writer);
        
        v.push_back(Book(year, bookname, writer));
    }
    
    cin.ignore(1, '\n');
    cout << "총 입고된 책은 " << v.size() << "입니다." << endl;
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    getline(cin, writer);
    
    for(int i=0; i<v.size(); i++){
        if(writer == v[i].getWriter()){
            cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
        }
    }
    
    cout << "검색하고자 하는 년도를 입력하세요>>";
    cin >> year;
    
    for(int i=0; i<v.size(); i++){
        if(year == v[i].getYear()){
            cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
        }
    }
    return 0;
}
