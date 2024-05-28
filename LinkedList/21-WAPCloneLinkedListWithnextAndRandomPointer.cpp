#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *arb;

    Node() {
        this->data = 0;
        this->next = nullptr;
        this->arb = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->arb = nullptr;
    }

    ~Node() {
        cout << "Node with value " << this->data << " deleted" << endl;
    }
};

void PrintNode(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *Helper(Node *&head, unordered_map<Node*, Node*> &mp) {
    if (head == nullptr) {
        return nullptr;
    }
    Node *newhead = new Node(head->data);
    mp[head] = newhead;
    newhead->next = Helper(head->next, mp);
    if (head->arb) {
        newhead->arb = mp[head->arb];
    }
    return newhead;
}

Node *copyList(Node *head) {
    unordered_map<Node*, Node*> mp;
    return Helper(head, mp);
}



int main() {
    Node *first = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(19);
    Node *fourth = new Node(28);
    Node *fifth = new Node(7);
    Node *sixth = new Node(8);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    // Set arbitrary pointers
    first->arb = third;
    second->arb = first;
    third->arb = sixth;
    fourth->arb = second;
    fifth->arb = fourth;
    sixth->arb = fifth;

    cout << "Original List:" << endl;
    PrintNode(first);

    Node *copiedListHead = copyList(first);

    cout << "\nCopied List:" << endl;
    PrintNode(copiedListHead);
}
