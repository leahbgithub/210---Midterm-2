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
        int prob = rand() % 100 + 1;
        if (prob <= 10) {
            Node* temp = head;
            int pos = rand() % 3 + 1;
            for (int i = 0; i < pos && temp; ++i) {
                temp = temp-> next;
            }
            if (temp && temp != head && temp != tail) {
                string name = temp->data;
                cout << name << " left the line." << endl;
                if (temp->prev)
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

vector <string> load_names(const string&filename) {
    vector<string> name;
    ifstream file(filename);
    string name;
    while (file >> name) {
        names.push_back(name);
    }
    return names;
}

int main() {
    srand(static_cast<unsigned>time(0)));
    
    DoublyLinkedList line;
    vector <string> name = load_names("names.txt");
    
    cout << "Store opens: " << endl;
    
    for (int i = 0; i < 5; ++i) {
        string customer = names[rand() % names.size()];
        line.push_back(customer);
        cout << customer << " joins the line" << endl;
    }
    
    line.print();
    
    for (int time = 0; time <= 20; ++time) {
        cout << "Time step #" << time << ":" << endl;
        
        //60% chance of new customer joining end of the line
        prob = rand() % 100;
        if (prob <= 60) {
            string new_customer = names[rand() % names.size()];
            line.push_back(new_customer);
            cout << new_customer << " joins the line" << endl;
        }
        
        // 40% chance that first customer is served
        int prob = rand() % 100;
        if (prob <= 40 && !line.is_empty()) {
            string served_customer = line.pop_front();
            cout << served_customer << " is served" << endl;
        }
        
        
    }
    
    cout <<
    
    return 0;
}
