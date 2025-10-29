// recursion_solutions.cpp
#include <iostream>
#include <vector>
#include <cstring>
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

void ChangeLocation_1based(char *Array, int b1, int b2) {
    if (!Array) return;
    if (b1 <= 0 || b2 <= 0) return;
    ChangeLocation(Array, b1 - 1, b2 - 1);
}
void SwapEndpoints(char *Array, int b1, int b2) {
    if (!Array) return;
    char tmp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = tmp;
}
//part-b
static void printVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}
static bool allOnes(const vector<int>& v) {
    for (int x : v) if (x != 1) return false;
    return true;
}
static void PrintPatternHelper(vector<int>& v) {
    printVec(v);
    if (allOnes(v)) return;
    if (v.size() == 1 && v[0] > 1 && (v[0] % 2 == 0)) {
        int half = v[0] / 2;
        v.clear();
        v.push_back(half);
        v.push_back(half);
        PrintPatternHelper(v);
        return;
    }

    size_t i = 0;
    while (i < v.size() && v[i] == 1) ++i;
    if (i >= v.size()) return;
    if (i + 1 < v.size()) {
        v[i] -= 1;
        v[i+1] += 1;
    } else {
        int old = v[i];
        v[i] = 1;
        v.push_back(old - 1);
    }
    PrintPatternHelper(v);
}

void PrintPattern(int &n) {
    if (n <= 0) return;
    vector<int> v(1, n);
    PrintPatternHelper(v);
}

int main() {
    char arr[] = {'C','O','M','P','U','T','E','R'};
    const int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    for (int i=0;i<len;i++) {
        if (i) cout << ' ';
        cout << '\'' << arr[i] << '\'';
    }
    cout << "\n\n";

    char a1[len];
    memcpy(a1, arr, len);
    ChangeLocation(a1, 2, 6); 
    cout << "After ChangeLocation(a1, 2, 6) [reverse indices 2..6]:\n";
    for (int i=0;i<len;i++) { if (i) cout << ' '; cout << '\'' << a1[i] << '\''; } cout << "\n\n";

    char a2[len];
    memcpy(a2, arr, len);
    SwapEndpoints(a2, 2, 6);
    cout << "After SwapEndpoints(a2, 2, 6) [swap 0-based indices 2 and 6]:\n";
    for (int i=0;i<len;i++) { if (i) cout << ' '; cout << '\'' << a2[i] << '\''; } cout << "\n\n";

    cout << "PrintPattern example (n = 4):\n";
    int n = 4;
    PrintPattern(n);

    return 0;
}