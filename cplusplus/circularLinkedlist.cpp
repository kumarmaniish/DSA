#include<iostream>
using namespace std;

// ---------> CIRCULAR LINKED LIST

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this->data=d;
            this->next=NULL;
        }

        ~Node(){
            int value=this->data;
            if(this->next !=NULL){
                delete next;
                next=NULL;
            }
            cout<<"memory free is "<<value<<endl;
        }
};

// void insertAtHead(Node* &head, int d){
//     // create temp node
//     Node* temp=new Node(d);

//     temp->next=head;
//     head->next=temp;
//     head=temp;
// }

void insertNode(Node* &tail, int element, int d){
    // assuming that the element present in list

    // empty list
    if(tail == NULL){
        Node* newNode=new Node(d);

        tail=newNode;
        newNode->next=newNode;
    }
    else{
        // non empty list

        Node* curr=tail;

        while(curr->data != element){
            curr=curr->next;
        }
        // element found

        Node* temp = new Node(d);

        temp->next=curr->next;
        curr->next=temp;
    }

}
void deleteNode(Node* &tail, int value){

    if(tail==NULL){
        cout<<"List is empty, please check again "<<endl;
        return;
    }
    else
    {
        // elements present in the list  ---> Non empty
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }

        prev -> next = curr -> next;
        // single node
        if(curr==prev){
            tail=NULL;
        }

        // greater than 2
        else if(tail==curr){
            tail=prev;
        }

        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &tail){

    Node* temp=tail;

    if(tail==NULL){
        cout<<"List is empty "<<endl; 
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail != temp);
    cout<<endl;
}
int main(){

    Node* tail = NULL;

    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,9,10);
    print(tail);
    insertNode(tail,3,4);
    print(tail);

    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,6);
    print(tail);
    deleteNode(tail,10);
    print(tail);
    deleteNode(tail,9);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    deleteNode(tail,7);
    print(tail);
    deleteNode(tail,4);
    print(tail);

    return 0;
}