#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int kor;
    int eng;
    int math;
    Student(string n, int k, int e, int m) {
        name = n;
        kor = k;
        eng = e;
        math = m;
    }
    string getName() {
        return name;
    }
};

vector<Student> arr;

bool compare(Student a, Student b) {
    int size = min(a.name.length(), b.name.length());
    if (a.kor > b.kor) return true;
    else if (a.kor < b.kor) return false;
    else {
        if (a.eng > b.eng) return false;
        else if (a.eng < b.eng) return true;
        else {
            if (a.math > b.math) return true;
            else if (a.math < b.math) return false;
            else {
                for (int i = 0; i < size; i++) {
                    if (a.name[i] < b.name[i]) return true;
                    else if (a.name[i] > b.name[i]) return false;
                    else continue;
                }
            }
        }
    }
    if (size == a.name.length()) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name;
        int k, e, m;
        cin >> name >> k >> e >> m;
        Student tmp(name, k, e, m);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << arr[i].getName() << '\n';
    }
}