#include<iostream>
using namespace std;

class node{

    public:

    int val;
     node* next;

    node(int data){
        this -> val = data;
        this -> next = NULL;
    }

};

int Length(node* &head){

    node* temp = head;
    int count = 0;
    while( temp != NULL){
        count++;
        temp = temp -> next;
    }

    return count;
}

void InsertAtStart(node* &head , int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        return;
    }
    Newnode -> next = head;
    head = Newnode;

}

void InsertAtLast(node* &head , int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        return;
    }

    node* helper = head;
    while(helper -> next != NULL){
        helper = helper -> next;
    }

    helper -> next = Newnode;

}

void InsertAtIndex(node* &head , int data , int index){

    if(index > Length(head)){
        cout<<endl<<"Index is greater than the total Length."<<endl<<endl;
        return;
    }
    if(index == 0){
        InsertAtStart(head, data);
        return;
    } 
    if(index == Length(head)){
        InsertAtLast(head, data);
    }    
    
    node* Newnode = new node(data);

    node* BeforeIndex = head;
    for(int i = 0; i < index-1; i++){
        BeforeIndex = BeforeIndex -> next;
    }

    Newnode -> next = BeforeIndex -> next;
    BeforeIndex -> next = Newnode;

}

void PrintList(node* &head){

    node* temp = head;

    while(temp != NULL){
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }cout<<endl;

}

void DeleteFromStart(node* &head){
    
    if(head == NULL)    return;

    node* temp = head;
    head = temp -> next;
    temp -> next = NULL;

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

    if(head == NULL)    return;

    if( index >Length(head)-1 ){
        cout<<endl<<endl<<"Index is greater then total Length."<<endl<<endl;
    }

        node* BeforeIndex = head;
        for(int i = 0; i < index-1 ; i++){
            BeforeIndex = BeforeIndex -> next;
        }

        node* Current = BeforeIndex -> next;

        BeforeIndex -> next = Current -> next;

        delete Current;

}

int main(){

    node* head = NULL;

    InsertAtStart(head,10);
    PrintList(head);
    InsertAtStart(head,20);
    PrintList(head);
    InsertAtStart(head,30);
    PrintList(head);
    InsertAtStart(head,40);
    PrintList(head);
    InsertAtStart(head,50);
    PrintList(head);

    InsertAtIndex(head,1,3);
    PrintList(head);

    DeleteAnIndex(head,2);
    PrintList(head);

    DeleteFromLast(head);
    PrintList(head);

    DeleteFromStart(head);
    PrintList(head);

    return 0;
}