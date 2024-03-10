#include <iostream>
#include <climits>

using namespace std;



#define NONE (INT_MAX)

class Heap{
private:
    int no_of_elements=0;
    int top=-1;
    int* heap;
    int max;
public:
    Heap(int N) {
        heap = new int[N];
        max = N;
    }
    void Insert(int);
    int Pop();

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
    else if(top!=max-1){
        top++; no_of_elements++;
        heap[top] = val;
        int parent_index = (top-1)/2;
        int index = top;
        // Keep adjusting the heap by replacing the parent with the child until the child is no longer smaller than the parent
        while (val<heap[parent_index] && index>0){
            int temp = heap[index];
            heap[index] = heap[parent_index];
            heap[parent_index] = temp;
            index = parent_index;
            parent_index = (index-1)/2;
        }
    }
}
int Heap::Pop() {
    int temp=0;
    if (top==0) {
        temp = heap[top];
        heap[top] = NONE;
        top--; no_of_elements--;
        return temp;
    }
    else if (no_of_elements==0){
        return -1;
    }
    else {
        temp = heap[0];
        heap[0] = heap[top];
        heap[top] = NONE;
        top--; no_of_elements--;
        int index=0;
        int child_index = (index*2)+1;
        // Compare if the data of the parent is smaller than either of its children
        while ((heap[index]>heap[child_index] || heap[index] > heap[child_index+1])&& child_index<=top){
            // Compare which one of the children is greater and replace that with the parent
            if (heap[child_index]<heap[child_index+1]){
                int temp2 = heap[index];
                heap[index] = heap[child_index];
                heap[child_index] = temp2;
                index = child_index;
                child_index = (index*2)+1;
            }
            else{
                int temp2 = heap[index];
                heap[index] = heap[child_index+1];
                heap[child_index+1] = temp2;
                index = child_index+1;
                child_index = (index*2)+1;
            }
        }
        return temp;

    }
}



int main() {

    int N, val, v1, v2, res;
    while(cin>>N) {
        res = 0; v1=0; v2=0;
        Heap* heap = new Heap(N);
        for (int i =0; i < N; i++) {
            cin >> val;
            heap->Insert(val);
        }
        while(true) {
            v1 = heap->Pop();
            v2 = heap->Pop();
            if (v2==-1) {
                break;
            }
            res+= v1+v2;
            heap->Insert(v1+v2);
        }
        cout << res << endl;
        delete heap;
    }
}
