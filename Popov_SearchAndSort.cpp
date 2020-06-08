#include <iostream>
#include <stack>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

//класс стека
class myStack {
public:
    int myStack[100]{}, n = 100, top = -1;
    void push(int val) {
        if (top >= n - 1)
            cout << "\nStack Overflow\n";
        else {
            top++;
            myStack[top] = val;
        }
    }
    void pop() {
        if (top <= -1)
            cout << "\nStack Underflow\n";
        else
            top--;
    }
    bool empty() {
        return top <= -1;
    }
};

//метод вывода массива в консоль
void Print(int* arr, int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}

//метод замены двух элементов в массиве местами
void Swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//метод заполнения массива значениями
void FillArray(int* arr, int N, int min, int max) {
    default_random_engine generator(time(nullptr));
    uniform_int_distribution<int> distribution(min + 1, max - 1);
    for (int i = 0; i < N; ++i)
        arr[i] = distribution(generator);
}

//метод обыкновенного поэлементного поиска
void Search(const int* Array, int N, int val) {
    bool numberIsFound = false;
    int index = -1;
    for (int i = 0; i < N; i++) //поиск числа "42" среди элементов массива
        if (Array[i] == val) {
            numberIsFound = true;
            index = i;
        }
    if (numberIsFound)
        cout << "\nThe element "<< val << " has been found, its index is " << index << ".\n";
    else
        cout << "\nThere is no such element in the array.\n";
}

/*вспомогательный метод, который берёт последний элемент,
ставит его в правильное место, и перемещает все элементы
 меньше него левее, а больше – правее*/
int partition(int arr[], int startIdx, int endIdx) {
    int x = arr[endIdx];
    int i = (startIdx - 1);
    for (int j = startIdx; j <= endIdx - 1; j++) {
        if (arr[j] <= x) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[endIdx]);
    return (i + 1);
}

//быстрая сортировка без рекурсии, используя стеки
void QuickSort(int* arr, int startIdx, int endIdx) {
    myStack start, end;
    start.push(startIdx);
    end.push(endIdx);
    int l, h, p;
    while (!start.empty()) {
        l = start.myStack[start.top];
        h = end.myStack[end.top];
        if (l < h) {
            p = partition(arr, l, h);
            start.pop();
            end.pop();
            start.push(p + 1);
            end.push(h);
            start.push(l);
            end.push(p - 1);
        }
        else {
            start.pop();
            end.pop();
        }
    }
}

//быстрая сортировка, использующая рекурсию
void QuickSortRecursively(int* arr, int startIdx, int endIdx) {
    int i = startIdx, j = endIdx, temp;
    int mid = arr[(i + j) / 2];
    while (i <= j) {
        while (arr[i] < mid)
            i++;
        while (arr[j] > mid)
            j--;
        if (i <= j) {
            Swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (j > startIdx)
        QuickSortRecursively(arr, startIdx, j);
    if (i < endIdx)
        QuickSortRecursively(arr, i, endIdx);
}

//бинарный поиск, использующий рекурсию
int BSearchRecursively(int* arr, int val, int startIdx, int endIdx) {
    if (endIdx >= startIdx) {
        int mid = startIdx + (endIdx - startIdx) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            return BSearchRecursively(arr, val, startIdx, mid - 1);
        return BSearchRecursively(arr, val, mid + 1, endIdx);
    }
    return -1;
}

//бинарный поиск без рекурсии
int BSearch(int* arr, int val, int startIdx, int endIdx) {
    while (startIdx <= endIdx) {
        int mid = startIdx + (endIdx - startIdx) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            startIdx = mid + 1;
        else
            endIdx = mid - 1;
    }
    return -1;
}

int main() {
    int N1 = 10000, N2 = 100;
    int Array1[N1];
    FillArray(Array1, N1, -1000, 1000); //заполнение массива случайными числами
    Search(Array1, N1, 42);
    int Array2[N2];
    FillArray(Array2, N2, -10, 10);

    auto t1start = std::chrono::steady_clock::now();
    Search(Array2, N1, 7);
    auto t1end = std::chrono::steady_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds> (t1end - t1start);

    cout << "Unsorted array:\n";
    Print(Array2, N2);

    QuickSortRecursively(Array2, 0, 99); //сортировка с рекурсией
    QuickSort(Array2, 0, 99); //сортировка без рекурсии

    cout << "\nQuicksorted array:\n";
    Print(Array2, N2);

    auto t2start = std::chrono::steady_clock::now();
    auto idx = BSearchRecursively(Array2, 7, 0, 99); //бинарный поиск с рекурсией
    auto t2end = std::chrono::steady_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds> (t2end - t2start);

    auto t3start = std::chrono::steady_clock::now();
    BSearch(Array2, 7, 0, 99); //бинарный поиск без рекурсии
    auto t3end = std::chrono::steady_clock::now();
    auto time3 = std::chrono::duration_cast<std::chrono::milliseconds> (t3end - t3start);

    if (idx == -1)
        cout << "\nThere is no such element in the array.\n";
    else
        cout << "\nThe element has been found, its index is " << idx << ".";

    cout << "\nSearch time comparison (linear, binary recursive, binary iterative): "
         << time1.count() << ", " << time2.count() << ", " << time3.count() << endl;
    return 0;
}