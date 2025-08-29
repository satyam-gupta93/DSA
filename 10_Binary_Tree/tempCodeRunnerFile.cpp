void levelOrderTraversal1(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i = 0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }

} 