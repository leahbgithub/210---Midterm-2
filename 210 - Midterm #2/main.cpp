// 210 - Midterm #2 - Leah Balakrishnan
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
class DoublyLinkedList {
private:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void push_back(string name) {
        Node* newNode = new Node(name);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(string name) {
        Node* newNode = new Node(name);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    string pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return "";
        }
        Node* temp = head;
        string name = temp->data;
        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
        delete name;
    }
    
    string pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return "";
        }
        Node* temp = tail;
        string name = temp->data;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
        delete name;
    }
    
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Current line: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void remove_random() {
        if (!head) return;
        if (prob <= 11) {
            node* temp = head;
            int pos = rand() % 3 + 1;
        }
    }
};
int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
    return 0;
}
