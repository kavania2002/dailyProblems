// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    
    // a vector queue which we will treat as
    // circular queue
    vector<int> queue;

    // variables to store head, tail indexes
    int head, tail, length, k;
    MyCircularQueue(int k) {
        this->queue.resize(k, -1);
        head = 0, tail = -1, length = 0;
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (length == k) return false;
        
        tail = (tail+1)%k, length++;
        queue[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (length == 0) return false;
        
        head = (head+1)%k;
        length--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return queue[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return queue[tail];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */