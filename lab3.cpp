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

int main() {
    //Ввод
    setlocale(LC_ALL, "Russian");
    int n, m;
    int k;
    vector<int> a, b;
    cout << "Введите количество элементов в первом множестве" << endl;
    cin >> n;
    cout << "Введите элементы первого множества" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        a.push_back(k);
        if (count(a.begin(), a.end(), a[i]) > 1) {
            a.pop_back();
        }
    }
    cout << "Введите количество элементов во втором множестве" << endl;
    cin >> m;
    cout << "Введите элементы второго множества" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        b.push_back(k);
        if (count(b.begin(), b.end(), b[i]) > 1) {
            b.pop_back();
        }
    }
    n = a.size();
    m = b.size();
    map<int, int> funk;
    for (int i = 0; i < n; ++i){
        funk[a[i]] = 0;
    }
    int kolvo;
    int first, second;
    int ans = 1;
    cout << "введите количество пар" << endl;
    cin >> kolvo;
    cout << "введите пары элементов" << endl;
    int i = 0;
    while (i < kolvo) {
        cin >> first >> second;
        if (count(a.begin(), a.end(), first) == 0 || count(b.begin(), b.end(), second) == 0) {
            cout << "ошибка" << endl;
        }
        else {
            funk[first] += 1;
            i++;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (funk[a[j]] != 1) {
            ans = 0;
            break;
        }
    }
    if (ans == 1) {
        cout << "функция";
    }
    else {
        cout << "не функция";
    }
    return 0;
}