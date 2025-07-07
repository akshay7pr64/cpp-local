
#include<iostream>
using namespace std;

class Base{
    public:
        Base(){cout<<"base cons"<<endl;}
/*1*/  ~Base(){cout<<"base des"<<endl;}    
/*2*/  virtual ~Base(){cout<<"base des"<<endl;}
};
class Derived:public Base{
    public:
    Derived(){cout<<"Derived cons"<<endl;}
    ~Derived(){cout<<"Derived des"<<endl;}
};
int main()
{
    Base *p=new Derived();      //base class pointer pointing to derived class object
    delete p;
    return 0;
}

/*  
###(Notes)
    1.output*
                base cons
                Derived cons
                base des
            *

    to call derived class destructor, base class destructor should be virtual
    2.output*
                base cons
                Derived cons
                Derived des
                base des
            *
####Can we make constructor as virtual?
    no, constructor can't be virtual
    constructor is called in order of inheritance
        in cons vptr is goint to point to Vtable and if we make it 
        virtual constructor then it will be called in reverse order of inheritance so some complication may occur. 
    destructor is called in reverse order of inheritance.
*/

