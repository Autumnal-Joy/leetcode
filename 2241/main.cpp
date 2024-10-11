#include <algorithm>
#include <vector>

using namespace std;

class ATM {
    long long m20 = 0;
    long long m50 = 0;
    long long m100 = 0;
    long long m200 = 0;
    long long m500 = 0;

public:
    ATM() = default;

    void deposit(vector<int> banknotesCount) {
        m20 += banknotesCount[0];
        m50 += banknotesCount[1];
        m100 += banknotesCount[2];
        m200 += banknotesCount[3];
        m500 += banknotesCount[4];
    }

    vector<int> withdraw(int amount) {
        int cnt500 = static_cast<int>(
                std::min({static_cast<long long>(amount / 500), m500}));
        amount -= cnt500 * 500;
        int cnt200 = static_cast<int>(
                std::min({static_cast<long long>(amount / 200), m200}));
        amount -= cnt200 * 200;
        int cnt100 = static_cast<int>(
                std::min({static_cast<long long>(amount / 100), m100}));
        amount -= cnt100 * 100;
        int cnt50 =
                static_cast<int>(std::min({static_cast<long long>(amount / 50), m50}));
        amount -= cnt50 * 50;
        int cnt20 =
                static_cast<int>(std::min({static_cast<long long>(amount / 20), m20}));
        amount -= cnt20 * 20;

        if (amount == 0) {
            m500 -= cnt500;
            m200 -= cnt200;
            m100 -= cnt100;
            m50 -= cnt50;
            m20 -= cnt20;
            return {cnt20, cnt50, cnt100, cnt200, cnt500};
        } else {
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main() { return 0; }
