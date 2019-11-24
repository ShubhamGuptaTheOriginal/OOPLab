#include <iostream>
using namespace std;

template <class T>
class Stack{
    int Size;
    int Top;
    T* stack;
public:
    Stack(int size){
        this->Top=0;
        this->Size = size;
        this->stack = new T[size];
    }
    void push(T data){
        if(Top<Size)
            stack[Top++] = data;
        else
            cout << "\nStack overflow.\n";
    }
    T top(){
        if(Top>0)
            return stack[Top-1];
        else{
            cout << "\nStack is empty\n";
            return (T)-1;
        }
    }
    void pop(){
        if(Top>0)
            Top--;
        else
            cout << "\nStack underflow.\n";
    }
    int size(){
        return this->Top;
    }
    void print(){
        if(Size==0){
            cout << "\nStack is empty.\n";
            return;
        }
        cout << "\nData in stack - ";
        int i = Top-1;
        while(i>=0)
            cout << stack[i--] << "  ";
    }
};


int main(){
    Stack<int> S(10);
    
    int C=1;
    while(C){
        int data;
        cout << "\n0. Exit\n1. Top of stack.\n2. Push in stack.\n3. Pop from stack.\n4. Total data in stack.\n5.Print data in stack.";
        cout << endl << "Enter your choice - ";
        cin >> C;
        switch(C){
            case 0: break;
            case 1:
                data = S.top();
                if(data != -1)
                    cout << "\nTop of stack - " << S.top() << endl;
                break;
            case 2:
                cout << "\nEnter data to push in stack - " ;
                cin >> data;
                S.push(data);
                break;
            case 3:
                S.pop();
                break;
            case 4:
                cout << "\nTotal data in stack - " << S.size() << endl;
                break;
            case 5:
                S.print();
                break;
            default:
                cout << "\nInvalid choice. Enter valid choice\n";
                break;
        }
    }
    return 0;
}