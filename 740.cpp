#include <iostream>

using namespace std;
class Node{

public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;

    }
};

class LinkedList{
private:
    Node* root= nullptr;
public:
    void createList(int size, int* arr_data);
    void Insert(int val, int pos);
    void Delete(int index);
    void Reverse(int i, int j);
    int Query(int i);

};
void LinkedList::createList(int size, int* arr_data) {
    Node* new_node = new Node();
    Node* temp;
    root = new_node;
    int counter=0;
    while(counter<size){
        new_node->data = arr_data[counter];
        temp = new_node;
        new_node = new Node();
        temp->next = new_node;
        counter++;
    }
    temp->next = nullptr;
}




void LinkedList::Insert(int val, int pos) {
    Node* new_node = new Node();
    Node* current;
    int pos_count=1;
    new_node->data = val;
    current = root;
    while (current->next != nullptr){
        if(pos_count==pos) {
            Node* temp;
            temp = current->next;
            current->next = new_node;
            new_node->next = temp;
            break;
        }
        current = current->next;
        pos_count++;

    }

}

void LinkedList::Delete(int index) {
    int pos_count = 1;
    bool deleted = false;
    Node *current;
    Node *temp;
    current = root;
    if (index == 1) {
        root = current->next;
        delete current;
        deleted = true;
    }
    while (current != nullptr && !deleted) {
        temp = current;
        current = current->next;
        pos_count++;
        if (pos_count == index) {
            temp->next = current->next;
            delete current;
            break;
        }
    }

}

void LinkedList::Reverse(int i, int j) {
    Node* arr[j-i+1];
    Node* temp;
    Node* temp2;
    int pos=1;
    temp = root;
    while (pos<i-1) {
        temp = temp->next;
        pos++;
    }
    if (i >1) {
        temp2 = temp->next;

    }
    else {
        temp2 = temp;
    }


    for (int x = 0; x<(j-i+1); x++){
        arr[x] = temp2;
        temp2 = temp2->next;
    }
    arr[0]->next = arr[j-i]->next;
    for (int x = (j-i); x>=1; x--){
        arr[x]->next = arr[x-1];
    }
    if (i>1) {
        temp->next= arr[j-i];

    }
    else {
        root = arr[j-i];
    }
}


int LinkedList::Query(int i) {
    int pos=1;
    Node* current;
    current = root;
    while(current!= nullptr) {
        if (pos==i) {
            return current->data;
        }
        current= current->next;
        pos++;
    }
    return -1;
}


int main() {
    LinkedList list;
    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    list.createList(N, arr);
    int num_op = 0; cin >> num_op;
    for (int i = 0; i<num_op; i++) {
        int option=0, index=0, val=0, index2 =0;
        cin >> option;
        switch (option) {
            case 1:
                cin >> index >> val;
                list.Insert(val, index);
                break;
            case 2:
                cin >> index;
                list.Delete(index);
                break;
            case 3:
                cin >> index >> index2;
                list.Reverse(index, index2);
                break;
            case 4:
                cin >> index;
                cout << list.Query(index) << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    }

}
