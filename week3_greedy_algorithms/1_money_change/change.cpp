#include <iostream>

int get_change(int m) {
	int n = 0;
	while (m > 0){
		if (m >= 10){
			n = n + 1;
			m = m - 10;
		}
		else if (m < 10 && m >= 5){
			n = n + 1;
			m = m - 5;
		}
		else if (m < 5 && m >= 1){
			n = n + 1;
			m = m - 1;
		}
	}
  //write your code here
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
