#include "queue_class.h"

template <typename Object>
class QueueStack : public Queue<Object>
{
private:
    Stack<Object> in;
    Stack<Object> out;

public:
    void enqueue(Object x) {in.push(x);}
    void dequeue() {
        if (in.empty()) {
            std::cout << "Queue empty!";
        }
        else {
            out.push(in.top());
            in.pop()
        }}
    T front() {
        return in.top();
    }
    
}