#include <iostream>
#include <memory>

using namespace std;

int getMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        return min;
    }
}

int getMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        return max;
    }
}

void getMinAndAax(int numbers[], int size, int *min, int *max) {
    for (int i = 1; i < size; i++) {
        if (numbers[i] > *max)
            *max = numbers[i];
        if (numbers[i] < *min)
            *min = numbers[i];
    }
}

int main() {
    int numbers[5] = {5, 4, -2, 29, 6};
/*    cout << "Min is " << getMin(numbers, 5) << endl;
    cout << "Max is " << getMax(numbers, 5);*/

    int min = numbers[0];
    int max = numbers[0];
    getMinAndAax(numbers, 5, &min, &max);
    cout << "min is " << min << endl;
    cout << "max is " << max << endl;


    return 0;
}