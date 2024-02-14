#include<iostream>
using namespace std;

// --------->  Singly Linked List

class Node{
    public: 
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;

        }
        cout<<"Memory free "<<value<<endl;
    }


};

void insertAtHead(Node* &head, int d){
    // new node create
    Node* temp=new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    // new node create
    Node* temp=new Node(d);

    tail->next=temp;
    tail=tail->next;
}

void insertAtPosition(Node* &head, int pos, int d){
    //insert at start
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }

    // insert at last
    if(temp->next=NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    // create the node 
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void deleteNode(int pos, Node* &head){
    // delete start node
    if(pos==1){
        Node* temp=head;
        head=head->next;
        // memory free
        temp->next=NULL;
        delete temp;
    }
    else{
        // delete mid or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){


    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    Node* head=node1;
    Node* tail=node1;
    print(head);

    // insertAtHead(head,12);
    // print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

   deleteNode(2,head);
   print(head);






    return 0;
}