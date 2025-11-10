#include <iostream>
using namespace std;

//part-a
void ChangeLocation(char *Array, int b1, int b2) {
    if (!Array) return;
    if (b1 >= b2) return;
    char tmp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = tmp;
    ChangeLocation(Array, b1 + 1, b2 - 1);
}

//part-b
static void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
}

static bool allOnes(const int arr[], int size) {
    for (int i = 0; i < size; i++) 
        if (arr[i] != 1) return false;
    return true;
}

static void PrintPatternHelper(int arr[], int& size) {
    printArray(arr, size);
    if (allOnes(arr, size)) return;
    
    if (size == 1 && arr[0] > 1 && (arr[0] % 2 == 0)) {
        int half = arr[0] / 2;
        arr[0] = half;
        arr[1] = half;
        size = 2;
        PrintPatternHelper(arr, size);
        return;
    }

    int i = 0;
    while (i < size && arr[i] == 1) ++i;
    if (i >= size) return;
    
    if (i + 1 < size) {
        arr[i] -= 1;
        arr[i+1] += 1;
    } else {
        int old = arr[i];
        arr[i] = 1;
        arr[size] = old - 1;
        size++;
    }
    PrintPatternHelper(arr, size);
}

void PrintPattern(int &n) {
    if (n <= 0) return;
    int arr[100] = {n};
    int size = 1;
    PrintPatternHelper(arr, size);
}

int main() {
    char arr[] = {'N','I','S','H','A','Y','E'};
    const int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Original:\n";
    for (int i=0;i<len;i++) {
        if (i) cout << ' ';
        cout << '\'' << arr[i] << '\'';
    }
    cout << "\n\n";

    char a1[len];
    for(int i = 0; i < len; i++) {
        a1[i] = arr[i];
    }
    ChangeLocation(a1, 2, 6); 
    cout << "After ChangeLocation:\n";
    for (int i=0;i<len;i++) { if (i) cout << ' '; cout << '\'' << a1[i] << '\''; } cout << "\n\n";

    cout << "Print Pattern:\n";
    int n = 5;
    PrintPattern(n);

    return 0;
}
