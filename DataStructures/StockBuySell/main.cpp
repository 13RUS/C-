#include <iostream>

std::tuple <int, int> find_buy_sell_stock_prices(int *array, int size){
    if (array == NULL || size < 2 ) {
        std::tuple<int, int> t(std::make_pair(NULL,NULL));

        return t;
    }

    int current_buy = array[0];
    int global_sell = array[1];
    int global_profit = global_sell - current_buy;

    int current_profit = -2147483648;

    for (int i = 1; i < size; i++) {
        current_profit = array[i] - current_buy;

        std::cout << current_profit;

        if (current_profit > global_profit) {
            global_profit = current_profit;
            global_sell = array[i];
        }

        if (current_buy > array[i]) {
            current_buy = array[i];
        }
    }
        std::tuple<int, int> result (std::make_pair(global_sell-global_profit,global_sell));

        return result;
    }

int main() {
    int array[] = {1, 2, 3, 4, 3, 2, 1, 2, 5};
    std::tuple<int, int> result;
    result = find_buy_sell_stock_prices(array, 9);
    std::cout << "Buy Price: "<< get<0>(result) << ", Sell Price: " << get<1>(result) << std::endl;

    int array2[] = {8, 6, 5, 4, 3, 2, 1};
    result = find_buy_sell_stock_prices(array2, 7);
    std::cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << std::endl;
}