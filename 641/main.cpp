#include <vector>

using namespace std;

class MyCircularDeque {
    vector<int> nums;
    // [front, rear)
    size_t front, rear, cnt;
public:
    explicit MyCircularDeque(int k) : nums(k), front(0), rear(0), cnt(0) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front + nums.size() - 1) % nums.size();
        nums[front] = value;
        ++cnt;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        nums[rear] = value;
        rear = (rear + 1) % nums.size();
        ++cnt;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % nums.size();
        --cnt;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear + nums.size() - 1) % nums.size();
        --cnt;
        return true;
    }

    int getFront() const {
        return isEmpty() ? -1 : nums[front];
    }

    int getRear() const {
        return isEmpty() ? -1 : nums[(rear + nums.size() - 1) % nums.size()];
    }

    bool isEmpty() const {
        return cnt == 0;
    }

    bool isFull() const {
        return cnt == nums.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    return 0;
}
