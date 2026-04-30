#include <iostream>
#include <vector>
#include <algorithm>

// 冒泡排序
template <typename T>
void bubbleSort(T arr[], int n) {
		for (int i = 0; i < n - 1; ++i) {
				bool swapped = false;
				for (int j = 0; j < n - i - 1; ++j) {
						if (arr[j] > arr[j + 1]) {
								std::swap(arr[j], arr[j + 1]);
								swapped = true;
						}
				}
				if (!swapped) break; // 如果没有发生交换，说明已经有序
		}
}

// 选择排序
template <typename T>
void selectionSort(T arr[], int n) {
		for (int i = 0; i < n - 1; ++i) {
				int minIndex = i;
				for (int j = i + 1; j < n; ++j) {
						if (arr[j] < arr[minIndex]) {
								minIndex = j;
						}
				}
				if (minIndex != i) {
						std::swap(arr[i], arr[minIndex]);
				}
		}
}

// 插入排序
template <typename T>
void insertionSort(T arr[], int n) {
		for (int i = 1; i < n; ++i) {
				T key = arr[i];
				int j = i - 1;
				while (j >= 0 && arr[j] > key) {
						arr[j + 1] = arr[j];
						--j;
				}
				arr[j + 1] = key;
		}
}

// 快速排序的划分函数
template <typename T>
int partition(T arr[], int low, int high) {
		T pivot = arr[high];
		int i = low - 1;
		for (int j = low; j < high; ++j) {
				if (arr[j] < pivot) {
						++i;
						std::swap(arr[i], arr[j]);
				}
		}
		std::swap(arr[i + 1], arr[high]);
		return i + 1;
}

// 快速排序
template <typename T>
void quickSort(T arr[], int low, int high) {
		if (low < high) {
				int pi = partition(arr, low, high);
				quickSort(arr, low, pi - 1);
				quickSort(arr, pi + 1, high);
		}
}

// 归并排序的合并函数
template <typename T>
void merge(T arr[], int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		T* L = new T[n1];
		T* R = new T[n2];

		for (int i = 0; i < n1; ++i)
				L[i] = arr[left + i];
		for (int j = 0; j < n2; ++j)
				R[j] = arr[mid + 1 + j];

		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2) {
				if (L[i] <= R[j]) {
						arr[k] = L[i];
						++i;
				}
				else {
						arr[k] = R[j];
						++j;
				}
				++k;
		}

		while (i < n1) {
				arr[k] = L[i];
				++i;
				++k;
		}

		while (j < n2) {
				arr[k] = R[j];
				++j;
				++k;
		}

		delete[] L;
		delete[] R;
}

// 归并排序
template <typename T>
void mergeSort(T arr[], int left, int right) {
		if (left < right) {
				int mid = left + (right - left) / 2;
				mergeSort(arr, left, mid);
				mergeSort(arr, mid + 1, right);
				merge(arr, left, mid, right);
		}
}

// 堆排序的堆化函数
template <typename T>
void heapify(T arr[], int n, int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && arr[left] > arr[largest])
				largest = left;

		if (right < n && arr[right] > arr[largest])
				largest = right;

		if (largest != i) {
				std::swap(arr[i], arr[largest]);
				heapify(arr, n, largest);
		}
}

// 堆排序
template <typename T>
void heapSort(T arr[], int n) {
		// 构建最大堆
		for (int i = n / 2 - 1; i >= 0; --i)
				heapify(arr, n, i);

		// 一个个提取元素
		for (int i = n - 1; i > 0; --i) {
				std::swap(arr[0], arr[i]);
				heapify(arr, i, 0);
		}
}

// 打印数组
template <typename T>
void printArray(T arr[], int n) {
		for (int i = 0; i < n; ++i)
				std::cout << arr[i] << " ";
		std::cout << "\n";
}

int main() {
		int arr[] = { 64, 25, 12, 22, 11 };
		int n = sizeof(arr) / sizeof(arr[0]);

		std::cout << "Original array: ";
		printArray(arr, n);

		// 测试各种排序算法
		// 注意：每次测试前需要复制原始数组，因为排序会修改数组

		int arr1[n];
		std::copy(arr, arr + n, arr1);
		bubbleSort(arr1, n);
		std::cout << "Bubble sorted: ";
		printArray(arr1, n);

		int arr2[n];
		std::copy(arr, arr + n, arr2);
		selectionSort(arr2, n);
		std::cout << "Selection sorted: ";
		printArray(arr2, n);

		int arr3[n];
		std::copy(arr, arr + n, arr3);
		insertionSort(arr3, n);
		std::cout << "Insertion sorted: ";
		printArray(arr3, n);

		int arr4[n];
		std::copy(arr, arr + n, arr4);
		quickSort(arr4, 0, n - 1);
		std::cout << "Quick sorted: ";
		printArray(arr4, n);

		int arr5[n];
		std::copy(arr, arr + n, arr5);
		mergeSort(arr5, 0, n - 1);
		std::cout << "Merge sorted: ";
		printArray(arr5, n);

		int arr6[n];
		std::copy(arr, arr + n, arr6);
		heapSort(arr6, n);
		std::cout << "Heap sorted: ";
		printArray(arr6, n);

		return 0;
}