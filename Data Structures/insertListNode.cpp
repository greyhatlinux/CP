#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)

class Node
{
    public:
    int data;
    Node *next;
};

void insertAtStart(Node **head, int value){
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insertAtEnd(Node **head, int value) {

    if(*head == NULL) {
        // starting the list
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

int main()
{
    int tc; cin>>tc; while(tc--){
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];

        Node *head = NULL;
        // fi(0,n) insertAtEnd(&head, arr[i]);
        fi(0,n) insertAtStart(&head, arr[i]);
        printList(head);

    }

    return 0;
}
