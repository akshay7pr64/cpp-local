#include<iostream>
#include<cstring>
using namespace std;

class String{
    public:
    String():res(nullptr),len(0){ }      //dCons 
    String(const char* ch):len(strlen(ch)){  //pCons
        res=new char[len+1];
        strcpy(res,ch);
    }
    String(const String& other):len(other.len){  //copy constructor
        this->res=new char[len+1];
        strcpy(res,other.res);
    }
    String(const String&& str) {            //move constructor takes rvalue alias
        len=str.len;
        res=str.res;
        // str=nullptr;
        // str.len=0;
    }
    
    String& operator=(const String& str){ //obj assignment operator
        if(this!=&str){    //str3=str3 assignment have to ignored
            char* temp=this->res;       //temp saving if in case new char[] failed
            len=str.len;
            res=new char[len+1];         //assign new array of char
            strcpy(res,str.res);
            delete[] temp;
        }
        return *this;
    }
    //another way for obj assignment operator cas
    // String& operator=(String str){  //obj assignment operator
    //     Swap(this,str)
    //     return *this;   //CAS idiom
    // }
    // void Swap(String& str1, String& str2){
    //     std::swap(str1.res,str2.res);
    //     std::swap(str1.len,str2.len);
    // }
   
    unsigned int length(){
        return len;
    }
    
    friend ostream& operator<<(ostream& out, String& str);  //<< operator overloading
    friend istream& operator>>(istream& in, String& str);  //>> operator overloading

    ~String(){  //des
        if (res){
            delete[] res;
            res=nullptr;
            len=0;
        }
    }
    private:
        char *res;
        unsigned int len;

};



ostream& operator<<(ostream& out, String& str){  //<< operator overloading
    out<<str.res;
    return out;
}

istream& operator>>(istream& in, String& str){  //<< operator overloading
    in>>str.res;
    return in;
}

int main(){
    String str1;    //default constructor
    String str2="hello";  //parameterised constructor --
    String str3=str1;   //copy constructor  (initialisation for first time)
    str3=str2;          //copy assignment operator  -- reassignment to str3
    // str3="hello";       //copy assignment operator  -- reassignment to str3 
    // string str5(str1);  //taken caare by copy constructor-- same as above
    int len=str2.length();  //member function
    cout<<str2<<str3<<str1; //<< overloading
    cin>>str1;  //>> operator overloading
    String str6 = std::move(str2);  //move constructor   modercpp just move and delete str2
    str6=std::move(str3);  //move assignment operator
    

}



//when to  initilize in initlizer list cumpulsory for:
//1. const int pp;      as class member
//   int & mem;
//   String():pp(0),mem(nullptr){   good with this
//      pp=...    // const can only be assign once
//      mem=...    // ref can only be assign once
//   }

//2  ClassA obj;     as class member and classA has only pCons,no dCons
//   String():obj(nullptr){
//       obj=...      // compiler look for dCons
//   }


