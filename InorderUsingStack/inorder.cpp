#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){

    data=val;
    left=NULL;
    right=NULL;

    }
};


void inorderT(TreeNode* root){

    TreeNode* node = root;
    stack<TreeNode*> st;


    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true)
                break;
            node=st.top();
            cout<<node->data<<" ";
            st.pop();
             node=node->right;

        }
    }

}


int main() {
    TreeNode* Root = new TreeNode(1);
    Root->left = new TreeNode(4);
    Root->right = new TreeNode(5);
    Root->left->left = new TreeNode(3);
    Root->left->right = new TreeNode(5);
    Root->right->left = new TreeNode(6);
    Root->right->right = new TreeNode(7);


    cout << "inorder traversal: ";
    inorderT(Root);

    return 0;
}
