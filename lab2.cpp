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
    string ans = "�����������";
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            ans = "�� �����������"
        }
    }
    cout << ans << endl;
}

void simm(vector<vector<int>> a) {
    string ans = "�����������";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                ans = "�� �����������";
                break;
            }
        }
        if (ans == "�� �����������") {
            break;
        }
    }
    cout << ans << endl;
}

void kososimm(vector<vector<int>> a) {
    string ans = "���������������";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                if (a[i][j] != 0) {
                    ans = "�� ���������������";
                    break;
                }
            }
            else {
                if (a[i][j] == a[j][i]) {
                    ans = "�� ���������������";
                    break;
                }
            }
        }
        if (ans == "�� ���������������") {
            break;
        }
    }
    cout << ans;
}

void tranz(vector<vector<int>> a) {
    string ans = "�����������";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int c = 0; c < n; ++c) {
                if (a[i][j] == 1 && a[j][c] == 1 && a[i][c] == 0) {
                    ans = "�� �����������";
                    break;
                }
            }
            if (ans == "�� �����������") {
                break;
            }
        }
        if (ans == "�� �����������") {
            break;
        }
    }
    cout << ans;
}

int main() {
    //����
    setlocale(LC_ALL, "Russian");
    cout << "������� ������ �������" << endl;
    cin >> n;
    a.resize(n, vector<int>(n));
    cout << "������� ������� ���������" << endl;
    while (err == 1) {
        err = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++i) {
                cin >> a[i][j];
                if (a[i][j] != 0 && a[i][j] != 1) {
                    err = 1;
                    cout << "������" << endl;
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