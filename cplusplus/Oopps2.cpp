#include<iostream>
using namespace std;
// ---->  OOPS 2  ( Pillars of Oops )
class Human{
    public:
    int age;
    int weight;
   // private:  --> inaccessible
    int height;

    public:
    int getAge(){
        return this->age;
    }

    int setweight(int w){
        this->weight=w;
    }
};

class Male: protected Human{
    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping"<<endl;
    }

    int getheight(){
        return this->height;
    }
};

int main(){

    Male m1;
    cout<<m1.getheight()<<endl;

  /*  Male object1;

    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;
    cout<<object1.color<<endl;

    object1.setweight(80);
    cout<<object1.weight<<endl;

    object1.sleep();
*/


    return 0;
}