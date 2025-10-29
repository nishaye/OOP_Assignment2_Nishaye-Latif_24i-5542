#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int tickets;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() { front = rear = nullptr; }

    void enqueue(int id, string name, int tickets) {
        Node* newNode = new Node{id, name, tickets, nullptr};
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << name << " joined the queue.\n";
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << front->name << " has been served.\n";
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nCurrent Queue:\n";
        for (Node* temp = front; temp; temp = temp->next)
            cout << temp->id << " - " << temp->name << " (" << temp->tickets << " tickets)\n";
    }

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1, "Maryam", 2);
    q.enqueue(2, "Noor", 4);
    q.enqueue(3, "Umer", 1);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
