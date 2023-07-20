#include<stdio.h>

void gnome_sort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
	int array[] = { 1, 5, 8, 3, 6, 0, 9, 4, 2, 7 };
	
	int n = sizeof(array) / sizeof(array[0]);
	
	puts("Sorted sequence before Gnome sort: ");
	printArray(array, n);
	
	gnome_sort(array, n);
	
	puts("Sorted sequence after Gnome sort: ");
	printArray(array, n);

	return (0);
}

void gnome_sort(int arr[], int n) {
	int index = 0;

	while (index < n) {
		if (index == 0)
			index++;
		if (arr[index] >= arr[index - 1])
			index++;
		else {
			int temp = arr[index];
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			index--;
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}