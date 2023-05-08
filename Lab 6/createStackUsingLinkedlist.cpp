#include<iostream>
#include <chrono>
using namespace std;
class Stack {
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node* top;
    public:
        Stack() {
            top = nullptr;
        }

        void Push(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }

        void Pop() {
            if(top == nullptr) {
                cout << "Stack UnderFlow" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        void Display() {
            if(top == nullptr) {
                cout << "Stack UnderFlow" << endl;
            }
            Node* temp = top;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
        bool isEmpty() {
            return top == nullptr;
        }
        int stackTop() {
            if(isEmpty()) {
                cout << "Stack UnderFlow" << endl;
                return -1;
            }
            return top->data;
        }
};

int main(){
    auto start = chrono::high_resolution_clock::now();
    Stack stack;
    stack.Push(8);
    stack.Push(10);
    stack.Push(5);
    stack.Push(11);
    stack.Push(15);
    stack.Push(23);
    stack.Push(6);
    stack.Push(18);
    stack.Push(20);
    stack.Push(17);
    stack.Display();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Display();
    stack.Push(4);
    stack.Push(30);
    stack.Push(3);
    stack.Push(1);
    stack.Display();
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << "ms" << endl;


}
