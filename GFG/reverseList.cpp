#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
};

void insertAtStart(Node **head, int val) {
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

int listLength(Node *head) {
    int length=0;
    while(head) {
        head = head->next;
        length++;
    }
    return length;
}
void printList(Node *head) {
    if(!head) {
        cout<<"Empty list\n"; 
        return; 
    }
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

void reverseTheList(Node **head) {
    Node *start, *end;
    end = start = *head;

    int len = listLength(*head);

    int i=0, arr[len];   
    for(int i=0;i<len;i++){
        arr[len-1-i] = start->data;
        start = start->next;
    }

    Node *new_head = NULL;
    for(int i=0;i<len;i++) insertAtStart(&new_head, arr[len-1-i]);

    *head = new_head;
}

void reverseTheListInplace(Node **head) {
    Node *nxt, *curr, *prev;
    curr = *head;
    prev = nxt = NULL;

    while(curr!=NULL) {

        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        
    }
    *head = prev;
}


int main()
{   
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int val[n];
        for(int i=0;i<n;i++) cin>>val[i];

        Node *head = NULL;
        for(int i=0;i<n;i++) insertAtStart(&head, val[i]);

        cout<<"Original List : ";
        printList(head);
        cout<<endl;

        // reverseTheList(&head);
        reverseTheListInplace(&head);

        cout<<"Reversed list : ";
        printList(head);
        cout<<endl<<endl;
    }

    return 0;
}


// This reverses the list in O(N) time, but sace complexity is O(N) [but GFG says it will have O(1) space complexity]
// The inplace-reversing also takes O(N) time, but takes no extra space for storing the value. It changes the pointers in-place.
