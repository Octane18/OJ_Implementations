#include <iostream>

using namespace std;
class Node{
public:
    int pos;
    Node* next;
};

class LinkedList{


public:
    int no_of_elements=0;
    void create(int);
    int Delete(Node*, Node*);
    Node* base;

};
void LinkedList::create(int size) {
    Node* new_node = new Node;
    Node* temp;
    no_of_elements = size;
    new_node->pos = 1;
    base = new_node;
    for (int i = 1; i<size-1; i++){
        temp = new_node;
        new_node = new Node;
        new_node->pos = i+1;
        temp->next = new_node;

    }
    temp = new_node;
    new_node = new Node;
    new_node->pos = size;
    temp->next = new_node;
    new_node->next = base;
}
int LinkedList::Delete(Node* prev, Node* current) {
    prev->next = current->next;
    int r_val = current->pos;
    delete current;
    no_of_elements--;
    return r_val;
}

int main() {
    int n,m;
    cin >> n;
    LinkedList list;
    Node* current;
    Node* prev;
    list.create(n);
    cin >> m;
    current = list.base;
    bool isFirst = true;
    while(list.no_of_elements!=0) {

        for (int i = 1; i<m;i++) {
            prev = current;
            current = current->next;
        }
        if(isFirst) {
            cout << list.Delete(prev, current);
            isFirst = false;
        }
        else {
            cout << " " << list.Delete(prev, current);
        }
        current = prev->next;
    }
    cout << endl;
    return 0;

}

