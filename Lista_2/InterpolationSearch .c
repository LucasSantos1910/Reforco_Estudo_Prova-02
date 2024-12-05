
int interpolationSearch(int array[], int low, int high, int n)
{
    int index = 0;
    
    if (low <= high && n >= array[low] && n <= array[high])
    {
        index = low + (((double)(high - low) / (array[high] - array[low])) * (n - array[low]));

        if (array[index] == n)
        {
            return index;
        }
        
        if (array[index] < n)
        {
            return interpolationSearch(array, index + 1, high, n);
        }

        return interpolationSearch(array, low, index - 1, n);
    }
    
    return -1;
}

int main(void)
{
    int arr[] = {24, 69, 121, 157, 420, 666, 1533};
    int size = sizeof(arr) / sizeof(arr[0]);

    int n = 121;
    int i = interpolationSearch(arr, 0, size - 1, n);

    if (i == -1)
    {
        printf("Elemento não encontrado!");
    }
    else
    {
        printf("Elemento no índice %d.", i);
    }
        
    return 0;

    }

//     "Binary Search é mais simples e facil de implementar. Ele é mais eficiente para a maioria dos casos em listas ordenadas, porém não é tão eficiente em listas muito grandes com elementos altamente não-uniformemente distribuídos.
// Interpolation Search é mais rápido que a busca binária para listas grandes com distribuição uniforme de dados. Ela reduz significativamente o número de comparações quando os dados são uniformemente distribuídos, mas tem maior de implementação e o desempenho pode se degradar significativamente se os dados não forem uniformemente distribuídos.



