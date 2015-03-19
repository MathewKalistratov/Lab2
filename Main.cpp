#include <stdio.h>  
#include <stdlib.h>   

//! Данная функция производит сортировку массива интов по неубыванию
/*!
* \param [in] *a − входной массив
* \param [in] N − индекс последнего элемента
*/
void quickSort(int* a, int N) 
{
	int i = 0, j = N;
	int temp, p;  //! Буферная переменная и переменная для среднего элемента массива
	p = a[N>>1];  //! С помощью хитрой побитовой операции находим средний элемент. Аналогично можно сделать p = a[N/2];   
	do {
		while (a[i] < p) i++;
		while (a[j] > p) j--;  //! Разделяем массив
		if (i <= j) {
			temp = a[i]; a[i] = a[j]; a[j] = temp;  //! Меняем соседние элементы местами при условии i <= j
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(a, j);
	if (N > i) quickSort(a + i, N - i);  //! Рекурсивно вызываем функцию, пока элементы не кончатся
}

//! Функция main() − точка входа в программу.
int main()
{
	int N; //! Количество элементов
	printf("Enter, how many elements you wanna to sort: "); scanf("%d", &N);
	int *sourceArray = (int*)malloc(N*sizeof(int)); //! Массив интов

	for (int i = 0; i<N; i++)  //! В данном цикле вводим их
	{
		printf("Element number %i: ", i+1); scanf("%d", &sourceArray[i]);
	}

	quickSort(sourceArray, N - 1);  //! Сортируем

	printf("\nYour sorted elements: \n");

	for (int i = 0; i<N; i++)  //! Выводим
	{
		printf("%d ", sourceArray[i]);
	}
	system("pause");  //! Останавливаем программу
	return 0;
}