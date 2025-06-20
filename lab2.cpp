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

int n, err = 1;
vector<vector<int>> a;

void refl(vector<vector<int>> a) {
    string ans = "рефлексивно";
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            ans = "не рефлексивно"
        }
    }
    cout << ans << endl;
}

void simm(vector<vector<int>> a) {
    string ans = "симметрично";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                ans = "не симметрично";
                break;
            }
        }
        if (ans == "не симметрично") {
            break;
        }
    }
    cout << ans << endl;
}

void kososimm(vector<vector<int>> a) {
    string ans = "кососимметрично";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                if (a[i][j] != 0) {
                    ans = "не кососимметрично";
                    break;
                }
            }
            else {
                if (a[i][j] == a[j][i]) {
                    ans = "не кососимметрично";
                    break;
                }
            }
        }
        if (ans == "не кососимметрично") {
            break;
        }
    }
    cout << ans;
}

void tranz(vector<vector<int>> a) {
    string ans = "транзитивно";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int c = 0; c < n; ++c) {
                if (a[i][j] == 1 && a[j][c] == 1 && a[i][c] == 0) {
                    ans = "не транзитивно";
                    break;
                }
            }
            if (ans == "не транзитивно") {
                break;
            }
        }
        if (ans == "не транзитивно") {
            break;
        }
    }
    cout << ans;
}

int main() {
    //¬вод
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите размер матрицы" << endl;
    cin >> n;
    a.resize(n, vector<int>(n));
    cout << "введите матрицу отношени€" << endl;
    while (err == 1) {
        err = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++i) {
                cin >> a[i][j];
                if (a[i][j] != 0 && a[i][j] != 1) {
                    err = 1;
                    cout << "ќшибка" << endl;
                    break;
                }
            }
            if (err == 1) {
                break;
            }
        }
    }
    refl(a);
    simm(a);
    kososimm(a);
    tranz(a);
    return 0;
}