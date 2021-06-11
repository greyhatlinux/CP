// Question :
// Sorted Linked List given like above where each node has 2 pointers left and down. 
// For each row starting nodes down points to next row start. 
// Each row has 4 elements, except last one which can have <= 4 elements. 
// Next rows start element is greater than previous rows end element. 
// We need to design and code for it insert of new value at correct place, delete, as well as search operation on the data structure.

// 2->7->8->11
// |
// 13->16->17->21
// |
// 22->23->27->29
// |
// 30->32



#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

class Node
{
    public:
    int data;
    Node *next;

    public:
    Node(int n) {
        data = n;
        next = NULL;
    }

    void NodePush(Node *head, int value) {
        
        //with this loop, we reach the target node where new node is to be added
        while(head->next!=NULL) head = head->next;

        Node *temp = new Node(value);
        head->next = temp;
    }
};

class HeadNode
{
    // public:
    int data, mx = INT_MIN, size;
    Node *next;
    HeadNode *down;

    public:
    HeadNode(int n) {
        data = n;
        size = 0;
        next = NULL;
        down = NULL;
    }

    void pushNode(HeadNode *head, int value) {
        //if this is the first node being entered
        if(head->next == NULL) {
            head->data = value;
            head->mx = value;
            (head->size)++;
            return;
        }

        //this indicates we're adding values in last row (which dosen't has any down rows)
        //with this loop, we'll reach the last row
        while(head->down!=NULL)  head = head->down;

        //this is the case, where the last row is full, so we need to add a row below
        if(head->size == 4 && head->mx < value) {
            HeadNode *temp = new HeadNode(value);
            head->down = temp;
            (temp->size)++;
            return;
        }

        // if new value is smaller than last value of above list, and the last row is full
        if(head->size == 4 && head->mx > value) {
            HeadNode *temp = new HeadNode(value);

            Node *newNode = new Node(head->data);
            newNode->next = head->next;
            temp->next = newNode;

            head = temp;   
            delete(temp);

            HeadNode *temp = new HeadNode(value);
            head->down = temp;
            (temp->size)++;
            return;
        }


        //normal node addition at the end
        Node *temp = new Node(value);
        temp = head->next;

        Node lastnode(value);
        lastnode.NodePush(temp, value);

        // list size of last row increases by 1
        (head->size)++;
    }   

    //TC: O(N)
    void delteNode(HeadNode *head, int value) {

    }

    //TC : O(N) but will be faster on average case
    void searchNode(HeadNode *head, int value) {

    }
};


int main()
{

    return 0;
}

