#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}



vector<int> dynamic_sequence(int n) {
  vector<int> num(n+1);
  vector<int> sequence;


  num[0] = pow(2,31) - 1;
  num[1] = 0;

  for (int i = 2; i < n+1; i++){
    int a = i - 1;
    int b = 0; int c = 0;

    if (i % 2 == 0) b = i/2;
    if (i % 3 == 0) c = i/3;

    num[i] = std::min({num[a],num[b],num[c]})+1;
  }

  //std::cout << num[n] << "\n**********\n";

  /*for (int i = 0; i < num.size(); i++){
    std::cout << num[i] << " ";
  }

  std::cout << "\n**********\n";*/

  while (n > 1){
    sequence.push_back(n);
    if (num[n-1] == num[n] - 1) n = n - 1;
    else if (n % 2 == 0 && num[n/2] == num[n]-1) n = n/2;
    else if ((n % 3 == 0 and num[n/3] == num[n]-1)) n = n/3;
  }
  sequence.push_back(1);

  reverse(sequence.begin(), sequence.end());
  return sequence;
}




int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dynamic_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
