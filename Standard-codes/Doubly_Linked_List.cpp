#include<iostream>
using namespace std;

class node{

    public: 

    int val;
    node* next;
    node* previous;

    node(int data){
        this -> val = data;
        this -> next = NULL;
        this -> previous = NULL;
    }
};


int Length(node* & head){
    int count = 0;

    node* temp = head;

    while( temp != NULL){
        temp = temp -> next;
        count++;    
    }

    return count;
}


void InsertAtStart(node* &head, int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        return;
    }

    node* Current = head;

    head = Newnode;
    Current -> previous = Newnode;
    Newnode -> next = Current;

}


void InsertAtLast(node* &head, int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        return;
    }

    node* Current = head;

    while(Current -> next != NULL){
        Current = Current -> next;
    }

    Current -> next = Newnode;
    Newnode -> previous = Current;

}


void InsertAtIndex(node* &head, int data, int index){

    node* Newnode = new node(data);

    if(index > Length(head)){
        cout<<endl<<endl<<"Invalid Index to insert a node"<<endl<<endl;
        return;
    }
    if(index == 0){
        InsertAtStart(head,data);
        return;
    }
    if(index == Length(head)){
        InsertAtLast(head,data);
        return;
    }

    node* BeforeIndex = head;
    for(int i = 0 ; i < index ; i++ ){
        BeforeIndex = BeforeIndex -> next;
    }

    Newnode -> next = BeforeIndex -> next ;
    Newnode -> previous = BeforeIndex;

    BeforeIndex -> next -> previous = Newnode;
    BeforeIndex -> next = Newnode;

}


void DeleteFromStart(node* &head){

    if(head == NULL)    return;

    node* temp = head;
    head = temp -> next;

    if(head != NULL)
        head -> previous = NULL;

    delete temp;

}


void DeleteFromLast(node* &head){

    if(head == NULL)    return;

    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;

    while( temp -> next -> next != NULL){
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = NULL;

}


void DeleteAnIndex(node* &head, int index){

    if(index >= Length(head)){
        cout<<endl<<endl<<"Invalid Index for deletion "<<endl<<endl;
        return;
    }
    if(index == 0){
        DeleteFromStart(head);
        return;
    }
    if(index == Length(head)-1){
        DeleteFromLast(head);
        return;
    }

    node* BeforeIndex = head;

    for(int i = 0 ; i < index-1 ; i++){
        BeforeIndex = BeforeIndex -> next;
    }

    node* temp = BeforeIndex -> next;

    temp -> next -> previous = BeforeIndex;
    BeforeIndex -> next = temp -> next;

    delete temp;
    
}


void PrintList(node* &head){

    node* temp = head;

    while( temp != NULL){
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }cout<<endl;

}


int main(){

    node* head = NULL;

    InsertAtStart(head,10);
    PrintList(head);

    InsertAtLast(head,20);
    PrintList(head);

    InsertAtStart(head,50);
    PrintList(head);

    InsertAtStart(head,60);
    PrintList(head);

    InsertAtIndex(head,2,2);
    PrintList(head);

    DeleteFromStart(head);
    PrintList(head);

    DeleteFromLast(head);
    PrintList(head);

    DeleteAnIndex(head,1);
    PrintList(head);

    return 0;
}