//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void quickSort(vector<int> &A, int start, int end);
//void swap(vector<int> &A, int i, int j);
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	int N, K;
//	cin >> N >> K;
//	
//	vector<int> A(N, 0);
//	for(int i = 0; i < N; i++){
//		cin >> A[i];
//	}
//	
//	quickSort(A, 0, N - 1);
//	
//	cout << A[K-1];
//	
//}
//
//void quickSort(vector<int> &A, int start, int end){
//	if(start >= end)
//		return;
//		
//	int pivot = start;
//	int i = start + 1;
//	int j = end;
//	
//	while(i <= j){
//		while(i <= end && A[i] <= A[pivot])
//			i++;
//		while(start <= j && A[pivot] <= A[j])
//			j--;
//		
//		if(i > j)
//			swap(A, pivot, j);
//		else
//			swap(A, i, j);
//	}
//	
//	quickSort(A, start, j - 1);
//	quickSort(A, j + 1, end);
//}
//
//void swap(vector<int> &A, int i, int j){
//	A[i] = A[i] ^ A[j];
//	A[j] = A[i] ^ A[j];
//	A[i] = A[i] ^ A[j];
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> A(N, 0);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	sort(A.begin(), A.end());
	
	cout << A[K-1];
	
}
