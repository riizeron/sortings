#include <iostream>

void mergeArr(int *arr, int block_i, int size, int n) {
    int left_i = 0;
    int right_i = 0;
    int left = block_i;
    int mid = left + size;
    int right = mid + size > n ? n : mid + size;

    int *block = new int[right - left];

    while (left + left_i < mid && mid + right_i < right) {
        if (arr[left + left_i] < arr[mid + right_i]) {
            block[left_i + right_i] = arr[left + left_i];
            left_i++;
        } else {
            block[left_i + right_i] = arr[mid + right_i];
            right_i++;
        }
    }

    while (left + left_i < mid) {
        block[left_i + right_i] = arr[left + left_i];
        left_i++;
    }
    while (mid + right_i < right) {
        block[left_i + right_i] = arr[mid + right_i];
        right_i++;
    }

    for (int i = 0; i < left_i + right_i; ++i) {
        arr[left + i] = block[i];
    }

    delete[] block;
}

void mergeSort(int *arr, int n) {
    for (int size_i = 1; size_i < n; size_i *= 2) {
        for (int block_i = 0; block_i < n - size_i; block_i += 2 * size_i) {
            mergeArr(arr, block_i, size_i, n);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
