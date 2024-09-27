#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<string> &words) {
    vector <int> mask(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      for (char c : words[i]) {
        mask[i] |= 1 << (c - 'a');
      }
    }

    int max = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if ((mask[i] & mask[j]) == 0) {
          int product = words[i].size() * words[j].size();
          max = product > max ? product : max;
        }
      }
    }
    return max;
  }
};

int main() {
  Solution s;
  vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  cout << s.maxProduct(words) << endl;
  return 0;
}
