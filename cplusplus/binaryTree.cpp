#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// make a class treat like a data type 
class node{
    public:
    // here what node contains it basically define it
        int data;
        node *left;
        node* right;

    node(int d){
        // constructor that initialize by data d and left and right is null means a single node
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildTree(node* root){
    // code for creation of a tree
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    // lets assume what node contains that basically goes on a root
    root=new node(data);

    // here for null values
    if(data==-1){
        return NULL;
    }

    // basically recursion used here for left and right
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root "<<endl;
    int data;
    cin>>data;

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

void levelOrderTraversal(node* root){

    // for level order traversal --> bfs
    // create a Queue and insert the values and pop till q is empty
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void reverseOrderTraversal(node* root){
    queue<node*> q;

    // make stack for reverset=Traversal
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(node* root){
    // left->node->right
    //base case
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrder(node* root){
    // node left right
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    //left right node

    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    // creation a tree
   /* root = buildTree(root);

    // level
    cout<<"Print levelorder "<<endl;
    levelOrderTraversal(root);

    // inorder
    cout<<"Print InOrder"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    // preOrder
    cout<<"Print preOrder"<<endl;
    preOrder(root);
    cout<<endl;

    //postOrder
    cout<<"Print postOrder"<<endl;
    postOrder(root);
    cout<<endl; */

    return 0;
}