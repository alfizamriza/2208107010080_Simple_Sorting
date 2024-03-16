Tugas 2
Nama	: Alfi Zamriza
NPM	: 2208107010080
Struktur Data dan Algoritma

## Deskripsi

Program ini adalah implementasi sederhana dari beberapa algoritma pengurutan dan penyusunan angka dalam bahasa C. Algoritma-algoritma yang digunakan meliputi:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort

Setiap algoritma diimplementasikan dalam fungsi terpisah dan kemudian dijalankan pada sejumlah angka acak untuk menunjukkan kinerjanya.

## Cara Menjalankan Program

1. Pastikan Anda memiliki compiler C yang terinstal pada sistem Anda, seperti GCC.
2. Buka terminal atau command prompt.
3. Salin kode program dari file `2208107010080_Simple_Sorting.c` ke dalam file baru atau langsung ke dalam IDE C Anda.
4. Simpan file tersebut dengan nama yang diinginkan, misalnya `2208107010080_Simple_Sorting.c`.
5. Compile program menggunakan compiler C, contoh: `gcc 2208107010080_Simple_Sorting.c -o sorting_program`.
6. Jalankan program yang telah dikompilasi, misalnya: `./sorting_program`.
7. Program akan meminta Anda untuk memasukkan jumlah angka yang akan diurutkan.
8. Ikuti petunjuk yang muncul di layar untuk melihat hasil pengurutan.

## Fungsi yang Digunakan

1. `void quickShuffle(int *array, int n)`: Fungsi untuk mengacak urutan array menggunakan metode pertukaran acak.
2. `void bubbleSort(int arr[], int n)`: Fungsi untuk mengurutkan array menggunakan algoritma Bubble Sort.
3. `void selectionSort(int arr[], int n)`: Fungsi untuk mengurutkan array menggunakan algoritma Selection Sort.
4. `void insertionSort(int arr[], int n)`: Fungsi untuk mengurutkan array menggunakan algoritma Insertion Sort.
5. `void printNumbers(int numbers[], int n, int pilih, int mode)`: Fungsi untuk mencetak angka-angka ke dalam file "numbers.txt" sebelum atau setelah pengurutan dilakukan, beserta metode pengurutan yang digunakan.

