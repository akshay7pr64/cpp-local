// C++ permits the base pointer to point to any object derived from the base class, 
// it cannot directly access the members of the derived class. Therefore, there is a 
// need for virtual function which allows the base pointer to access the members of the derived class.
#include <iostream>
using namespace std; 
class A{    
    public:    
    virtual void display()    
    {    
        cout << "Base class is invoked"<<endl;    
    }    
};    
class B:public A    
{    
    public:    
    void display()    
    {    
        cout << "Derived Class is invoked"<<endl;    
    }    
};


class Base{  
    public:  
    virtual void show() = 0;  
};  
class Derived : public Base{  
    public:  
    void show()  
    {  
        cout << "Derived class is derived from the base class." << endl;  
    }  
};  

int main()    
{ 
    A* a;    //pointer of base class    
    B b;     //object of derived class    
    a = &b;    
    a->display();   //Late Binding occurs    

    Base *bptr;   //Base b;  
    Derived d;  
    bptr = &d;  
    bptr->show();  

}    