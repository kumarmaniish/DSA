#include<iostream>
#include"hero.cpp"
using namespace std;

// ----->  OOPS

class Hero1{

    // properties
    private:
    int health;
    public:
    char level;

    // Default Constructor
    Hero1(){
        cout<<"Constructor called"<<endl;
    }

    // Parameterized Constructors
    Hero1(int health){
        cout<<"This -> "<<this<<endl;
        this->health=health;
    }
    Hero1(int health, char level){
        // cout<<"This -> "<<this<<endl;
        this->health=health;
        this->level=level;
    }

    // Copy constructor
    Hero1(Hero1 &temp){
        cout<<"Constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    // use of getter and setter
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }

    //set
    int sethealth(int h){
        health=h;
    }
    char setlevel(char ch){
        level=ch;
    }

    void print(){
        cout<<"Health"<< this->health<<endl;
        cout<<"Level "<<this->level<<endl;
    }

};
int main(){

    /* statically allocation
    Hero1 a;
    cout<<"Health is : "<<a.gethealth()<<endl;
    cout<<"Level is : "<<a.level<<endl;  

    // Dynamically allocation
    Hero1 *b = new Hero1; 
    cout<<"Health is : "<<(*b).gethealth()<<endl;
    cout<<"Level is : "<<b->level<<endl;  

    creation of object
    Hero1 ramesh;

    cout<<"Health of ramesh is : "<<ramesh.gethealth()<<endl;

    // set health
    ramesh.sethealth(70);
    ramesh.level='A';
    cout<<"Health of ramesh is : "<<ramesh.gethealth()<<endl;
    cout<<"Health of ramesh is : "<<ramesh.getlevel()<<endl;


    h1.health=70;
    h1.level='d';
    cout<<"Size : "<<sizeof(h1)<<endl; 
    cout<<"Value is : "<<h1.health<<endl;
    cout<<"Value is : "<<h1.level<<endl;


    // Object created Statically
    Hero1 ramesh(10);
    cout<<"Address : "<<&ramesh<<endl;
    ramesh.gethealth();

    //Object created Dynamically
    Hero1 *h = new Hero1;*/

    Hero1 S(70,'C');
    S.print();

    // copy constructor
    Hero1 R(S);
    R.print();
    return 0;
}