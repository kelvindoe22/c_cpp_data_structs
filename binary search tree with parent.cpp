#include <iostream>

using namespace std;



struct BST {
    int data;
    BST* parent;
    BST* left;
    BST* right;
};

BST* Findmin(BST* node);

BST* Find(BST* node, int data){
    if (node == NULL){
        return node;
    }
    if(data == node->data){
        return node;
    }else if(data < node->data){
        return Find(node->left,data);
    }else if(data > node->data){
        return Find(node->right,data);
    }
}

BST* GetSuccessor(BST* node, int data){
    BST* current = Find(node,data);
    if (current == NULL){
        return NULL;
    }else{
        if (current->right == NULL){
            if (current->parent->right != current){
                return current->parent;
            }else{
                if(current->data < node->data){
                    return current->parent->parent;
                }else{
                    return NULL;
                }
            }
        }else {
            return Findmin(current->right);
        }
    }

}

BST* Findmin(BST* node){
    BST* temp = node;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}


void inorder(BST* node){
    if (node == NULL)return;
    inorder(node->left);
    cout<< node->data <<endl;
    inorder(node->right);

}

BST* GetNewNode(BST* parent,int val){
    BST* temp = new(BST);
    temp->data = val;
    temp->parent = parent;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BST* addtonode(BST* node,BST* parent,int val){
    if (node == NULL){
        node = GetNewNode(parent,val);
    }
    else if (val <= node->data){
        node->left = addtonode(node->left,node,val);
    }
    else{
        node->right = addtonode(node->right,node,val);
    }
    return node;
}

void printparentval(BST* node){
    if (node == NULL){
        return;
    }
    if (node->parent == NULL){
        cout << "NULL" <<endl;
    }else{
        cout << node->parent->data <<endl;
    }
    printparentval(node->left);
    printparentval(node->right);
}

int main()
{
    BST* head = NULL;
    head = addtonode(head,head,8);
    head = addtonode(head,head,16);
    head = addtonode(head,head,4);
    head = addtonode(head,head,2);
    head = addtonode(head,head,12);
    //head = addtonode(head,head,5);
    if (GetSuccessor(head,4)== NULL){
        cout << "NULL";
    }else{
        cout << GetSuccessor(head,4)->data;
    }

}
