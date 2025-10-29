#include <iostream>
#include <string>
using namespace std;

class Feature {
protected:
    string name;
public:
    Feature(const string& n) : name(n) {}
    virtual ~Feature() = default;
    virtual void analyze() const = 0;
};

class LandFeature : public Feature {
public:
    LandFeature(const string& n) : Feature(n) {}
    void analyze() const override {
        cout << "Land: " << name << " detected\n";
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(const string& n) : Feature(n) {}
    void analyze() const override {
        cout << "Water: " << name << " detected\n";
    }
};

struct Node {
    int id;
    Feature* feat;
    Node* next;
    Node(int i, Feature* f) : id(i), feat(f), next(nullptr) {}
};

class linkedlist {
private:
    Node* head;
public:
    linkedlist() : head(nullptr) {}
    ~linkedlist() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp->feat;
            delete tmp;
        }
    }

    void inend(int id, Feature* f) {
        Node* n = new Node(id, f);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    bool delid(int id) {
        if (!head) return false;
        if (head->id == id) {
            Node* t = head;
            head = head->next;
            delete t->feat;
            delete t;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->id != id) cur = cur->next;
        if (!cur->next) return false;
        Node* t = cur->next;
        cur->next = t->next;
        delete t->feat;
        delete t;
        return true;
    }

    void display() const {
        for (Node* cur = head; cur; cur = cur->next) {
            cout << "ID " << cur->id << ": ";
            cur->feat->analyze();
        }
    }

    void reverse() {
        Node *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
};

int main() {
    linkedlist list;
    list.inend(1, new LandFeature("Forest"));
    list.inend(2, new WaterFeature("Ocean"));
    list.inend(3, new LandFeature("Mountain"));

    cout << "Original list:\n";
    list.display();

    cout << "\nAfter deleting ID 2:\n";
    list.delid(2);
    list.display();

    cout << "\nAfter reversing:\n";
    list.reverse();
    list.display();

    return 0;
}