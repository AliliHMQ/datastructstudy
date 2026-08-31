#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;      // 队首索引
    int rear;       // 队尾索引
    int capacity;   // 总容量
    int size;       // 当前元素个数（用size区分空和满，避免混淆）

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;    // 初始无元素
        size = 0;
    }

    ~CircularQueue() { delete[] arr; }

    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == capacity; }

    // 入队（从队尾加）
    void enqueue(int val) {
        if (isFull()) {
            cout << "[警告] 队列已满，无法入队: " << val << endl;
            return;
        }
        // 指针循环后移
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        cout << "入队: " << val << " (当前大小: " << size << ")" << endl;
    }

    // 出队（从队首取）
    int dequeue() {
        if (isEmpty()) {
            cout << "[警告] 队列为空，无法出队" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << "出队: " << val << " (剩余: " << size << ")" << endl;
        return val;
    }

    // 查看队首
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // 打印队列所有元素（从队首到队尾）
    void print() {
        if (isEmpty()) {
            cout << "队列为空" << endl;
            return;
        }
        cout << "队列内容 [队首 -> 队尾]: ";
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity; // 关键：循环取索引
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // 容量为5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print(); // 10 20 30

    // 出队两个，触发循环
    q.dequeue(); // 出队10
    q.dequeue(); // 出队20
    q.print(); // 30

    // 继续入队，测试循环覆盖
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // 容量5，此时满了，会警告
    q.print(); // 30 40 50 60 70 (注意front已经移到30的位置了)

    cout << "队首元素: " << q.getFront() << endl; // 30
    return 0;
}