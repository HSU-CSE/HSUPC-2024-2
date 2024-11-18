#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string word = "Hansung University";
  reverse(word.begin(), word.end());
  
  cout << word << endl;
  
  return 0;
}