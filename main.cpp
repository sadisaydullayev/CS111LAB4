
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// ========================================
// EXERCISE 1: ARRAY SUM
// ========================================
// int arraySum(int A[], int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += A[i];
//     }
//     return sum;
// }
//
// int main() {
//     int sizes[] = {1000, 5000, 10000, 50000, 100000};
//
//     for (int n : sizes) {
//         int* A = new int[n];
//
//         for (int i = 0; i < n; i++) {
//             A[i] = rand() % 100;
//         }
//
//         auto start = high_resolution_clock::now();
//         volatile int sum = arraySum(A, n);
//         auto stop = high_resolution_clock::now();
//
//         cout << "n = " << n
//              << " Time = "
//              << duration_cast<microseconds>(stop - start).count()
//              << " us, Sum = " << sum << endl;
//
//         delete[] A;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 2: LINEAR SEARCH
// ========================================
// int linearSearch(int A[], int n, int key) {
//     for (int i = 0; i < n; i++) {
//         if (A[i] == key) return i;
//     }
//     return -1;
// }
//
// int main() {
//     int sizes[] = {1000, 5000, 10000, 50000, 100000};
//
//     for (int n : sizes) {
//         int* A = new int[n];
//         for (int i = 0; i < n; i++) {
//             A[i] = i;
//         }
//
//         auto start = high_resolution_clock::now();
//         volatile int result = linearSearch(A, n, A[0]);
//         auto stop = high_resolution_clock::now();
//         cout << "n=" << n << " Best: "
//              << duration_cast<nanoseconds>(stop-start).count()
//              << " ns" << endl;
//
//         start = high_resolution_clock::now();
//         result = linearSearch(A, n, A[n/2]);
//         stop = high_resolution_clock::now();
//         cout << "Average: "
//              << duration_cast<nanoseconds>(stop-start).count()
//              << " ns" << endl;
//
//         start = high_resolution_clock::now();
//         result = linearSearch(A, n, -999999);
//         stop = high_resolution_clock::now();
//         cout << "Worst: "
//              << duration_cast<nanoseconds>(stop-start).count()
//              << " ns" << endl;
//
//         delete[] A;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 3: BUBBLE SORT
// ========================================
// void bubbleSort(int A[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - 1 - i; j++) {
//             if (A[j] > A[j+1]) {
//                 int temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp;
//             }
//         }
//     }
// }
//
// int main() {
//     int sizes[] = {1000, 5000, 10000, 50000, 100000};
//
//     for (int n : sizes) {
//         int* A = new int[n];
//         for (int i = 0; i < n; i++) {
//             A[i] = rand();
//         }
//
//         auto start = high_resolution_clock::now();
//         bubbleSort(A, n);
//         auto stop = high_resolution_clock::now();
//
//         cout << "n = " << n << " Time = "
//              << duration_cast<milliseconds>(stop-start).count()
//              << " ms" << endl;
//
//         delete[] A;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 4: STATIC VS DYNAMIC ARRAY
// ========================================
int main() {
    const int CAP = 100000;
    static int A[CAP];
    int sizes[] = {1000, 5000, 10000, 50000, 100000};

    for (int n : sizes) {
        int* B = new int[n];

        auto start = high_resolution_clock::now();
        for (int i = 0; i < n; i++) A[i] = i;
        auto stop = high_resolution_clock::now();

        cout << "Static: "
             << duration_cast<microseconds>(stop-start).count()
             << " us" << endl;

        start = high_resolution_clock::now();
        for (int i = 0; i < n; i++) B[i] = i;
        stop = high_resolution_clock::now();

        cout << "Dynamic: "
             << duration_cast<microseconds>(stop-start).count()
             << " us" << endl;

        cout << "Static bytes: " << sizeof(A) << endl;
        cout << "Dynamic bytes: " << n * sizeof(int) << endl;

        delete[] B;
    }
    return 0;
}























