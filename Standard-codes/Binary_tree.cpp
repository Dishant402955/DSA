#include<iostream>
using namespace std;

class node{

    public:

    int val;
    node* left;
    node* right;

    node(int data){
        this -> val = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void InOrder (node* root){

    if(root == NULL)
        return;

    InOrder(root -> left);
    cout<<root -> val<<" ";
    InOrder(root -> right);

}

void PreOrder (node* root){

    if(root == NULL)
        return;

    cout<<root -> val<<" ";
    PreOrder(root -> left);
    PreOrder(root -> right);

}

void PostOrder (node* root){

    if(root == NULL)
        return;

    PostOrder(root -> left);
    PostOrder(root -> right);
    cout<<root -> val<<" ";

}


node* Build_Tree(node* root){

    int data;
    cout<<"Enter the Data : ";
    cin >> data;

    if( data == -1){
        return NULL;
    }
    
    root = new node(data);

    cout<<endl<<"Insertion in the left side of the node "<<root -> val<<" : "<<endl;
    root -> left = Build_Tree(root -> left);

    cout<<endl<<"Insertion in the right side of the node "<<root -> val<<" : "<<endl;
    root -> right = Build_Tree(root -> right);
    

    return root;
}


int main(){

    node* root = NULL;

    root = Build_Tree(root);

    cout<<endl<<"InOrder Traversal : ";
    InOrder(root);
    cout<<endl;
    
    cout<<endl<<"PreOrder Traversal : ";
    PreOrder(root);
    cout<<endl;

    cout<<endl<<"PostOrder Traversal : ";
    PostOrder(root);
    cout<<endl;
    
    return 0;
}