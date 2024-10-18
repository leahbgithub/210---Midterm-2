// 210 - Midterm #2 - Leah Balakrishnan
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

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
            int pos = rand() % 3;
            for (int i = 0; i < pos && temp; ++i) {
                temp = temp-> next;
            }
            if (temp && temp != jead && temp != tail) {
                string name = temp->data;
                cout << name << " left the line." << endl;
                if (temp-> prev)
                    temp->next->prev = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
    
    bool is_empty() {
        return head == nullptr;
    }
};

srand(static_cast<unsigned>time()));

int main() {
    DoublyLinkedList line;
    vector <string> name = load_names("names.txt");
    
    cout << "Store opens: " << endl;
    
    
    
    cout <<
    
    return 0;
}
