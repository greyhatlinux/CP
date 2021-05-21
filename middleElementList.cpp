#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)

class Node
{
    public:
    int data;
    Node *next;
};

void insertAtEnd(Node **head, int value) {

    if(*head == NULL) {
        // starting the list
        // cout<<"hi";
        Node *new_node = new Node();
        new_node->data = value;
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;
    Node *ptr = *head;

    while(ptr->next!= NULL) ptr = ptr->next;
    ptr->next = new_node;
}

void printList(Node *head) {
    if(!head) {
        cout<<"Empty list\n";
        return;
    }
    while(head) {
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL\n";
}

void findMiddle(Node *head) {
    if(!head) cout<<"Empty List\n";
    Node *sptr, *fptr;

    sptr = head->next;
    fptr = head->next->next;

    while(fptr->next != NULL && fptr->next->next != NULL ){
        fptr = fptr->next->next;
        sptr = sptr->next;
    }

    //case of even nodes, so there will be 2 middle elements
    if(fptr->next != NULL ) cout<<"Middle elements are : "<<sptr->data<<" and "<<sptr->next->data<<endl;
    //case of odd number of nodes
    else cout<<"Middle element is : "<<sptr->data<<endl;
}

int main()
{
    int tc; cin>>tc; while(tc--){
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];

        Node *head = NULL;
        fi(0,n) insertAtEnd(&head, arr[i]);
        printList(head);
        findMiddle(head);
    }

    return 0;
}
