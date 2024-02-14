#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;

    q.push(11);
    cout<<"front is : "<<q.front()<<endl;
    q.push(15);
    cout<<"front is : "<<q.front()<<endl;
    q.push(13);
    cout<<"front is : "<<q.front()<<endl;

    cout<<"Size "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"Size "<<q.size()<<endl; 
    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}