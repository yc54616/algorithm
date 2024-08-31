//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int N, num;
//	cin >> N;
//
//	int index[10001]; // 0~10,000
//	for (int i = 0; i <= 10001; i++)
//		index[i] = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> num;
//		index[num]++;
//	}
//	for (int i = 0; i <= 10000; i++)
//	{
//		for (int j = 0; j < index[i]; j++)
//			cout << i << "\n";
//	}
//}
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; 
	cin >> N;
	int count[10001] = {0,};
	int number;
	
	for(int i = 0; i < N; i++){
		cin >> number;
		count[number]++;
	}
	
	for(int i = 0; i <= 10000; i++){
		for(int j = 0; j < count[i]; j++)
			cout << i << "\n";
	}
	
	return 0;
}
