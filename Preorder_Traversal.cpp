// preorder: current->left->right
struct node{
    int val;
    node* left;
    node* right;
    node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
    void setchild(node* l, node* r){
        left=l;
        right=r;
    }
};

void preorder_iter(node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder_iter(root->left);
    preorder_iter(root->right);
}

void preorder_recur(node* root){
    if (root==NULL) return;
    stack<node*> istack;
    istack.push(root);
    
    while (!istack.empty()) {
        node* tmp=istack.top();
        istack.pop();
        if(tmp->right!=NULL) istack.push(tmp->right);
        if(tmp->left!=NULL) istack.push(tmp->left);
        cout<<tmp->val<<" ";
    }
}
