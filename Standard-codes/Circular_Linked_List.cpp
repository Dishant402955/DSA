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

    if(head == NULL)    return count;

    temp = temp -> next;
    count++;

    while( temp != head){
        count++;
        temp = temp -> next;
    }

    return count;
}


void InsertAtStart(node* &head , int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        Newnode -> next = head;
        return;
    }

    node *temp = head;
    while( temp -> next != head){
        temp = temp -> next;
    }

    Newnode -> next = head;
    head = Newnode;
    temp -> next = Newnode;

}


void InsertAtLast(node* &head , int data){

    node* Newnode = new node(data);

    if(head == NULL){
        head = Newnode;
        Newnode -> next = head;
        return;
    }

    node* helper = head;
    while(helper -> next != head){
        helper = helper -> next;
    }

    helper -> next = Newnode;
    Newnode -> next = head;

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

    if(head == NULL)    return;

    node* temp = head;


    do{
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }while(temp != head);

    cout<<endl;

}


void DeleteFromStart(node* &head){
    
    if(head == NULL)    return;

    if(head -> next == head){
        delete  head;
        head = NULL;
        return;
    }

    node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }

    temp -> next = head -> next;

    node* helper = head;
    head = head -> next;

    delete helper;


}


void DeleteFromLast(node* &head){

    if(head == NULL)    return;

    if(head -> next == head){
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while( temp -> next -> next != head){
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = head;
    
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

    InsertAtLast(head,30);
    PrintList(head);

    InsertAtIndex(head,40,2);
    PrintList(head);

    DeleteAnIndex(head,2);
    PrintList(head);
    
    DeleteFromStart(head);
    PrintList(head);

    DeleteFromLast(head);
    PrintList(head);

    return 0;
}