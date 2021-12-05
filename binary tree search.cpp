#include <iostream>

using namespace std;
struct BTS{
    int data;
    BTS* left;
    BTS* right;
};

class pointer_stack{
private:
    BTS* pointers[101];
    int top = -1;
public:
    void push(BTS* ptr);
    BTS* Top();
    void pop();
};

void pointer_stack::push(BTS* ptr){
    if (top == 100){
        return;
    }
    top++;
    pointers[top] = ptr;
}

BTS* pointer_stack::Top(){
    if (top == -1){
        return NULL;
    }
    return pointers[top];
}

void pointer_stack::pop(){
    if (top != -1){
        top--;
    }
}




class miniStack{
private:
    int arr[101];
    int top = -1;
    bool Reg = true;
public:
    bool IsEmpty();
    void push(int val);
    bool cant_compare();
    bool compare();
    void change_reg();
    bool check_reg();
    void pop();
    int Top();

};

int miniStack::Top(){
    return arr[top];
}

bool miniStack::IsEmpty(){
    if (top == -1){
        return true;
    }else{
        return false;
    }
}

void miniStack::pop(){
    if (top != -1){
        top--;
    }
}




void miniStack::change_reg(){
    Reg = false;
}

bool miniStack::check_reg(){
    return Reg;
}

void miniStack::push(int val){
    if (top == 100){
        return;
    }
    if (val < arr[top]){
        change_reg();
    }
    top++;
    arr[top] = val;
}

bool miniStack::compare(){
    if (top >= 1){if (arr[top] > arr[top-1]){
        return true;
    }else return false;}
    return false;
}



miniStack check;

void inorder2(BTS* node){
    if (node == NULL) return;
    inorder2(node->left);
    check.push(node->data);
    inorder2(node->right);
}
/*
void inorder2del(BTS* node, BTS* original_node, miniStack stark){
    if (node == NULL) return;
    inorder2(node->left , original_node , stark);
    if (node != original_node)stark.push(node->data);
    inorder2(node->right,original_node, stark);
    delete(node);
}
*/

bool inorder2cBT(BTS* node){
    inorder2(node);
    return check.check_reg();

}


