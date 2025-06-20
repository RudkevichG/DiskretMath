#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define endl '\n'

int n;

vector<vector<int>> inp() {
    vector<vector<int>> a(n, vector<int>(n));
    int noerr = 0;
    cout << "Введите матрицу смежности" << endl;
    while (noerr == 0) {
        noerr = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] != 0 && a[i][j] != 1) {
                    noerr = 0;
                    break;
                }
            }
            if (noerr == 0) {
                cout << "ошибка" << endl;
                break;
            }
        }
    }
    return a;
}

vector<vector<int>> out(vector<vector<int>> a) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
    return a;
}

int main() {
    //Ввод
    setlocale(LC_ALL, "Russian");
    vector<vector<int>> matrix, ans;
    cout << "Введите количество вершин" << endl;
    cin >> n;
    matrix = inp();
    ans = out(matrix);
    cout << "Матрица достижимости:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}