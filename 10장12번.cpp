/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Word{
    string engword;
    string korword;
    public:
    Word(string engword, string korword){ this->engword = engword; this->korword = korword; }
    string getEngword(){ return engword; }
    string getKorword(){ return korword; }
};

int main()
{
    vector<Word> v;
    int menu;
    string engword;
    string korword;
    bool sw = false;
    cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;

    while(true){
    cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료:그외키 >>";
    cin >> menu;
    if(menu==1){ //어휘 삽입
        cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
        while(true){
            cout << "영어 >>";
            cin >> engword;
            if(engword=="exit") break;
            cout << "한글 >>";
            cin >> korword;
            v.push_back(Word(engword,korword));
        }
    }
    else if(menu==2){ //어휘 테스트
        cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료." << endl;
        while(true){
            int answer;
            string answer_array[4] = {""};
            
            srand(time(NULL)); //영어단어 랜덤 출력
            int index = rand()%v.size();
            cout << v[index].getEngword() << "?" << endl;
            
            int answer_index = rand()%4; //보기안에 정답 넣기
            answer_array[answer_index] = v[index].getKorword();
            
            for(int i=0; i<4; i++){
                if (i != answer_index) {
                        sw = true;
                        while (sw) { // 보기에 중복이 없게 하기
                            int n = rand() % v.size();
                            if (answer_array[0] != v[n].getKorword() && 
                            answer_array[1] != v[n].getKorword() && 
                            answer_array[2] != v[n].getKorword() && 
                            answer_array[3] != v[n].getKorword()) 
                            {
                                answer_array[i] = v[n].getKorword();
                                sw = false;
                            }
                        }
                    }
            }
            
            for(int i=0; i<4; i++){
                cout << "(" << i+1 << ")" << answer_array[i]; 
            }
            cout << ":>";
            cin >> answer;
            if(answer==-1) break;
            
            if(answer_array[answer-1]==v[index].getKorword()){
                cout << "Excellent !!" << endl;
            }
            else cout<< "NO. !!" << endl;
        }
    }
    else{ //다른 키 눌렀을 경우
        cout << "프로그램을 종료합니다.";
        return 0;
    }
}//while문

    return 0;
}
