#include<iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <future>
#include <thread>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct Person{
    string name;
    int age;
    long long mobile;
};

void structure_binding(){
    Person p1={"kirti",21,1234567890};
    
    auto [name, age, mobile] = p1;

    cout<<name<<" "<<age<<" "<<mobile<<endl;
}

void parallel_sort(){
    vector<int> v={11,2,13,4,59,62,17,38,19,10};
    std:: sort(std::execution::par,v.begin(),v.end());  //parallel sort using multi cores
    for(auto& i:v){
        cout<<i<<" ";
    }    
}

int sumf(int a , int b){
    cout<< "adding two numbers"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int res = a+b;
    return res;
}

void future_async(){
    std::future<int> ft = std::async(std::launch::async,sumf,8,9);
    //do some task
    int value = ft.get();
    cout<< "result is :" << value << endl;
}

void file_system(){
    fs::create_directory("tempdir");
    if (fs::exists("tempdir/src.txt")) {  cout<<"yes"<<endl; }   
    fs::copy_file("tempdir/src.txt","tempdir/dest.txt",fs::copy_options::overwrite_existing);
    for (auto& itr: fs::directory_iterator("tempdir")){
        cout<<"name : "<< itr.path()<< endl;
    }
}

int main(){
    structure_binding();
    parallel_sort();
    future_async(); 
    file_system();
    return 0;
}