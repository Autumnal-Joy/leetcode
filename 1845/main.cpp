#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class SeatManager {
public:
  priority_queue<int, vector<int>, greater<>> pq;
  SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
      pq.push(i);
    }
  }

  int reserve() {
    int seatNumber = pq.top();
    pq.pop();
    return seatNumber;
  }

  void unreserve(int seatNumber) { pq.push(seatNumber); }
};

int main() {
  // 初始化 SeatManager ，有 5 个座位。
  auto seatManager = SeatManager(5);
  // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
  cout << seatManager.reserve() << endl;
  // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
  seatManager.unreserve(2);
  // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
  cout << seatManager.reserve() << endl;
  // 唯一可以预约的是座位 5 ，所以返回 5 。
  cout << seatManager.reserve() << endl;
  // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
  seatManager.unreserve(5);
  return 0;
}
