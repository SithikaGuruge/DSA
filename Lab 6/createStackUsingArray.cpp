#include<iostream>
#include <chrono>
using namespace std;
class Stack{
    private:
        const int static maximum_size = 50;
        int current_size;
        int arr[maximum_size];
        
    public:
        Stack(){
            current_size = 0;
        }
        void Push(int element){
            if (current_size==maximum_size){
                cout<<"Stack OverFlow"<<endl;
            }
            else{
                arr[current_size] = element;
                current_size++;
            }
            
        }
        void Pop(){
            if(isEmpty()){
                cout<<"stack Underflow"<<endl;
            }
            current_size--;
        }
        void Display(){
            if(current_size==0){
                cout<<"Stack UnderFlow"<<endl;
            }
            for(int i=0; i<current_size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        bool isEmpty(){
            if(current_size == 0){
                return true;
            }
            return false;
        }
        bool isFull(){
            if(current_size == maximum_size){
                return true;
            }
            return false;
        }
        int stackTop(){
            if(isEmpty()){
                cout<<"Stack UnderFlow";
            }
            return arr[current_size];
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
