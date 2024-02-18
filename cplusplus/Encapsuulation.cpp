#include<iostream>
using namespace std;

class student{
    private:
        int rollno;
    public:
        void setRollno(int roll){
            rollno=roll;
        }  
        int getRollno(){
            return rollno;
        }
};

int main(){
    cout<<"Encapsulation is ";

    student s;
    s.setRollno(2);
    cout<<s.getRollno()<<endl;

    return 0;
}