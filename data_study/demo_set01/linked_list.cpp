//单链表 demo
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // 头插法
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 按值删除第一个匹配的节点
    bool remove(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val) {
            cur = cur->next;
        }
        if (cur->next) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return true;
        }
        return false;
    }

    // 查找
    bool search(int val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == val) return true;
            cur = cur->next;
        }
        return false;
    }

    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    cout << "链表: ";
    list.print(); // 30 -> 20 -> 10 -> nullptr

    list.remove(20);
    cout << "删除20后: ";
    list.print();

    cout << "查找10: " << (list.search(10) ? "找到" : "未找到") << endl;
    return 0;
}