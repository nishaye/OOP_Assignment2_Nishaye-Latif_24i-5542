#include <iostream>
#include <string>
using namespace std;

struct Node {
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;
};

class linkedlist {
private:
    Node* head;
    Node* tail;

public:
    linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void addbeg(int id, string title, string author) {
        Node* newNode = new Node{id, title, author, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addend(int id, string title, string author) {
        Node* newNode = new Node{id, title, author, nullptr, nullptr};
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addpos(int pos, int id, string title, string author) {
        if (pos <= 1) {
            addbeg(id, title, author);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            addend(id, title, author);
            return;
        }

        Node* newNode = new Node{id, title, author, temp->next, temp};
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void delid(int id) {
        Node* temp = head;
        while (temp && temp->BookID != id)
            temp = temp->next;

        if (!temp) {
            cout << "Book with ID " << id << " not found.\n";
            return;
        }

        if (temp == head)
            head = temp->next;
        if (temp == tail)
            tail = temp->prev;

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Book with ID " << id << " deleted.\n";
    }

    void forward() {
        Node* temp = head;
        cout << "\nBooks in order:\n";
        while (temp) {
            cout << temp->BookID << " - " << temp->Title << " by " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void backwards() {
        Node* temp = tail;
        cout << "\nBooks in reverse order:\n";
        while (temp) {
            cout << temp->BookID << " - " << temp->Title << " by " << temp->Author << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    linkedlist l;

    l.addbeg(101, "How To Lose Yourself In 10 Days", "Nishaye");
    l.addend(102, "The Great Gatorade", "Maryam");
    l.addend(103, "Battle Of The Heehee", "Alishba");
    l.addpos(2, 104, "Pride and Plastic Surgery", "Khadija");

    l.forward();
    l.backwards();

    l.delid(104);
    l.forward();

    return 0;
}
