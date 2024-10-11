#include <vector>

using namespace std;

class MyCircularQueue {
    vector<int> nums;
    // [front, rear)
    size_t front, rear, cnt;
public:
    explicit MyCircularQueue(int k) : nums(k), front(0), rear(0), cnt(0) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        nums[rear] = value;
        rear = (rear + 1) % nums.size();
        ++cnt;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % nums.size();
        --cnt;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : nums[front];
    }

    int Rear() {
        return isEmpty() ? -1 : nums[(rear + nums.size() - 1) % nums.size()];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == nums.size();
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

int main() {
    return 0;
}
