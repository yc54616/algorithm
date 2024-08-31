#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	string name;
	int num;
} Member;

//void swap(Member *a, Member *b);
void swap(vector<Member> &A);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<Member> A;
	
	string tempName;
	int tempNum;
	int N, m[5];
	char oper;
	bool check;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> oper >> tempNum >> tempName;
		if(oper == 'I'){
			check = true;
			for(int j = 0; j < A.size(); j++){
				if(A[j].num == tempNum){
					check = false;
					break;
				}
			}
			if(check){
				A.push_back(Member{tempName, tempNum});
			}
		}
		else if(oper == 'D'){
			for(int j = 0; j < A.size(); j++){
				if(A[j].num == tempNum){
					A.erase(A.begin() + j);
					break;
				}
			}
		}
	}
	for(int i = 0; i < 5; i++){
		cin >> m[i];
	}
	
	swap(A);
	
//	for(int i = 0; i < A.size() - 1; i++){
//		for(int j = 0; j < A.size() - 1 - i; j++){
//			if(A[j].num > A[j+1].num){
//				swap(A[j], A[j+1]);
//			}
//		}
//	}
	
	for(int i = 0; i < 5; i++){
		cout << A[m[i]-1].num << " "<< A[m[i]-1].name << "\n";
	}
}

//void swap(Member *a, Member *b){
//	Member c;
//	c = *a;
//	*a = *b;
//	*b = c;
//}

void swap(vector<Member> &A){
	Member B;
	for(int i = 0; i < A.size() - 1; i++){
		for(int j = 0; j < A.size() - 1 - i; j++){
			if(A[j].num > A[j+1].num){
				B = A[j];
				A[j] = A[j+1];
				A[j+1] = B;
			}
		}
	}
}
