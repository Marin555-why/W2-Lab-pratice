#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class linked_list {
    Node* head;
public:
void swap(int pos1, int pos2) {
    if (pos1 == pos2) return;
    Node *prev1 = nullptr, *curr1 = head;
    for (int i = 0; i < pos1 && curr1; ++i) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    Node *prev2 = nullptr, *curr2 = head;
    for (int i = 0; i < pos2 && curr2; ++i) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if (!curr1 || !curr2) return;
    if (prev1) prev1->next = curr2; else head = curr2;
    if (prev2) prev2->next = curr1; else head = curr1;
    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}
void search(int val) {
    Node* temp = head;
    int pos = 0;
    while (temp) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << val << " not found in the list." << endl;
}

    linked_list() : head(nullptr) {}
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insert_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insert_end(int val) {
        Node* newNode = new Node(val);
        if (!head) {
        head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insert_middle(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; ++i){
            temp = temp->next;
        }
        if (temp) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            delete newNode; 
    }
}
void delete_front() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
void delete_end() {
    if (!head) return;
    if (!head->next) {
        delete head ;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
    temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}
void delete_middle(int pos) {
    if (pos == 0 && head) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; ++i) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

void display(){
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
            }
            cout << "nullptr\n" << endl;
        }
    };
