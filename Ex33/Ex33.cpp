#include <iostream>
#include <chrono>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

vector<int> generateVector(int size, int min, int max) {
	vector<int> arr;
	for (int i = 0; i < size; i++) {
		arr.push_back(rand() % (max + 1 - min) + min);
	}
	return arr;
}

vector<int> getBubbleSort(vector<int> src) {
	vector<int> arr = src;
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = arr.size() - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
			}
		}
	}
	return arr;
}

int getPosMinOfArray(vector<int> arr, int start, int end) {
	int min = start;
	for (int i = start; i < end; i++) {
		if (arr[min] > arr[i]) {
			min = i;
		}
	}
	return min;
}

vector<int> getSelectionSort(vector<int> src) {
	vector<int> arr = src;
	for (int i = 0; i < arr.size(); i++) {
		int min = getPosMinOfArray(arr, i, arr.size());
		swap(arr[min], arr[i]);
	}
	return arr;
}

vector<int> getInsertionSort(vector<int> src) {
	vector<int> arr = src;
	int i, key, j;
	for (i = 1; i < arr.size(); i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return arr;
}

void merge(vector<int>& src, int const left, int const mid, int const right)
{
	int const subArr1 = mid - left + 1;
	int const subArr2 = right - mid;

	vector<int> leftArr(subArr1, 0),
		rightArr(subArr2, 0);

	for (auto i = 0; i < subArr1; i++) {
		leftArr[i] = src[left + i];
	}
	for (auto j = 0; j < subArr2; j++) {
		rightArr[j] = src[mid + 1 + j];
	}
	auto indexSub1 = 0, indexSub2 = 0;
	int indexMerged = left;

	while (indexSub1 < subArr1 && indexSub2 < subArr2) {
		if (leftArr[indexSub1] <= rightArr[indexSub2]) {
			src[indexMerged] = leftArr[indexSub1];
			indexSub1++;
		}
		else {
			src[indexMerged] = rightArr[indexSub2];
			indexSub2++;
		}
		indexMerged++;
	}

	while (indexSub1 < subArr1) {
		src[indexMerged] = leftArr[indexSub1];
		indexSub1++;
		indexMerged++;
	}

	while (indexSub2 < subArr2) {
		src[indexMerged] = rightArr[indexSub2];
		indexSub2++;
		indexMerged++;
	}
	leftArr.clear();
	rightArr.clear();
}

void mergeSort(vector<int>& src, int const begin, int const end)
{
	if (begin >= end) {
		return;
	}

	int mid = begin + (end - begin) / 2;
	mergeSort(src, begin, mid);
	mergeSort(src, mid + 1, end);
	merge(src, begin, mid, end);
}

vector<int> getMergeSort(vector<int>& src) {
	vector<int> arr = src;
	mergeSort(arr, 0, arr.size() - 1);
	return arr;
}

int partition(vector<int>& arr, int start, int end)
{
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] < pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {

			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(vector<int>& arr, int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the src
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

vector<int> getQuickSort(vector<int> src) {
	vector<int> arr = src;
	quickSort(arr, 0, arr.size() - 1);
	return arr;
}

void heapify(vector<int>& arr, int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

vector<int> getHeapSort(vector<int> src)
{
	vector<int> arr = src;
	// Build heap (rearrange src)
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, arr.size(), i);

	// One by one extract an element
	// from heap
	for (int i = arr.size() - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
	return arr;
}

int getMaxOfArray(vector<int> arr)
{
	int mx = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(vector<int>& arr, int exp)
{
	// Output src
	vector<int> output(arr.size(), 0), count(10, 0);
	int i;

	// Store count of occurrences
	// in count[]
	for (i = 0; i < arr.size(); i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output src
	for (i = arr.size() - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output src to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

vector<int> getRadixSort(vector<int> src)
{
	vector<int> arr = src;
	// Find the maximum number to
	// know number of digits
	int m = getMaxOfArray(arr);

	// Do counting sort for every digit.
	// Note that instead of passing digit
	// number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, exp);
	return arr;
}

void printArr(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

template <typename T>
T getMaxVal(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
T getMinVal(T a, T b) {
	return a < b ? a : b;
}

void outputResult(vector<int> src, int turn) {
	long long maxTime = 0, minTime = LLONG_MAX;
	vector<int> arr;
	string typeSortMax, typeSortMin;
	cout << endl << "---------------------------------------------------------------------------------" << endl;
	cout << "Turn " << turn + 1 << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Source Vector: ";
	//printArr(src);
	//cout << "------------------------------------------------" << endl;
	//Buble Sort
	auto start = chrono::high_resolution_clock::now();
	arr = getBubbleSort(src);
	auto end = chrono::high_resolution_clock::now();
	//printArr(arr);
	chrono::nanoseconds duration = end - start;
	cout << "Bubble Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Bubble Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Bubble Sort";
	}

	//Selection Sort
	start = chrono::high_resolution_clock::now();
	arr = getSelectionSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Selection Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Selection Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Selection Sort";
	}

	//Insertion Sort
	start = chrono::high_resolution_clock::now();
	arr = getInsertionSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Insertion Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Insertion Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Insertion Sort";
	}

	//Merge Sort
	start = chrono::high_resolution_clock::now();
	arr = getMergeSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Merge Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Merge Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Merge Sort";
	}

	//Quick Sort
	start = chrono::high_resolution_clock::now();
	arr = getQuickSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Quick Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Quick Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Quick Sort";
	}

	//Heap Sort
	start = chrono::high_resolution_clock::now();
	arr = getHeapSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Heap Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Heap Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Heap Sort";
	}

	//Radix Sort
	start = chrono::high_resolution_clock::now();
	arr = getRadixSort(src);
	end = chrono::high_resolution_clock::now();
	//printArr(arr);
	duration = end - start;
	cout << "Radix Sort: " << duration.count() << "(nanoseconds)" << endl;
	if (duration.count() == getMaxVal(maxTime, duration.count())) {
		maxTime = getMaxVal(maxTime, duration.count());
		typeSortMax = "Radix Sort";
	}
	if (duration.count() == getMinVal(minTime, duration.count())) {
		minTime = getMinVal(minTime, duration.count());
		typeSortMin = "Radix Sort";
	}

	arr.clear();

	cout << endl;
	cout << "Max Time: " << maxTime << " (" << typeSortMax << ")" << endl;
	cout << "Min Time: " << minTime << " (" << typeSortMin << ")" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
}

int main()
{
	int arrNum = 0, N = 0;
	cout << "Enter Number of src to generate: ";
	cin >> arrNum;
	//check invalid input
	while (cin.fail() || arrNum < 0) {
		cin.clear();
		cin.ignore();
		cout << "#Warn: Invalid input !! Please Re-enter: ";
		cin >> arrNum;
	}
	cout << "Enter Number of elements of each srcs to generate: ";
	cin >> N;
	//check invalid input
	while (cin.fail() || N < 0) {
		cin.clear();
		cin.ignore();
		cout << "#Warn: Invalid input !! Please Re-enter: ";
		cin >> N;
	}
	srand((int)time(0));
	for (int i = 0; i < arrNum; i++) {
		vector<int> arr = generateVector(N, 0, 100);
		outputResult(arr, i);
	}
}