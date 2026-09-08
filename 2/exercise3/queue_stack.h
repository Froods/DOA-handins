#include "queue_class.h"

template <typename T>
class QueueStack : public Queue<T>
{
private:
    Stack<T> s1;
    Stack<T> s2;

public:
    void enqueue(T x) {s1.push(x);}
    void dequeue() {
        if (s1.empty()) {
            std::cout << "Queue empty!"
        }
        else {
            s2.push(s1.top());
            s1.pop()
        }}
    T front() {
        return s1.top();
    }
    
}