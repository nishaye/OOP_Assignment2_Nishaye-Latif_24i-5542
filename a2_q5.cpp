#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedliststack {
    Node* top;
public:
    linkedliststack() { top = nullptr; }

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    void display() {
        cout << "Linked List Stack (Top → Bottom): ";
        for (Node* temp = top; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;
    }
};

class arraystack {
    int* arr;
    int top;
    int capacity;
public:
    arraystack(int size = 5) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            int* newArr = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    void display() {
        cout << "Array Stack (Top → Bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~arraystack() { delete[] arr; }
};

void reversestack() {
    linkedliststack llStack;
    arraystack arrStack;

    cout << "\nPushing 1, 2, 3, 4 onto both stacks...\n";
    for (int i = 1; i <= 4; i++) {
        llStack.push(i);
        arrStack.push(i);
    }

    llStack.display();
    arrStack.display();

    cout << "\nPopping all elements (to reverse order):\n";

    cout << "Linked List Stack Output: ";
    while (!llStack.isEmpty()) {
        cout << llStack.peek() << " ";
        llStack.pop();
    }

    cout << "\nArray Stack Output: ";
    while (!arrStack.isEmpty()) {
        cout << arrStack.peek() << " ";
        arrStack.pop();
    }
    cout << endl;
}

int main() {
    reversestack();
    return 0;
}
/*

PART-B:
Both the array stack and linked list stack support push and pop in O(1) time but
are different in performance. The linked list stack takes more memory because of
pointers but does not require resizing, thus it is uniform. The array stack is
quicker due to contiguous memory access but sometimes requires resizing, which can
be temporarily O(n) time. In general, the array stack is faster in reality, while
the linked list stack is more convenient with dynamic data.

*/