#include <stdio.h>

int main()
{
	int input[10] = {9,7,1,5,8,2,6,3,4,0};
	int temp;

	for (int i = 0; i < 10; i++)
	{
		for(int j=0;j<10;j++)
			if (input[i] < input[j])
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
	}
	// 선택정렬


	/*for (int x = 0; x < 10; x++)
	{
		for (int i = 1; i < 10; i++)
		{
			if (input[i - 1] > input[i])
			{
				temp = input[i - 1];
				input[i - 1] = input[i];
				input[i] = temp;
			}
		}
	}*/
	// 버블정렬
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
	return 0;

}