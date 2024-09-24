#include <algorithm>
#include <iostream>
using namespace std;
int BinarySearch(int num, int A[], int left, int right) {
  int middle;
  while (left <= right) {
    middle = (left + right) / 2;
    if (num == A[middle])
      return 1;
    else if (num > A[middle])
      left = middle + 1;
    else
      right = middle - 1;
  }
  return 0;
}

int main() {
  int A[100000];
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];
  int B[100000];
  int M;
  cin >> M;
  for (int i = 0; i < M; i++)
    cin >> B[i];

  sort(A, A + N);

  for (int i = 0; i < M; i++) {
    cout << BinarySearch(B[i], A, 0, N-1);
    cout << "\n";
  }
}