// ========================================
// EXERCISE 5: VECTOR PUSH_BACK VS RESERVE
// ========================================
// int main() {
//     int sizes[] = {1000, 5000, 10000, 50000, 100000};
//
//     for (int n : sizes) {
//         vector<int> v;
//
//         auto start = high_resolution_clock::now();
//         for (int i = 0; i < n; i++) {
//             v.push_back(i);
//         }
//         auto stop = high_resolution_clock::now();
//
//         cout << "n=" << n << " No reserve: "
//              << duration_cast<microseconds>(stop-start).count()
//              << " us, Capacity=" << v.capacity() << endl;
//
//         vector<int> w;
//         w.reserve(n);
//
//         start = high_resolution_clock::now();
//         for (int i = 0; i < n; i++) {
//             w.push_back(i);
//         }
//         stop = high_resolution_clock::now();
//
//         cout << "With reserve: "
//              << duration_cast<microseconds>(stop-start).count()
//              << " us, Capacity=" << w.capacity() << endl;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 6: BUBBLE SORT VS STD::SORT
// ========================================
// void bubbleSort(int A[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - 1 - i; j++) {
//             if (A[j] > A[j+1]) {
//                 int temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp;
//             }
//         }
//     }
// }
//
// int main() {
//     int sizes[] = {100, 500, 1000, 5000, 10000, 100000};
//
//     for (int n : sizes) {
//         vector<int> original(n);
//         for (int i = 0; i < n; i++) original[i] = rand();
//
//         vector<int> A = original;
//         vector<int> B = original;
//
//         auto start = high_resolution_clock::now();
//         bubbleSort(A.data(), n);
//         auto stop = high_resolution_clock::now();
//         double bubbleTime = duration<double, milli>(stop-start).count();
//
//         start = high_resolution_clock::now();
//         sort(B.begin(), B.end());
//         stop = high_resolution_clock::now();
//         double stdTime = duration<double, milli>(stop-start).count();
//
//         cout << "n=" << n
//              << " Bubble=" << bubbleTime
//              << " ms, std::sort=" << stdTime
//              << " ms, Ratio="
//              << (stdTime > 0 ? bubbleTime/stdTime : 0)
//              << endl;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 7: MATRIX MULTIPLICATION
// ========================================
// int main() {
//     int sizes[] = {50, 100, 200, 400};
//
//     for (int n : sizes) {
//         vector<vector<int>> A(n, vector<int>(n));
//         vector<vector<int>> B(n, vector<int>(n));
//         vector<vector<int>> C(n, vector<int>(n, 0));
//
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 A[i][j] = rand() % 10;
//                 B[i][j] = rand() % 10;
//             }
//         }
//
//         auto start = high_resolution_clock::now();
//
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 0; k < n; k++) {
//                     C[i][j] += A[i][k] * B[k][j];
//                 }
//             }
//         }
//
//         auto stop = high_resolution_clock::now();
//
//         cout << "n=" << n << " Time="
//              << duration_cast<milliseconds>(stop-start).count()
//              << " ms, Bytes="
//              << 3LL*n*n*sizeof(int) << endl;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 8: RECURSIVE VS ITERATIVE FIBONACCI
// ========================================
// long long fibRecursive(int n) {
//     if (n <= 1) return n;
//     return fibRecursive(n-1) + fibRecursive(n-2);
// }
//
// long long fibIterative(int n) {
//     long long a = 0, b = 1;
//     for (int i = 0; i < n; i++) {
//         long long next = a + b;
//         a = b;
//         b = next;
//     }
//     return a;
// }
//
// int main() {
//     int sizes[] = {20, 25, 30, 35};
//
//     for (int n : sizes) {
//         auto start = high_resolution_clock::now();
//         long long result = fibRecursive(n);
//         auto stop = high_resolution_clock::now();
//
//         cout << "Recursive n=" << n << " Result=" << result
//              << " Time="
//              << duration_cast<microseconds>(stop-start).count()
//              << " us" << endl;
//
//         start = high_resolution_clock::now();
//         result = fibIterative(n);
//         stop = high_resolution_clock::now();
//
//         cout << "Iterative n=" << n << " Result=" << result
//              << " Time="
//              << duration_cast<microseconds>(stop-start).count()
//              << " us" << endl;
//     }
//     return 0;
// }


// ========================================
// EXERCISE 9: ARRAY VS VECTOR VS LINKED LIST
// ========================================
//
// struct Node {
//     int data;
//     Node* next;
// };
//
// int main() {
//     int sizes[] = {1000, 5000, 10000, 50000, 100000};
//
//     for (int n : sizes) {
//         cout << "\nInput size: " << n << endl;
//
//         // VECTOR INSERTION
//         vector<int> v;
//         auto start = high_resolution_clock::now();
//
//         for (int i = 0; i < n; i++) {
//             v.push_back(i);
//         }
//
//         auto stop = high_resolution_clock::now();
//         auto vectorInsert = duration_cast<nanoseconds>(stop-start).count();
//
//         // ARRAY INSERTION
//         int* A = new int[n];
//
//         start = high_resolution_clock::now();
//
//         for (int i = 0; i < n; i++) {
//             A[i] = i;
//         }
//
//         stop = high_resolution_clock::now();
//         auto arrayInsert = duration_cast<nanoseconds>(stop-start).count();
//
//         // LINKED LIST INSERTION
//         Node* head = nullptr;
//         Node* tail = nullptr;
//
//         start = high_resolution_clock::now();
//
//         for (int i = 0; i < n; i++) {
//             Node* newNode = new Node;
//             newNode->data = i;
//             newNode->next = nullptr;
//
//             if (head == nullptr) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }
//
//         stop = high_resolution_clock::now();
//         auto listInsert = duration_cast<nanoseconds>(stop-start).count();
//
//         // VECTOR SEARCH
//         int key = n - 1;
//
//         start = high_resolution_clock::now();
//         volatile int vectorFound = -1;
//
//         for (int i = 0; i < n; i++) {
//             if (v[i] == key) {
//                 vectorFound = i;
//                 break;
//             }
//         }
//
//         stop = high_resolution_clock::now();
//         auto vectorSearch = duration_cast<nanoseconds>(stop-start).count();
//
//         // ARRAY SEARCH
//         start = high_resolution_clock::now();
//         volatile int arrayFound = -1;
//
//         for (int i = 0; i < n; i++) {
//             if (A[i] == key) {
//                 arrayFound = i;
//                 break;
//             }
//         }
//
//         stop = high_resolution_clock::now();
//         auto arraySearch = duration_cast<nanoseconds>(stop-start).count();
//
//         // LINKED LIST SEARCH
//         start = high_resolution_clock::now();
//
//         Node* temp = head;
//         volatile int listFound = -1;
//         int index = 0;
//
//         while (temp != nullptr) {
//             if (temp->data == key) {
//                 listFound = index;
//                 break;
//             }
//             temp = temp->next;
//             index++;
//         }
//
//         stop = high_resolution_clock::now();
//         auto listSearch = duration_cast<nanoseconds>(stop-start).count();
//
//         // PRINT RESULTS
//         cout << "Vector insert: " << vectorInsert << " ns" << endl;
//         cout << "Array insert: " << arrayInsert << " ns" << endl;
//         cout << "Linked list insert: " << listInsert << " ns" << endl;
//
//         cout << "Vector search: " << vectorSearch << " ns" << endl;
//         cout << "Array search: " << arraySearch << " ns" << endl;
//         cout << "Linked list search: " << listSearch << " ns" << endl;
//
//         cout << "Vector bytes: "
//              << v.capacity() * sizeof(int) << endl;
//
//         cout << "Array bytes: "
//              << n * sizeof(int) << endl;
//
//         cout << "Linked list bytes: "
//              << n * sizeof(Node) << endl;
//
//         cout << "Node size: "
//              << sizeof(Node) << " bytes" << endl;
//
//         // FREE MEMORY
//         delete[] A;
//
//         while (head != nullptr) {
//             Node* next = head->next;
//             delete head;
//             head = next;
//         }
//     }
//
//     return 0;
// }
