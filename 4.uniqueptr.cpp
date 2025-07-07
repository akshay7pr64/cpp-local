#include<iostream>
using namespace std;

template <typename T>
class uniqueptr{
    private:
        T *res;

    public:
        uniqueptr(T* a=nullptr):res(a){ cout<<"cons"<<endl; }
        uniqueptr(const uniqueptr<T>&  ptr)=delete;  //copy constructor
        uniqueptr& operator=(const uniqueptr<T>& ptr)=delete;  //copy assignment operator

        uniqueptr(uniqueptr<T>&& ptr) noexcept{  //move constructor
            res=ptr.res;
            ptr.res=nullptr;
        }
        uniqueptr& operator=(uniqueptr<T>&& ptr) noexcept{
            if(this!=&ptr){
                if(res){
                    delete res;
                }
                res=ptr.res;
                ptr.res=nullptr;
            }
            return *this;
        }
        T* operator->(){
            return res;
        }

        T& operator*(){
            return *res;
        }

        T* get(){
            return res;
        }

        void reset(T* ptr=nullptr){
            if(res){
                delete res;
            }
            res=ptr;
        }

        ~uniqueptr() noexcept{
            cout<<"des"<<endl;
            if(res){
                delete res;
            }
        }        
};

int main(){
    uniqueptr<int> ptr1;
    uniqueptr<int> ptr2 = new int(10);
    // uniqueptr<int> ptr3 = ptr1;                //not valid //uniqueptr obj2(obj1)   
    // ptr3 = ptr1;                        //not valid
    uniqueptr<int> ptr3 = std::move(ptr1);    
    ptr2 = std::move(ptr3);
    // ptr1->func();
    cout<< *ptr2 <<endl;
    ptr2.get();
    ptr2.reset(new int (30));               //delete the memory to new one
    
    //destructor      //bcz we have to free up the resources    
    return 0;
}



/*
####(notes)
    If this function is not marked noexcept, STL containers 
    might copy objects instead of moving them (which is inefficient).
*/
