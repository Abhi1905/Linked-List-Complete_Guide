//ABHIJAY SRIVASTAVA

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


Node *sortedIsert(Node *head,int d)
{
    Node *temp=new Node(d);
    if(head==NULL)
    return temp;
    if(head->data>d){
        temp->next=head;
        return temp;
    }
    
        Node *curr=head;
        while(curr->next!=NULL && curr->next->data<d  )
        {
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    
    return head;
}

int main() {
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(4);
    head->next->next->next=new Node(45);
    sortedIsert(head,5);
    print(head);
}

