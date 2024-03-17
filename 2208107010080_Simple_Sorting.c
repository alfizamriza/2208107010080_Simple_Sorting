#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Fungsi untuk melakukan pengocokan cepat (quick shuffle) array
void quickShuffle(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        int temp = array[i];
        array[i] = array[r];
        array[r] = temp;
    }
}

// Fungsi untuk mengurutkan array menggunakan algoritma Bubble Sort
void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan array menggunakan algoritma Selection Sort
void selectionSort(int arr[], int n)
{
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi untuk mengurutkan array menggunakan algoritma Insertion Sort
void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk mencetak angka-angka dalam array ke dalam file
void printNumbers(int numbers[], int n, int pilih, int mode)
{
    FILE *fptr;
    if (mode == 1)
    {
        fptr = fopen("numbers.txt", "w"); // Mode penulisan file baru
    }
    else
    {
        fptr = fopen("numbers.txt", "a"); // Mode penulisan tambahan pada file yang sudah ada
    }

    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        free(numbers); // Membebaskan memori yang dialokasikan untuk array
        exit(1);
    }

    switch (pilih)
    {
    case 1:
        fprintf(fptr, "SEBELUM DIURUTKAN\n");
        break;
    case 2:
        fprintf(fptr, "\n\nSESUDAH DIURUTKAN MENGUNAKAN BUBBLE SORT------\n");
        break;
    case 3:
        fprintf(fptr, "\n\nSESUDAH DIURUTKAN MENGUNAKAN SELECTION SORT------\n");
        break;
    case 4:
        fprintf(fptr, "\n\nSESUDAH DIURUTKAN MENGUNAKAN INSERTION SORT------\n");
        break;
    default:
        break;
    }

    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        free(numbers);
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i % 50 == 0)
        { // Ganti dengan 10 agar tidak hardcoded
            fprintf(fptr, "\n");
        }
        fprintf(fptr, "%d\t", numbers[i]);
    }
    fclose(fptr);
}

int main()
{
    int n;
    printf("Isi jumlah angka yang kamu mau \n--->\t");
    scanf("%d", &n);
    int *numbers = malloc(n * sizeof(int)); // Alokasi memori untuk array angka
    int *numbers_copy = malloc(n * sizeof(int)); // Alokasi memori untuk array angka salinan

    // Mengisi array dengan angka dari 1 hingga n
    for (int i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
    }

    srand(time(NULL)); // Inisialisasi seed untuk fungsi rand()

    quickShuffle(numbers, n); // Mengocok array secara cepat
    printNumbers(numbers, n, 1, 1); // Mencetak array sebelum diurutkan ke dalam file

    // Melakukan pengurutan menggunakan Bubble Sort
    memcpy(numbers_copy, numbers, n * sizeof(int)); // Meng-copy isi array ke array salinan
    clock_t start_bubbleSort = clock(); // Memulai pencatatan waktu
    bubbleSort(numbers_copy, n); // Melakukan pengurutan
    clock_t end_bubbleSort = clock(); // Menghentikan pencatatan waktu
    printNumbers(numbers_copy, n, 2, 2); // Mencetak array setelah diurutkan menggunakan Bubble Sort ke dalam file

    // Melakukan pengurutan menggunakan Selection Sort
    memcpy(numbers_copy, numbers, n * sizeof(int)); // Meng-copy isi array ke array salinan
    clock_t start_selectionSort = clock(); // Memulai pencatatan waktu
    selectionSort(numbers_copy, n); // Melakukan pengurutan
    clock_t end_selectionSort = clock(); // Menghentikan pencatatan waktu
    printNumbers(numbers_copy, n, 3, 2); // Mencetak array setelah diurutkan menggunakan Selection Sort ke dalam file

    // Melakukan pengurutan menggunakan Insertion Sort
    memcpy(numbers_copy, numbers, n * sizeof(int)); // Meng-copy isi array ke array salinan
    clock_t start_insertionSort = clock(); // Memulai pencatatan waktu
    insertionSort(numbers_copy, n); // Melakukan pengurutan
    clock_t end_insertionSort = clock(); // Menghentikan pencatatan waktu
    printNumbers(numbers_copy, n, 4, 2); // Mencetak array setelah diurutkan menggunakan Insertion Sort ke dalam file

    // Menghitung waktu yang diperlukan untuk setiap algoritma pengurutan
    double time_taken_bubbleSort = ((double)(end_bubbleSort - start_bubbleSort)) / CLOCKS_PER_SEC;
    double time_taken_selectionSort = ((double)(end_selectionSort - start_selectionSort)) / CLOCKS_PER_SEC;
    double time_taken_insertionSort = ((double)(end_insertionSort - start_insertionSort)) / CLOCKS_PER_SEC;
    
    // Mencetak hasil pengurutan dan waktu eksekusi ke dalam konsol
    printf("+-----------------------+---------------------------+----------------------+\n");
    printf("| Algoritma Pengurutan  | Jumlah Bilangan (n)       | Waktu Eksekusi(detik)|\n");
    printf("+-----------------------+---------------------------+----------------------+\n");
    printf("| Bubble Sort           | %-25d | %-20.6f |\n", n, time_taken_bubbleSort);
    printf("| Selection Sort        | %-25d | %-20.6f |\n", n, time_taken_selectionSort);
    printf("| Insertion Sort        | %-25d | %-20.6f |\n", n, time_taken_insertionSort);
    printf("+-----------------------+---------------------------+----------------------+\n");

    // Membebaskan memori yang dialokasikan untuk array
    free(numbers);
    free(numbers_copy);

    return 0;
}
