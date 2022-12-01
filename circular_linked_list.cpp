
//ABHIJAY SRIVASTAVA
//-------------------------------------------------- CIRCULAR LINKED LIST-------------------------------------------------------- 
  // 1) traversal in circular linked list
  // 2) Insert node at head.(2 ways )
  // 3) Insert at end of list (2 solutions)
  // 4) Delete head Node
  // 5) Delete Kth node.
#include<iostream>  
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node *head)
{
    if(head==NULL)
    return;
    Node *curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    while(curr!=head);
    cout<<endl;
    
}

//---------------------------time complexity = O(n);

Node *insertAtHead(Node* head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    temp->next=temp;
    else
    {
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    temp->next=head;
    curr->next=temp;
    head=temp;
    }
    
    return temp;
}


//---------------In this the data of temp variable is swapped with head node.
// ---------------------------This is more efficient.
//-----------------------------time complexity = O(1);

Node*insertAtHead1(Node* head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int swap= head->data;
        head->data=temp->data;
        temp->data=swap;
    }
    return head;
    
    
}

//----------------insert at end of list 
//-------------------time complexity = O(n)

Node *insertAtEnd(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    temp->next=temp;
    else
    {
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    temp->next=head;
    curr->next=temp;
    head=temp;
    }
    
    return head;
}

//-----------------------------------Insert at end of list.
//--------------------------------- This is more efficient.
//-----------------------------------time complexity = O(1);


Node*insertAtEnd1(Node* head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int swap= head->data;
        head->data=temp->data;
        temp->data=swap;
        
    }
    return temp;
}   
//----------------------------------------Delete Head Node

Node *delHead(Node *head)
{
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
} 
    
//------------------------------------------- delete Kth Node

Node *deleteKth(Node *head, int k)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr=head;
        for(int i=0;i<k-2;i++)
        curr=curr->next;
        
        Node *temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        return head;
    }
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next= new Node(30);
    head->next->next->next=head;
    print(head);
    // head=insertAtHead(head,5);
    // print(head);
    // head=insertAtHead1(head,2);
    head=insertAtEnd1(head,55);
    print(head);
    deleteKth(head,3);
    print(head);
    return 0;
}