BTS* GetNewNode(int val){
    BTS* temp = new(BTS);
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Insert(BTS** node,int val){
    if (*node == NULL){
        *node = GetNewNode(val);
        return;
    }
    BTS* temp = *node;
    while (temp != NULL){
        if (val <= (temp)-> data){
                if (temp-> left == NULL){
                    temp ->left = GetNewNode(val);
                    return;
                }else{
                    temp = temp->left;
                }

        }
        else{
            if (temp ->right == NULL){
                temp -> right = GetNewNode(val);
                return;
            }else{
                temp = temp->right;
            }
        }
    }
}

BTS* Recursion(BTS* node, int data){
    if (node == NULL){
        node = GetNewNode(data);
    }else if (data <= node->data){
        node->left = Recursion(node->left,data);
    }else{
        node -> right = Recursion(node->right,data);
    }
    return node;
}

void Insert2(BTS** node, int data){
    BTS* temp = *node;
    *node = Recursion(temp,data);
}

bool Search(BTS* node, int data){
    while (node != NULL){
    if (data == node->data){
        return true;
    }else if(data < node->data){
        node = node->left;
    }else{
        node = node->right;
    }
    }
    return false;
}

void find_min(BTS* node){
    if (node -> left == NULL){
        cout << node->data << endl;
        return;
    }
    find_min(node->left);
}

void find_max(BTS* node){
    if (node -> right == NULL){
        cout << node->data << endl;
        return;
    }
    find_max(node->right);
}

int find_height(BTS* node){
    if (node == NULL){
        return -1;
    }

    return max(find_height(node->left), find_height(node->right))+1;
}

void real_deal(BTS* node){
    if (node == NULL){
        return;
    }

    real_deal(node->left);
    real_deal(node->right);

    BTS* temp1 = node->left;
    node->left = node->right;
    node ->right =temp1;

}

void preorder(BTS* node){
    if (node == NULL) return;
    cout << node->data <<endl;
    preorder(node->left);
    preorder(node->right);
}

void inorder(BTS* node){
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data <<endl;
    inorder(node->right);
}

void postorder(BTS* node){
    if (node == NULL) return;
    inorder(node->left);
    inorder(node->right);
    cout << node->data <<endl;
}


bool IsLesser(BTS* node, int val){
    if (node == NULL){
            return true;
    }
    if ((node->data <= val)&&(IsLesser(node->left,val))&& (IsLesser(node->right,val))){
        return true;
    }else{
        return false;
    }
}

bool IsGreater(BTS* node, int val){
    if (node == NULL) return true;
    if ((node->data > val) && (IsGreater(node->left,val)) && (IsGreater(node->right,val))){
        return true;
    }else{
        return false;
    }

}

bool IsBinarySearchTree(BTS* node){
    if (node == NULL)return true;
    if ((IsLesser(node->left,node->data)) && (IsGreater(node->right,node->data)) && IsBinarySearchTree(node->left) &&
        IsBinarySearchTree(node->right))return true;
    else{return false;}
}

bool IsBstUtil(BTS* node, int min_value, int max_value){
    if (node == NULL)return true;
    if ((node->data)>min_value && (node->data <= max_value) &&
        IsBstUtil(node->left,min_value,node->data) && IsBstUtil(node->right,node->data,max_value)
        ) return true;
    else{return false;}
}


bool IsBst(BTS* node){
    if(IsBstUtil(node,INT_MIN,INT_MAX))return true;
    else{return false;}
}

BTS* Searchmin(BTS* node){
    BTS* temp = node;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

BTS* altssearch(BTS* node){
    pointer_stack checker;
    BTS* temp = node;
    while (temp->left != NULL){
        checker.push(temp);
        temp = temp->left;
    }
    return checker.Top();
}


void Searchanddelete(BTS* node){
    BTS* temp = node;
    while (temp->left != node){
        temp = temp->left;
    }
    temp->left  = NULL;
}

BTS* DeleteNode(BTS* node, int value){
    if (node == NULL){
        return node;
    }else if (value < node->data){
        node->left = DeleteNode(node->left, value);
    }else if (value > node->data){
        node-> right = DeleteNode(node->right, value);
    }else{
        if (node -> left == NULL && node->right == NULL){
            delete node;
            node = NULL;
        }else if(node -> left == NULL){
            BTS* temp = node;
            node = node->right;
            delete temp;
        }else if(node->right == NULL){
            BTS* temp = node;
            node = node->left;
            delete temp;
        }else{
            BTS* temp = Searchmin(node->right);
            node -> data = temp->data;
            node ->right = DeleteNode(node->right,temp->data);
        }
    }
    return node;
}

/**< what is going on here */

int main()
{
    BTS head;
    head.data = 10;
    head.left = NULL;
    head.right = NULL;
    BTS* root = &head;
    Insert(&root,15);
    Insert(&root,13);
    Insert(&root,20);
    Insert(&root,11);
    Insert(&root,2);
    Insert2(&root,12);
    Insert2(&root,19);
    Insert2(&root,21);
    Insert2(&root,18);
    //find_max(root);
    //find_min(root);
    //cout<< root->left->data << endl;
    //preorder(root);
    //cout << endl;
    //inorder(root);
    //real_deal(root);
    //cout<< root->left->data << endl;


    cout << root->right->data << endl;


    DeleteNode(root,180);




    cout  << root->right->data << endl;

    /*BTS test;
    test.data = 1;
    test.left = NULL;
    test.right = NULL;
    BTS* ptr_test = &test;
    Insert2(&ptr_test,5);
    Insert2(&ptr_test,6);

    cout  << ptr_test->right->data << endl;
    DeleteNode(ptr_test,5);
    cout  << ptr_test->right->data << endl;*/


}
