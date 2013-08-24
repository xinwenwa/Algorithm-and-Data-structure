inorder: left->current->right
struct node{
    int val;
    node* left;
    node* right;
    bool isvisited;
    node(int data){
        val=data;
        left=NULL;
        right=NULL;
        isvisited=false;
    }
    void setchild(node* l, node* r){
        left=l;
        right=r;
    }
};
// excessive recursive function calls may cause memory to run out of stack space and extra overhead
//since the depth of balanced binary search tree is about logn, we dont need to worry about running out of
// stack space even when we have a million of elements. but what if the tree is not balanced, we will meet
// with problem because in the worst case the height of the tree may go up to n, stack space will eventually
// run out and the program will crash

void inorder_iter(node* root){
    if (root==NULL) return;
    inorder_iter(root->left);
    cout<<root->val<<" ";
    inorder_iter(root->right);
}

// this solution requires modification to the original BST data structure by adding a visited flag
void inorder_recur(node* root){
    if (root==NULL) return;
    stack<node*> istack;
    istack.push(root);
    while (!istack.empty()) {
        node* tmp=istack.top();
        istack.pop();
        
        if (tmp->isvisited) {
            cout<<tmp->val;
        }else
            tmp->isvisited=true;
        
        if (root->right!=NULL) istack.push(root->right);
        istack.push(tmp);
        if(root->left!=NULL) istack.push(root->left);
    }
    
}
