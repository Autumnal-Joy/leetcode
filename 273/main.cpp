#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> lessThan20 = {"Zero",    "One",       "Two",      "Three",
                               "Four",    "Five",      "Six",      "Seven",
                               "Eight",   "Nine",      "Ten",      "Eleven",
                               "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                               "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                         "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

 public:
  string numberToWords(int num) {
    if (num >= 1000000000) {
      auto quotient = num / 1000000000;
      auto remainder = num % 1000000000;
      if (remainder == 0) {
        return numberToWords(quotient) + " Billion";
      } else {
        return numberToWords(quotient) + " Billion " + numberToWords(remainder);
      }
    } else if (num >= 1000000) {
      auto quotient = num / 1000000;
      auto remainder = num % 1000000;
      if (remainder == 0) {
        return numberToWords(quotient) + " Million";
      } else {
        return numberToWords(quotient) + " Million " + numberToWords(remainder);
      }
    } else if (num >= 1000) {
      auto quotient = num / 1000;
      auto remainder = num % 1000;
      if (remainder == 0) {
        return numberToWords(quotient) + " Thousand";
      } else {
        return numberToWords(quotient) + " Thousand " +
               numberToWords(remainder);
      }
    } else {
      if (num < 20) {
        return lessThan20[num];
      } else if (num < 100) {
        auto quotient = num / 10;
        auto remainder = num % 10;
        if (remainder == 0) {
          return tens[quotient];
        } else {
          return tens[quotient] + " " + lessThan20[remainder];
        }
      } else {
        auto quotient = num / 100;
        auto remainder = num % 100;
        if (remainder == 0) {
          return lessThan20[quotient] + " Hundred";
        } else {
          return lessThan20[quotient] + " Hundred " + numberToWords(remainder);
        }
      }
    }
  }
};

int main() {
  Solution solution;
  cout << solution.numberToWords(990) << endl;
  return 0;
}
