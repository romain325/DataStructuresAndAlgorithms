#include "Queue.h"
#include <iostream>
using namespace std;
struct node* rear=NULL;

bool isEmpty()
{
    if( rear == NULL )
        return true;
    else
        return false;
}


bool push(int value)
    struct node *tmp= new node;
    tmp->val=value;
    if(tmp==NULL)
    {
        cout<<"\nMemory not available\n";
        return false;
    }
    if( isEmpty() ) 
    {
        rear=tmp;
        tmp->next=rear;
    }
    else
    {
        tmp->next=rear->next;
        rear->next=tmp;
        rear=tmp;
    }
    return true;

}

bool pop(){
	struct node *tmp;
    if( isEmpty() )
    {
        cout<<"\nQueue underflow\n";
        return false;
    }
    if(rear->next==rear)
    {
        tmp=rear;
        rear=NULL;
    }
    else
    {
        tmp=rear->next;
        rear->next=rear->next->next;
	}
    delete(tmp);
    return true;
}

bool printAll(){
    struct node *p;
    if(isEmpty())
    {
        cout<<"\nQueue is empty\n";
        return false;
    }
    cout<<"\nQueue is :\n";
    p=rear->next;
    do
    {
    	cout<<p->val<<" ";
        p=p->next;
    }while(p!=rear->next);
    cout<<endl;
    return true;
}
