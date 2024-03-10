#include <iostream>

using namespace std;

#define NONE (-999)

class Heap{
private:
    int no_of_elements=0;
    int top=-1;
    int* heap;
public:
    Heap(int N){
        heap = new int[N];
    }
    void Insert(int);
    void Pop();
    int calcSum();
    ~Heap(){
        delete [] heap;
    }

};

void Heap::Insert(int val) {
    if (top==-1) {
        top++;
        heap[top] = val;
        no_of_elements++;
    }
    else{
        top++; no_of_elements++;
        heap[top] = val;
        int parent_index = (top-1)/2;
        int index = top;
        // Keep adjusting the heap by replacing the parent with the child until the child is no longer smaller than the parent
        while (val>heap[parent_index] && index>0){
            int temp = heap[index];
            heap[index] = heap[parent_index];
            heap[parent_index] = temp;
            index = parent_index;
            parent_index = (index-1)/2;
        }
    }
}
void Heap::Pop() {
    if (top==0) {
        heap[top] = NONE;
        top--; no_of_elements--;
    }
    else if (no_of_elements==0){
        cout << "Empty heap." << endl;
    }
    else {
        heap[0] = heap[top];
        heap[top] = NONE;
        top--; no_of_elements--;
        int index=0;
        int child_index = (index*2)+1;
        // Compare if the data of the parent is smaller than either of its children
        while ((heap[index]<heap[child_index] || heap[index] < heap[child_index+1])&& child_index<=top){
            // Compare which one of the children is greater and replace that with the parent
            if (heap[child_index]>heap[child_index+1]){
                int temp = heap[index];
                heap[index] = heap[child_index];
                heap[child_index] = temp;
                index = child_index;
                child_index = (index*2)+1;
            }
            else{
                int temp = heap[index];
                heap[index] = heap[child_index+1];
                heap[child_index+1] = temp;
                index = child_index+1;
                child_index = (index*2)+1;
            }
        }

    }
}
int Heap::calcSum() {
    int sum=0;
    for (int i = 0; i < no_of_elements; i++) {
        sum += heap[i];
    }
    return sum;
}


int main() {
    int num_op, val;
    char op;

    while(cin >> num_op) {

        Heap* heap= new Heap(num_op);
        for (int i = 0; i<num_op; i++) {
            cin >> op;
            switch (op) {
                case 'a':
                    cin >> val;
                    heap->Insert(val);
                    break;
                case 'p':
                    heap->Pop();
                    break;
                case 'r':
                    cout << heap->calcSum() << endl;
                    break;
                default:
                    break;

           }

        }
        delete heap;

    }

}
