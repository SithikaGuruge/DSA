#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left = NULL;
    Node *right = NULL;
};

struct Node* insert(struct Node* root,int data){
    if(root == NULL){
        struct Node *p = new Node(); 
        p = root;
        p->key = data;
    }
    else if(data < root->key){
        insert(root->left,data);
    }
    else
        insert(root->right,data);
    return root;
}
int main(){
    int no;
    int value;
    cout<<"Enter no of inputs";
    cin >> no;
    struct Node *temp;

    

    for(int i =0;i<no;i++){
        cout<<"Enter a value";
        cin>>value;
        insert(temp,value);
    }

}
