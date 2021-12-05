#include <iostream>

using namespace std;

class Queue{
private:
    int arr[10];
    int top = -1;
    int rear = -1;
public:
    void Enqueue(int val);
    void Dequeue();
    int Top();
    bool IsEmpty();
    bool IsFull();
    void print();
};



void Queue::Dequeue(){
    if (!IsEmpty()){
        if (top == rear){
            cout << "Removed" << Top() << endl;
            top = -1;
            rear = -1;
        }else{
            if (top == 9){
                cout << "Removed" << Top() << endl;
                top = 0;
            }else{
            cout << "Removed" << Top() << endl;
            top++;
            }
        }
    }
}

bool Queue::IsFull(){
    if ((rear+1)%10 == top){
        return true;
    }
    return false;

}

bool Queue::IsEmpty(){
    if (top == -1 && rear == -1){
        return true;
    }
    return false;
}

void Queue::Enqueue(int val){
    if (top == -1 && rear == -1){
        top = 0;
        rear ++;
        arr[rear] = val;
        return;
    }
    if(!IsFull()){
        rear = (rear+1)%10;
        arr[rear] = val;
    }else{
        cout << "Queue is full \n";
    }
}

int Queue::Top(){
    if (!IsEmpty()){
        return arr[top];
    }
}





int main()
{
    Queue k;
    k.Enqueue(1);
    k.Enqueue(2);
    k.Dequeue();
    k.Enqueue(3);
    k.Enqueue(4);
    k.Enqueue(5);
    k.Enqueue(6);
    k.Enqueue(7);
    k.Enqueue(8);
    k.Enqueue(9);
    k.Enqueue(10);
    k.Enqueue(11);
    k.Enqueue(12);
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Dequeue();
    k.Enqueue(13);
    k.Dequeue();
    cout << k.Top() <<'\n';
    k.Dequeue();
    k.Enqueue(5);
    cout << k.Top();
}
