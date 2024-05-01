#include <iostream>
#include <cstdlib>
#include <ctime>

//Функция заполнения массива случайными числами
template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
    srand(time(NULL));
    for (int i = 0; i < lenght; i++)
        arr[i] = rand() % (right - left) + left;
}

//Функция вывода массива в консоль.
template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b }\n";
}

//Функция линейного поиска ПЕРВОГО вхождения значения key в массив arr начиная с позиции begin.
template<typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {
    for (int i = begin; i < length; i++)
        if (arr[i] == key)
            return i;
    return -1; // Возвращаем значение "-1" в том случае если нужного числа нет в массиве.
}

//Функция линейного поиска ПОСЛЕДНЕГО вхождения значения key в массив arr
template<typename T>
int search_last_index(T arr[], const int length, T key) {
    for (int i = length - 1; i >= 0; i--)
        if (arr[i] == key)
            return i;
    return -1; // Возвращаем значение "-1" в том случае если нужного числа нет в массиве.
}

//Функция линейного поиска ПОСЛЕДНЕГО вхождения значения key в массив arr c позиции begin.
template<typename T>
int search_last_index(T arr[], const int length, T key, int begin) {
    for (int i = begin; i >= 0; i--)
        if (arr[i] == key)
            return i;
    return -1; // Возвращаем значение "-1" в том случае если нужного числа нет в массиве.
}

//Функция возвращает значение минимального элемента массива;
template<typename T>
int arr_min(T arr[], const int lenght) {
    int min = arr[0];
    for (int i = 0; i < lenght; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

//Функция возвращает значение максимального элемента массива;
template<typename T>
int arr_max(T arr[], const int lenght) {
    int max = arr[0];
    for (int i = 0; i < lenght; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

//Функция возвращает среднее арифметическое всех элиментов массива
template<typename T>
int mean_value(T arr[], const int lenght) {
    int result = 0;
    for (int i = 0; i < lenght; i++)
        result += arr[i];
    return result / lenght;
}

//Функция выводит все элементы массива, переданные в диапазон
template <typename T>
void range(T arr[], const int length, T left, T right) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++)
        if (arr[i] > left && arr[i] < right)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b }\n";
}

//Функция возвращает количество вхождений переданного лемента в массив
template<typename T>
int count(T arr[], const int length, T key) {
    int counter{};
    for (int i = length - 1; i >= 0; i--) {
        if (arr[i] == key)
            counter++;
    }
    return counter;
}

//Функция сортировка пузырьком
template<typename T>
void bubble_sort(T arr[], const int lenght) {
    for (int i = lenght - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
	setlocale(LC_ALL, "Russian");

    std::cout << "Задача 1. Изначальный массив:\n";

    const int size = 20;
    int arr[size];
    
    fill_arr(arr, size, -50, 51);
    
    print_arr(arr, size);
    
    std::cout << "Индекс первого вхождения числа: " << search_index(arr, size, 10) << "\n";
    
    std::cout << "Индекс последнего вхождения числа: " << search_last_index(arr, size, 10) << "\n";
    
    std::cout << "Минимальное число массива: " << arr_min(arr, size) << "\n";
    
    std::cout << "Максимальное число массива: " << arr_max(arr, size) << "\n";
    
    std::cout << "Ср. арифметическое значений массива: " << mean_value(arr, size) << "\n";
    
    std::cout << "Количество вхождений переданного элимента в массив: " << count(arr, size, 10) << "\n";
    
    std::cout << "Элименты массива из заданного диапазона:\n";
    range(arr, size, 12, 18);
    
    std::cout << "Отсортированный массив:\n";
    bubble_sort(arr, size);
    print_arr(arr, size);
    
	return 0;
}