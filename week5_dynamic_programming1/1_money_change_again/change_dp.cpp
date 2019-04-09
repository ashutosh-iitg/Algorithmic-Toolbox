#include <iostream>

int get_change(int m) {
	int coins[3] = {1,3,4};
	//int len_coins = 3;

	int min_coins[m+1];
	min_coins[0] = 0;

	for (int i = 1; i <= m; i++){
		min_coins[i] = 1000000000;
		for(int j = 0; j < 3; j++){
			if (i >= coins[j]) {
				int num_coins = min_coins[i - coins[j]] + 1;
				if (num_coins < min_coins[i]) min_coins[i] = num_coins;
			}
		}
	}
  return min_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
