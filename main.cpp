#include <iostream>
using namespace std;

struct Node {
    string data;
    Node * next;
};

class Linked_List {
    public:
    Linked_List();
    ~Linked_List();
    void create_node(string data);
    void delete_node(string data);
    void add_node(string data,string before);
    void delete_list();
    bool isEmpty();
    void output_list();

    private:
    Node * head;
    Node * tail;
};

Linked_List::Linked_List() {
    head = NULL;
    tail = NULL;
}
Linked_List::~Linked_List() {
    if (isEmpty() == false) {
        cout << endl;
        delete_list();
    }
    else {
        cout << "Nothing in list to delete..." << endl;
    }
}
void Linked_List::create_node(string data) { //adds to tail
    Node * temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (isEmpty() == true) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    cout << data << " added to tail..." << endl;
    output_list();
}
void Linked_List::delete_node(string data) {
    Node * temp = new Node();
    Node * temp2 = new Node();
    temp = head;
    bool valid = false;
    while(temp != NULL) {
        if (temp->data == data) {
            valid = true;
            break;
        }
        else {
            temp = temp->next;
        }
    }
    if (valid == false) {
        cout << data << " cannot be deleted since it does not exist in list..." << endl;
        delete temp2;
    }
    temp = head;
    if (valid == true) {
        while(temp != NULL) {
            if(temp->data == data) {
                cout << temp->data << " deleted..." << endl;
                temp2->next = temp->next;
                temp->next = NULL;
            }
            temp2 = temp;
            temp = temp->next;
    }
        delete temp;
    }
    output_list();
    
}
void Linked_List::add_node(string data,string before) {
    Node * temp = new Node();
    Node * temp2 = new Node();
    temp = head;
    bool valid = false;
    while(temp != NULL) {
        if (temp->data == before) {
            valid = true;
            break;
        }
        else {
            temp = temp->next;
        }
    }
    if (valid == false) {
        cout << before << " does not exist in list..." << endl;
        delete temp2;
    }
    temp = head;
    if (valid == true) {
        while (temp != NULL) {
            if (before == head->data) {
                temp2->data = data;
                temp2->next = head;
                head = temp2;
            }
            else if(before == temp->data) {
                Node * temp3 = new Node();
                temp3->data = data;
                temp2->next = temp3;
                temp3->next = temp;
            }
            temp2 = temp; //always one before
            temp = temp->next;
        }
        cout << data << " added before " << before << endl;
    }
    output_list();
}
void Linked_List::delete_list() {
    Node * temp = new Node();
    while (temp != NULL) {
        temp = head->next;
        cout << head->data << " deleted..." << endl;
        delete head;
        head = temp;
    }
    delete temp;
}
bool Linked_List::isEmpty() {
    return (head == NULL);
}
void Linked_List::output_list() {
    if(isEmpty() == true) {
        cout << "Nothing in list to output..." << endl;
    }
    else {
        Node * temp = new Node();
        temp = head;
        cout << "(head)-> ";
        while(temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "(tail)" << endl;
        delete temp;
    }
}

int main() {
    Linked_List * l1 = new Linked_List();
    char input;
    string data,before;
    
    while (true) {
        cout << "Enter 'c' to create a new node at tail, 'b' to create a new node before a node,'d' to delete a node, 'x' to exit: " << flush;
        cin >> input;
        if (input == 'c') {
            cout << "Enter data to be stored in node: " << flush;
            cin >> data;
            l1->create_node(data);
        }
        else if (input == 'b') {
            cout << "Enter data to be stored in node: " << flush;
            cin >> data;
            cout << data << " will be stored before which node?: " << flush;
            cin >> before;
            l1->add_node(data,before);
        }
        else if (input == 'd') {
            cout << "Enter the data of the node you wish to delete: " << flush;
            cin >> data;
            l1->delete_node(data);
        }
        else if(input == 'x') {
            delete l1;
            break;
        }
        else {
            cout << "'" << input << "'" << " is not a valid input..." << endl;
        }
    }
}