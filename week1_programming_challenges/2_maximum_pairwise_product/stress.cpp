#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    /*for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }*/

    int max_index1 = -1;
    int max_index2 = -1;

    for (int i = 0; i < n; i++){
    	if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
    		max_index1 = i;
    }

    for (int j = 0; j < n; j++){
    	if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
    		max_index2 = j;
    }
    //cout << max_index1 << max_index2 << endl;

    max_product = (long long)numbers[max_index1] * (long long)numbers[max_index2];
    
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
