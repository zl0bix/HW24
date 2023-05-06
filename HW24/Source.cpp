#include<iostream>
#include<Windows.h>

void resize_arr(int arr[], const int length, unsigned int num);

int main() {
	//HW24.1
	std::cout << "\n\n\t\tHW24.1\n\n";
	const int sizeA = 2;
	int* A = (int*)malloc(sizeof(int) * sizeA);
	const int sizeB = 3;
	int* B = (int*)malloc(sizeof(int) * sizeB);
	int* C = NULL;
	const int sizeC = sizeA + sizeB;
	A[0] = 1;
	A[1] = 2;
	B[0] = 3;
	B[1] = 4;
	B[2] = 5;
	C = (int*)realloc(A,sizeof(int) * sizeC);
	//free(A);
	for (int i = sizeA; i < sizeC; i++)
		C[i] = B[i - sizeA];
	//free(B);
	for (int i = 0; i < sizeC; i++)
		std::cout << C[i] << ' ';
	//free(C);

	//HW24.2
	std::cout << "\n\n\t\tHW24.2\n\n";
	const int size2 = 5;
	int arr2[size2]{ 1,2,3,4,5 };
	int new_num = 11;
	resize_arr(arr2, size2, new_num);
	
	system("pause");
	return 0;
}
void resize_arr(int arr[], const int length, unsigned int num) {
	if (num <= 0)
		std::cout << "Error!!!";
	else if (num > length) {
		int* tmp = new int[num];		
		for (int i = 0; i < num; i++) {
			if (i < length) {
				tmp[i] = arr[i];
				std::cout << tmp[i] << ' ';
			}
			else {
				tmp[i] = 0;
				std::cout << tmp[i] << ' ';
			}
		}
		delete[] tmp;
	}
	else {
		int* tmp = new int[num];
		for (int i = 0; i < num; i++) {
			tmp[i] = arr[i];
			std::cout << tmp[i] << ' ';
		}
		delete[] tmp;
	}
}