//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int num[1000000] = {
//    0,
//};
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N;
//    for (int i = 0; i < N; i++)
//    {
//        cin >> num[i];
//    }
//    sort(num, num + N);
//    for (int i = 0; i < N; i++)
//    {
//        cout << num[i] << "\n";
//    }
//}


// #include <iostream>
// #include <vector>

// using namespace std;

// void merge(int start, int end);
// void merge_sort(int start, int end);

// static vector<int> A;
// static vector<int> tmp;

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
	
// 	int N;
// 	cin >> N;
	
// 	A = vector<int>(N, 0);
// 	tmp = vector<int>(N, 0);
	
// 	for(int i = 0; i < N; i++)
// 		cin >> A[i];
	
// 	merge_sort(0, N - 1);
	
// 	for(int i = 0; i < N; i++)
// 		cout << A[i] << "\n";
	
// }

// void merge(int start, int end){
// 	int mid = (start + end) / 2;
// 	int i = start;
// 	int j = mid + 1;
// 	int k = start;
	
// 	while(i <= mid && j <= end){
// 		if(A[i] < A[j])
// 			tmp[k++] = A[i++];
// 		else
// 			tmp[k++] = A[j++];
// 	}
	
// 	while(i <= mid)
// 		tmp[k++] = A[i++];
// 	while(j <= end)
// 		tmp[k++] = A[j++];
	
// 	for(int i = start; i <= end; i++)
// 		A[i] = tmp[i];
// }

// void merge_sort(int start, int end){
// 	if(start < end){
// 		int mid = (start + end) / 2;
// 		merge_sort(start, mid);
// 		merge_sort(mid + 1, end);
// 		merge(start, end);
// 	}
// }

#include <iostream>
#include <vector>

using namespace std;

void merge(int start, int end);
void mergeSort(int start, int end);

static int N;
static vector<int> A, temp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A = vector<int>(N, 0);
	temp = vector<int>(N, 0);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	mergeSort(0, N - 1);

	for(int i = 0; i < N; i++){
		cout << A[i] << "\n";
	}

}

void merge(int start, int end){
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if(A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	while(i <= mid){
		temp[k++] = A[i++];
	}
	while(j <= end){
		temp[k++] = A[j++];
	}

	for(int l = start; l <= end; l++){
		A[l] = temp[l];
	}
	
}

void mergeSort(int start, int end){
	int mid = (start + end) / 2;
	if(start < end){
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, end);
	}

}
