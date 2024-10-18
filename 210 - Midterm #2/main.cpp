// 210 - Midterm #2 - Leah Balakrishnan
#include <iostream> // This is for input/output
#include <cstdlib> // rand() for random numbers
#include <ctime> // to seed random number with time
#include <vector> // store list of customer names
#include <fstream> // file input operations for reading customer names

using namespace std;

// class which will represent doubly linked list of coffee shop line
class DoublyLinkedList {
private:
    // node structure which will represent the customer in the line
    struct Node {
        string data; // customer name stored as string
        Node* prev; // pointer to previous node in list
        Node* next; // pointer to next node in list
        // node constructor which will intitialize data and maaybe the prev and next pointers
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head; // points to first node
    Node* tail; // points to last node
public:
    //constructor which will intialize empty doubly linked list
    DoublyLinkedList() {
        head = nullptr; // sets head to nullptr
        tail = nullptr; // sets tail to nullptr
    }
    
    //This will add customer to back of line
    void push_back(string name) {
        Node* newNode = new Node(name); // create new node for customer
        if (!tail) // if list empty, both head and tail will point to new node
            head = tail = newNode; // set head to new node
        else { // link new node to current tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // This will add VIP customer to front of line
    void push_front(string name) {
        Node* newNode = new Node(name); // create new node for VIP
        if (!head) // if list empty, head and tail will go to new node
            head = tail = newNode;
        else { // link new node to current head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    //Will remove and return the customer at the front of the line
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
        } else {
            head = tail = nullptr;
        }
        delete temp;
        return name;
    }
    
    // Will remove customer from the back of the line
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
        } else {
            head = tail = nullptr;
        }
        delete temp;
        return name;
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
    
    // this will remove random customer from middle of line (10% chance)
    void remove_random() {
        if (!head) return; //if list empty, dont do anything
        int prob = rand() % 100 + 1; // generate random number between 1 and 100
        if (prob <= 10) { // less than or equal to 100, remove customer
            Node* temp = head; // start from head
            int pos = rand() % 3 + 1; // generate random position between 1 and 3
            for (int i = 0; i < pos && temp; ++i) { // move selected position in list
                temp = temp-> next;
            }
            if (temp && temp != head && temp != tail) { // make sure head or tail isnt remove
                string name = temp->data; // get name of customer that leaves
                cout << name << " left the line." << endl; // print customer left the line
                if (temp->prev) // update previous nodes pointer
                    temp->next->prev = temp->next;
                if (temp->next) // update next nodes previous pointer
                    temp->next->prev = temp->prev;
                delete temp; // free memory
            }
        }
    }
    
    //will check if list empty
    bool is_empty() {
        return head == nullptr; // return true if head is nullptr which means list empty
    }
};

// this function will load names from file into a vector
vector <string> load_names(const string& filename) {
    vector<string> names; // create empty vector for storing names
    ifstream file(filename); // open file with list of names
    string name; // temporary string to hold each name
    while (file >> name) { // read names from file
        names.push_back(name);
    }
    return names; // return vector of names
}

// main program
int main() {
    srand(static_cast<unsigned>(time(0))); // seed random number generator with time
    
    DoublyLinkedList line; // create empty doubly linked list for coffee line
    
    vector <string> names = load_names("names.txt"); // will load customer names from file
    
    cout << "Store opens: " << endl;
    
    // this will add 5 additional customers
    for (int i = 0; i < 5; ++i) {
        string customer = names[rand() % names.size()]; // select random customer name
        line.push_back(customer); // adds customer to end of line
        cout << customer << " joins the line" << endl; //prints customer joined the line
    }
    
    line.print(); // print current line
    
    // 20 time periods in minutes need to be created
    for (int time = 1; time <= 20; ++time) {
        cout << "Time step #" << time << ":" << endl;
        
        // 40% chance that first customer is served
        int prob = rand() % 100 + 1; // generate random number between 1 and 100
        if (prob <= 40 && !line.is_empty()) { // if random number is less than or equal to 40 and line isnt empty
            string served_customer = line.pop_front(); // first customer done
            cout << served_customer << " is served" << endl; // print customer served
        }
        
        //60% chance of new customer joining end of the line
        prob = rand() % 100 + 1; // generate random number
        if (prob <= 60) {
            string new_customer = names[rand() % names.size()]; // select random customer name
            line.push_back(new_customer); // add customer to end of line
            cout << new_customer << " joins the line" << endl; // print customer joined the line
        }
        
        //20% chance of last customer leaving the line
        prob = rand() % 100 + 1;
        if (prob <= 20 && !line.is_empty()) {
            string last_customer = line.pop_back(); // remove last customer from line
            cout << last_customer << " at the end has left the line" << endl; // prints
        }
        
        //10% chance of VIP customer that will skip to the front of line
        prob = rand() % 100 + 1;
        if (prob <= 10) {
            string vip_customer = names[rand() % names.size()]; // select VIP customer at random
            line.push_front(vip_customer); // add VIP to the front
            cout << vip_customer << " (VIP) joined the front of the line" << endl; // Print VIP joined
        }
        
        // 10% chance that a customer leaves the line at random
        line.remove_random();
        
        line.print(); // Will print current line at end of the time step
    }
    
    return 0; // terminate the program
}
