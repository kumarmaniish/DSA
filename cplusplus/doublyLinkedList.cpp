#include<iostream>
using namespace std;

// --------->  DOUBLY LINKED LIST

class Node{
    public:
    int data;
    Node* prev;    
    Node* next;


    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    // destructor
    ~Node(){
        int value=this->data;
        if(next !=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free from data "<<value<<endl;
    }
};

void insertAtHead(int d, Node* &head){

    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
    }else{
        Node* temp = new Node(d);

        temp->next=head;
        head->prev=temp; 
        head=temp;
    }
}

void insertAtTail(int d, Node* &tail){
    Node* temp = new Node(d);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void insertAtPosition(Node* &tail,Node* &head, int pos, int d){
    if(pos==1){
        insertAtHead(d,head);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt < pos-1){
        temp=temp->next;
        cnt++;
    }

    //for last node
    if(temp->next=NULL){
        insertAtTail(d,tail);
        return;
    }

    // create node
    Node* nodeToInsert=new Node(d);

    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;

    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;


}

void deleteNode(int pos,Node* &head){
    // delete start node
    if(pos==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev->next=curr->next;

        curr->next=NULL;

        delete curr;
    }
}
void print(Node* head){
    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp != NULL){
        //cout<<temp->data
        cnt++;
        temp=temp->next; 
    }
    return cnt;
}
int main(){


    Node* node1=new Node(10);
    Node* head = node1;
    Node* tail=node1;
    print(head);
    //cout<<getLength(head);

    // insertAtHead(12,head);
    // print(head);
    // insertAtHead(14,head);
    // print(head);
    // insertAtHead(33,head);
    // print(head);
    // insertAtHead(22,head);
    // print(head);


    insertAtTail(12,tail);
    print(head);
    insertAtTail(14,tail);
    print(head);
    insertAtTail(33,tail);
    print(head);
    insertAtTail(22,tail);
    print(head);


   insertAtPosition(tail,head,2,456);
   print(head);

   deleteNode(1,head);
   print(head);


    return 0;
}