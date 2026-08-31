#include <iostream>
#include <cstring>
using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int capacity;
public:
    Stack(int size = 100) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }
    ~Stack() { delete[] arr; }

    void push(char c) { if (top < capacity - 1) arr[++top] = c; }
    char pop() { return (top >= 0) ? arr[top--] : '\0'; }
    bool isEmpty() { return top == -1; }
    char peek() { return (top >= 0) ? arr[top] : '\0'; }
};

// 检查括号是否匹配
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValidParentheses(const char* str) {
    Stack s;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.isEmpty() || !isMatching(s.peek(), c)) {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}

int main() {
    const char* test1 = "({[]})";
    const char* test2 = "({[}])";
    cout << test1 << " 是否合法: " << (isValidParentheses(test1) ? "是" : "否") << endl;
    cout << test2 << " 是否合法: " << (isValidParentheses(test2) ? "是" : "否") << endl;
    return 0;
}