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

struct Element {
    char even1;
    char odd1;
    char odd2;
    char even2;
};

void inputArray(vector<Element>& mass, int size) {
    Element elem;

    for (int i = 0; i < size; ++i) {
        cout << "Input Element ijji " << i << ": ";
        string input;
        cin >> input;

        if (input.length() == 4 &&
            (input[0] >= '0' && input[0] <= '9' && (input[0] - '0') % 2 == 0) &&
            (input[1] >= '0' && input[1] <= '9' && (input[1] - '0') % 2 == 1) &&
            (input[2] >= '0' && input[2] <= '9' && (input[2] - '0') % 2 == 1) &&
            (input[3] >= '0' && input[3] <= '9' && (input[3] - '0') % 2 == 0))
        {
            elem.even1 = input[0];
            elem.odd1 = input[1];
            elem.odd2 = input[2];
            elem.even2 = input[3];
            mass.push_back(elem);
        }
        else {
            cout << "Error input" << endl;
            i--;
        }
    }
}

void printArray(const vector<Element>& mass) {
    for (int i = 0; i < mass.size(); ++i) {
        cout << "Element " << i << ": " << mass[i].even1 << mass[i].odd1 << mass[i].odd2 << mass[i].even2 << endl;
    }
}

void removeNonUnique(vector<Element>& mass) {
    vector<Element> uniqueElements;

    for (int i = 0; i < mass.size(); ++i) {
        bool isUnique = true;

        for (int j = 0; j < uniqueElements.size(); ++j) {
            if (mass[i].even1 == uniqueElements[j].even1 &&
                mass[i].odd1 == uniqueElements[j].odd1 &&
                mass[i].odd2 == uniqueElements[j].odd2 &&
                mass[i].even2 == uniqueElements[j].even2) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqueElements.push_back(mass[i]);
        }
    }

    mass.clear();
    for (size_t i = 0; i < uniqueElements.size(); ++i) {
        mass.push_back(uniqueElements[i]);
    }
}

//Объединение двух массивов
void unionArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); ++i)
        result.push_back(mass1[i]);
    for (int i = 0; i < mass2.size(); ++i)
        result.push_back(mass2[i]);
    removeNonUnique(result);
}

//пересечение
void intersection(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); ++i) {
        bool isNotUnique = false;

        for (int j = 0; j < mass2.size(); ++j) {
            if (mass1[i].even1 == mass2[j].even1 &&
                mass1[i].odd1 == mass2[j].odd1 &&
                mass1[i].odd2 == mass2[j].odd2 &&
                mass1[i].even2 == mass2[j].even2) {
                isNotUnique = true;
                break;
            }
        }

        if (isNotUnique) {
            result.push_back(mass1[i]);
        }
    }
}

//A/B
void ab(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); ++i) {
        bool inB = false;

        for (int j = 0; j < mass2.size(); ++j) {
            if (mass1[i].even1 == mass2[j].even1 &&
                mass1[i].odd1 == mass2[j].odd1 &&
                mass1[i].odd2 == mass2[j].odd2 &&
                mass1[i].even2 == mass2[j].even2) {
                inB = true;
                break;
            }
        }

        if (inB == false) {
            result.push_back(mass1[i]);
        }
    }
}

//B/A
void ba(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass2.size(); ++i) {
        bool inA = false;

        for (int j = 0; j < mass1.size(); ++j) {
            if (mass2[i].even1 == mass1[j].even1 &&
                mass2[i].odd1 == mass1[j].odd1 &&
                mass2[i].odd2 == mass1[j].odd2 &&
                mass2[i].even2 == mass1[j].even2) {
                inA = true;
                break;
            }
        }

        if (inA == false) {
            result.push_back(mass2[i]);
        }
    }
}

//симметрическая разность
void symmetrical(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
    for (int i = 0; i < mass1.size(); ++i) {
        bool inB = false;

        for (int j = 0; j < mass2.size(); ++j) {
            if (mass1[i].even1 == mass2[j].even1 &&
                mass1[i].odd1 == mass2[j].odd1 &&
                mass1[i].odd2 == mass2[j].odd2 &&
                mass1[i].even2 == mass2[j].even2) {
                inB = true;
                break;
            }
        }

        if (inB == false) {
            result.push_back(mass1[i]);
        }
    }
    for (int i = 0; i < mass2.size(); ++i) {
        bool inA = false;

        for (int j = 0; j < mass1.size(); ++j) {
            if (mass2[i].even1 == mass1[j].even1 &&
                mass2[i].odd1 == mass1[j].odd1 &&
                mass2[i].odd2 == mass1[j].odd2 &&
                mass2[i].even2 == mass1[j].even2) {
                inA = true;
                break;
            }
        }

        if (inA == false) {
            result.push_back(mass2[i]);
        }
    }
}

int main() {
    int size1, size2;
    vector<Element> mass1;
    vector<Element> mass2;
    vector<Element> mass_unification;
    vector<Element> mass_intersection;
    vector<Element> mass_ab, mass_ba;
    vector<Element> mass_s;

    cout << "Input SIZE first array: ";
    cin >> size1;

    inputArray(mass1, size1);
    cout << "\n";

    cout << "Input SIZE second array: ";
    cin >> size2;
    inputArray(mass2, size2);
    cout << "\n";

    cout << "ELEMENTS first array: " << endl;
    printArray(mass1);
    cout << "\n";

    cout << "ELEMENTS second array: " << endl;
    printArray(mass2);
    cout << "\n";

    // Объединение двух массивов
    unionArrays(mass_unification, mass1, mass2);
    cout << "ELEMENTS union arrays: " << endl;
    printArray(mass_unification);
    cout << "\n";

    //пересечение

    intersection(mass_intersection, mass1, mass2);
    cout << "ELEMENTS intersection arrays: " << endl;
    printArray(mass_intersection);
    cout << "\n";

    //A/B

    ab(mass_ab, mass1, mass2);
    cout << "A/B: " << endl;
    printArray(mass_ab);
    cout << "\n";

    //B/A

    ba(mass_ba, mass1, mass2);
    cout << "B/A: " << endl;
    printArray(mass_ba);
    cout << "\n";

    //симметрическая разность

    symmetrical(mass_s, mass1, mass2);
    cout << "symmetrical difference: " << endl;
    printArray(mass_s);
    cout << endl;

    return 0;
}