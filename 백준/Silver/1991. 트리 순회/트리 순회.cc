#include <bits/stdc++.h>
using namespace std;

pair<char, char> node[26];
int n;

void preorder(char ch) {
    if (ch == '.') return;

    cout << ch;
    preorder(node[ch - 'A'].first);
    preorder(node[ch - 'A'].second);
}

void inorder(char ch) {
    if (ch == '.') return;

    inorder(node[ch - 'A'].first);
    cout << ch;
    inorder(node[ch - 'A'].second);
}

void postorder(char ch) {
    if (ch == '.') return;

    postorder(node[ch - 'A'].first);
    postorder(node[ch - 'A'].second);
    cout << ch;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        node[parent - 'A'].first = left;
        node[parent - 'A'].second = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

}