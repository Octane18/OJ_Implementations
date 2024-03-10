#include <iostream>

using namespace std;


class Stack{
private:
    int top=-1;
    int* stack= nullptr;
public:
    Stack(int);
    void createStack(const int*, int);
    void Push(int);
    int Pop();
    int returnTop();
    bool isEmpty() const;
    ~Stack();
};
Stack::Stack(int size) {
    stack = new int[size];
}
void Stack::createStack(const int *arr, int size) {

    for (int i = 0; i < size; i++) {
        stack[i] = arr[i];
    }
    top = size-1;

}
void Stack::Push(int val) {
    top++;
    stack[top] = val;
}
int Stack::Pop() {
    if(top== -1) {
        return -1;
    }
    else{
        int ret = stack[top];
        top--;
        return ret;
    }

}
int Stack::returnTop() {
    return stack[top];
}
bool Stack::isEmpty() const {
    if(this->top== -1) {
        return true;
    }
    return false;
}
Stack::~Stack() {
    delete [] stack;
}

int main() {
    int T=0, N=0, perm=0;
    bool isFound;
    int *arr, *B;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
         
        cin >> N;
        Stack *A = new Stack(N), *S = new Stack(N);
        arr = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        A->createStack(arr, N);
        cin >> perm;
        B = new int[N];
        for (int j = 0; j < perm; j++) {
            int count = 0;
            for (int k = 0; k < N; k++) {
                cin >> B[k];
            }
            S->Push(A->Pop());
            while(S->returnTop()!=B[count]){
                S->Push(A->Pop());
            }
            count++; S->Pop();
            while(!A->isEmpty()){
                isFound = false;
                if (A->returnTop()==B[count]){
                    S->Push(A->Pop());
                    S->Pop();
                    isFound = true;
                    count++;
                }
                else if(S->returnTop()==B[count]){
                    S->Pop();
                    count++;
                    isFound = true;
                }
                else {
                    S->Push(A->Pop());
                }
            }
            while(!S->isEmpty()){
                isFound = false;
                if(S->returnTop()!=B[count]){
                    S->Pop();
                }
                else {
                    S->Pop();
                    count++;
                    isFound = true;
                }
            }
            if(isFound&&count>=N) {
                cout << "Aye" << endl;

            }
            else {
                cout << "Impossible" << endl;
            }


            A->createStack(arr, N);

        }
        delete A; delete S;
        delete [] B;
        delete [] arr;
    }
}