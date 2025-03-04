#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        ~Node();
};

class List{
    public:
        Node *root = nullptr;
        int size = 0;
        void show();
        void append(int);
        void insert(int, int);
        void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d, int idx){    
    Node *n = new Node;
    n->data = d;
    
    if(idx == 0){
        n->next = root;
        root = n;
        return;
    }
    Node *current = root;
    for(int i = 0; i < idx - 1; i++){
        if(current->next == nullptr) return;
        current = current->next;
    }
    n->next = current->next;
    current->next = n;        
}

void List::show(){
    if (!root) return;
    Node *current = root;
    cout << current->data << " ";    
    while(current->next){
        current = current->next;
        cout << current->data << " ";
    }    
    
}

void List::append(int d){    
    Node *n = new Node;
    n->data = d; n->next = nullptr;
    if(root == nullptr) root = n;
    else{
        Node *current = root;
        while(current->next){
            current = current->next;
        }
        current->next = n;
    }
    size++;
}

void List::remove(int index) {
    if (!root || index < 0 || index >= size) return; // ตรวจสอบ index ว่าถูกต้องหรือไม่

    Node *current = root;
    Node *prev = nullptr;

    if (index == 0) { // ลบโหนดแรก
        root = root->next;
    } else {
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }

    
    delete current;
    size--;
}
