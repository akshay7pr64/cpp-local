#include<iostream>
#include<fstream>
#include<string>
using namespace std;

namespace first{
    void firstFunction(){ofstream fb("test.txt");
        if(fb.is_open()){
            fb<<"hi there my name is akshay";
            fb<<"how its going on man"; 
            fb.close();
        }else{cout<<"file openeing failed"<<endl;}
        cout<<"hi"<<endl;
        ifstream fb2("test.txt");
        string line;
        if(fb2.is_open()){
            while (getline (fb2,line)){
                cout<<line<<endl;
            } 
            fb2.close();
        }else{cout<<"file openeing failed"<<endl;}
    }

    void secondFunction(){
        cout<<"second function"<<endl;
    }
}
int main(){
    first:: firstFunction();
}
