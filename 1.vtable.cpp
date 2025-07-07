#include<iostream>
using namespace std;

class Employee{
    public:
    void raiseSalary(){ }   
    // virtual void raiseSalary(){}         //uncomment this to see the difference
    void promote(){ }
};

class Engineer:public Employee{
    public:
    void raiseSalary(){
        cout<<"engineer raise"<<endl;
    }
    
};

int main(){
    Employee *e=new Engineer();     //base class pointer is used to determine which method to call
    e->raiseSalary();             //Employee raise
    //WITH VIRUAL FUNCTION on base method
    e->raiseSalary();            //engineer raise
    return 0;
}
/*
###(Notes)
    1.we use pointer type to knwo which method to call
    2.if base class method is virtual, then object class method will be called

###when class have atleast one virtual function then class and its all sub class have vtable
***vtable is a static array type common to all objects of class
***vtable is created at compile time
***each object have vptr pointer poniting to vtable
***vtable have address of all virtual functions of class

//raisesalary is overriden so in vtable it points to derived class method
//promote is inherited and not overriden so in vtable it points to base class method 


###compiler makes the vptr point to the Vtable in constructor. 

*/ 
