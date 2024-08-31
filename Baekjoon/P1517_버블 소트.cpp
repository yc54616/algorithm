#include <iostream>
#include <vector>

using namespace std;

void merge(int start, int end);
void mergeSort(int start, int end);

static vector<int> A;
static vector<int> tmp;
static long result;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	A = vector<int>(N, 0);
	tmp = vector<int>(N, 0);
	
	for(int i = 0; i < N; i++)
		cin >> A[i];
	
	mergeSort(0, N - 1);
		
	cout << result; 
}

void merge(int start, int end){
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	while(i <= mid && j <= end){
		if(A[i] <= A[j])
			tmp[k++] = A[i++];
		else{
			result = result + j - k;
			tmp[k++] = A[j++];
		}
	}
	
	while(i <= mid)
		tmp[k++] = A[i++];
	while(j <= end)
		tmp[k++] = A[j++];
	
	for(int i = start; i <= end; i++)
		A[i] = tmp[i];
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, end);
	}
}
