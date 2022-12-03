#include <stdio.h>
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

struct Node{
    
    int data;
    Node *next; 
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void printMid(Node *head)
{
    if(head==NULL)
      return;
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data;
}


int main() {
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(4);
    head->next->next->next=new Node(45);
    head->next->next->next->next=new Node(45);
    print(head);
    printMid(head);
    cout<<endl<<"Code by - Abhijay Srivastava";
}
