#include<iostream>

void bublesortline1(int** arr, int N, int no)
{
	int i = 0;
	int j;
	int temp;
	while (i < (N-1))
	{
		j = i;
		while (j < (N-1))
		{
			if (arr[no][j] > arr[no][j + 1])
			{
				temp = arr[no][j];
				arr[no][j] = arr[no][j + 1];
				arr[no][j + 1] = temp;
			}
			j++;
		}
		i++;
	}
		
}

int main()
{
	const int N = 2;
	int matrix[N+1][N+1];
	for (int i = 0; i < N+1; i++)
		for (int j = 0; j < N+1; j++)
			std::cin >> matrix[i][j];
	int i =N+1;
	int j = 0;
	int k = 0;
	int temp;
	__asm
	{
	jmp start	

	bublesortline:
		
		L3:
			mov ebx, N
			cmp j, ebx
			jge L7
				mov ebx, j
				mov k, ebx
				L4:
					mov ebx, N
					cmp k, ebx
					jge L5
						lea esi, [matrix+eax][0]
						mov ebx, k
						mov edx, [esi+ebx*4]
						cmp edx, [esi + ebx * 4+4]
						jng L6
							mov ecx, [esi+ebx*4+4]
							mov [esi+ebx*4+4], edx
							mov [esi+ebx*4] , ecx
						L6:
						inc k
						jmp L4
				L5:
				inc j
				jmp L3
		L7:
	ret

	bubblesortcollumn:


	ret

		
	start:

		L1:
			cmp i, 0
			je L2
			mov eax,N
			inc eax
			sub eax, i
			call bublesortline

			dec i
			jmp L1
		L2:
	}
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < N + 1; j++)
			std::cout << matrix[i][j];
	return 0;
}