#include <algorithm>
#include <functional>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class FizzBuzz {
private:
  int n;
  int currentStep;
  mutex mtx;
  condition_variable cv;

public:
  FizzBuzz(int n) : n(n), currentStep(0) {}

  // printFizz() outputs "fizz".
  void fizz(const function<void()> &printFizz) {
    for (int i = 1; i <= n; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [&] { return currentStep == 0; });

      if (i % 3 == 0 && i % 5 != 0) {
        printFizz();
      }

      currentStep = (currentStep + 1) % 4;
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(const function<void()> &printBuzz) {
    for (int i = 1; i <= n; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [&] { return currentStep == 1; });

      if (i % 3 != 0 && i % 5 == 0) {
        printBuzz();
      }

      currentStep = (currentStep + 1) % 4;
      cv.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(const function<void()> &printFizzBuzz) {
    for (int i = 1; i <= n; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [&] { return currentStep == 2; });

      if (i % 3 == 0 && i % 5 == 0) {
        printFizzBuzz();
      }

      currentStep = (currentStep + 1) % 4;
      cv.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(const function<void(int)>& printNumber) {
    for (int i = 1; i <= n; ++i) {
      unique_lock<mutex> lock(mtx);
      cv.wait(lock, [&] { return currentStep == 3; });

      if (i % 3 != 0 && i % 5 != 0) {
        printNumber(i);
      }

      currentStep = (currentStep + 1) % 4;
      cv.notify_all();
    }
  }
};

int main() {
  auto s = Solution();
  return 0;
}
