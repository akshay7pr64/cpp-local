#include <iostream>
using namespace std;

template<typename T>     // <T,deletor,allocator> can use separate deletor and allocator function
class sharedptr{
    private:
        int *res;
        int *counter;
        void incrementCounter(){
            (*counter)++;
        }
        void decrementCounter(){
            (*counter)--;
            if(*counter==0){
                delete res;
                delete counter;
            }
        }
    public:
        sharedptr(int* ptr=nullptr):res(ptr),counter(new int(1)){ cout<<"cons"<<endl; }
        sharedptr(const sharedptr<T>& ptr){
            res=ptr.res;
            counter=ptr.counter;
            incrementCounter();
        }
        sharedptr<T>& operator=(const sharedptr<T>& ptr){
            if(this!=&ptr){
                decrementCounter();
                res=ptr.res;
                counter=ptr.counter;
                incrementCounter();
            }
            return *this;
        }
        sharedptr(sharedptr<T>&& ptr) noexcept{
            res=ptr.res;
            counter=ptr.counter;
            ptr.res=nullptr;
            ptr.counter=nullptr;
        }
        sharedptr<T>& operator=(sharedptr&& ptr) noexcept{
            if(this!=&ptr){
                decrementCounter();
                res=ptr.res;
                counter=ptr.counter;
                ptr.res=nullptr;
                ptr.counter=nullptr;
            }
            return *this;
        }
        
        unsigned int get_count(){
            if(counter){
                return *counter;
            }
            return -1;   //can throw error
        }

        T* operator->(){
            return res;
        }

        T& operator*(){
            return *res;
        }
        T* get(){
            return res;   //can throw error
        }

        void reset(T* ptr){
            decrementCounter();
            res=ptr;
            counter=new int(1);
        }
        
        ~sharedptr(){
            cout<<"des"<<endl;
            decrementCounter();
        }
};

int main(){
    sharedptr<int> ptr1;
    sharedptr<int> ptr2 = new int(10);
    sharedptr<int> ptr3 = ptr2;
    ptr3=ptr2;
    sharedptr<int> ptr4 = std::move(ptr2);
    ptr4=std::move(ptr2);
    // ptr1->func();
    cout<<*ptr3<<endl;
    ptr3.get_count();
    ptr3.reset(new int(20));
    return 0;
}