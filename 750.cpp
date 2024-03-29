#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
private:
    int data;
    int parent;
public:
    TreeNode(int d, int p) {
        data =d;
        parent = p;
    }
    int get_parent() const {
        return parent;
    }
    int get_data() const {
        return data;
    }
};

int main() {

    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        vector<TreeNode*> arr;
        int root=0, N=0;
        cin >> root >> N;
        TreeNode* rt = new TreeNode(root, -1);
        arr.push_back(rt);
        for (int j=0; j < N-1; j++) {
            int data, parent;
            cin>> data >> parent;
            TreeNode* Tr = new TreeNode(data, parent);
            arr.push_back(Tr);
        }
        int d1=0, d2=0;
        TreeNode* t1= nullptr, *t2= nullptr;
        cin >> d1 >> d2;
        for(TreeNode* t: arr){
            if(t->get_data()==d1 && t1== nullptr){
                t1 = t;


            }
            else if (t->get_data()==d2 && t2== nullptr){
                t2 = t;
            }
            if(t1 != nullptr && t2 != nullptr) {
                break;
            }
        }
        vector<int> p1, p2;
		p1.push_back(d1);
		p2.push_back(d2);
        int parent;
        if(d1==root) {
            parent = -1;
            p1.push_back(root);
        }
        else {
            parent = t1->get_parent();
        }
        while(parent!=-1) {
            p1.push_back(parent);
            for(TreeNode* t: arr) {
                if(t->get_data()==parent) {
                    t1 = t;
                    break;
                }
            }
            parent = t1->get_parent();
        }
        if(d2==root) {
            parent = -1;
            p2.push_back(root);
        }
        else {
            parent = t2->get_parent();
        }
        while(parent!=-1) {
            p2.push_back(parent);
            for(TreeNode* t: arr) {
                if(t->get_data()==parent) {
                    t2 = t;
                    break;
                }
            }
            parent = t2->get_parent();
        }
        bool Found = false;
        for(int c : p1) {
            for(int c1 : p2) {
                if(c==c1) {
                    parent = c;
                    Found = true;
                    break;
                }
            }
            if(Found) {
                break;
            }
        }
        cout << parent << endl;
        for(TreeNode* t: arr) {
            TreeNode* temp = t;
            delete temp;
        }
        arr.clear();
        arr.shrink_to_fit();


// Q: Maybe the issue of the wrong answer is that it is not pushing itself on to the vector?
// A: That was the issue remember the edge case that when we have the parent and the child then the output is the parent.

    }
}
