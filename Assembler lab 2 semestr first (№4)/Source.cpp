#include<iostream>

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
		
		mov j, 0
		mov ecx, N
		inc ecx
		mul cl
		mov cl, 4
		mul cl	
		lea esi, [matrix + eax]
		L3:
			mov ebx, N
			cmp j, ebx
			jge L7
				mov k,0
				L4:
					mov ebx, N
					sub ebx, j
					cmp k, ebx
					jge L5
						mov ebx, k // проверить лишее ли
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
		mov j, 0
		lea esi, [matrix+eax*4]
		mov eax, N
		mov bl, 4
		mul bl
		L9:
			mov ebx, N
			cmp j, ebx
			jge L10
				mov k, 0
				L11:
					mov ebx, N
					sub ebx, j
					cmp k, ebx
					jge L12
						mov edx, k
						mul dl
						mov edx, [esi+eax]
						cmp edx, [esi+eax*2]
						

				L12:
				inc j
				jmp L9
		L10:
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
			mov eax, N
			mov i, eax
			inc i
		L8:
			cmp i, 0
			je L90
			mov eax, N
			inc eax
			sub eax, i
			call bubblesortcollumn
			dec i
			jmp L8
		L90:
	}
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < N + 1; j++)
			std::cout << matrix[i][j];
	return 0;
}