#include<iostream>
using namespace std;
//function template
template<class T> T add(T &a,T &b)  
{  
    T result = a+b;  
    return result;   
}  
template<class X> void fun(X a)  
{  
    std::cout << "Value of a is : " <<a<< std::endl;  
}  
template<class X,class Y> void fun(X b ,Y c)       //function overloading
{  
    std::cout << "Value of b is : " <<b<< std::endl;  
    std::cout << "Value of c is : " <<c<< std::endl;  
}  
//class template
template<class T1,class T2,int size = 10>
class A{
    T1 a;
    T2 b;
    T2 arr[size];
    public:
    A(T1 x,T2 y){
        a = x;
        b = y;
    }
    void display(){
        cout<<"a and b are :"<<a<<" "<<b<<endl;
    }
    void insert(){
        for(int i=0;i<size;i++){
            arr[i] = i+1;   
        }
    }
    void dis(){  
        for(int i=0;i<size;i++)  
        {  
            cout << arr[i] << " ";  
        }  
    }  
};

int main(){
    int i =2;  
    int j =3;  
    float m = 2.3;  
    float n = 1.2;  
    cout<<"Addition of i and j is :"<<add(i,j);  
    cout<<'\n';  
    cout<<"Addition of m and n is :"<<add(m,n);   
    fun(10);
    fun(20,30.5);
    A<int,float> obj(10,20.5);
    obj.display();
    obj.insert();
    obj.dis();
    return 0;
}