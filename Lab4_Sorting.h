/*----------------------------------------------------------
 * Lab #4: Sorting Algorithms
 *
 * Date: October-2023
 * Authors:
 *           A01749879 Julio Cesar Vivas Medina
 *           A01798380 Ulises Jaramillo Portilla
 *----------------------------------------------------------*/

#pragma once

#include <cstdlib>
#include <algorithm>

// Starter Code
// ----------------------------------------------------------
void fill_random(std::vector<int>& values, int max_value) {
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

void fill_incremental(std::vector<int>& values, int max_value) {
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

void fill_decremental(std::vector<int>& values, int max_value) {
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = values.size() - 1; i >= 0; --i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}
// ----------------------------------------------------------

void insertionSort(std::vector<int>& data){
    int length = data.size();
    for(int i = 0; i <= length - 1 ; ++i){
        int current = data[i];
        int j = i;

        while (j > 0 && data[j - 1] > current) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = current;
    }
}

void selectionSort(std::vector<int>& data){
    int length = data.size();
    for(int i = 0; i < length - 1; ++i){
        int min_index = i;
        for(int j = i + 1; j  < length; ++j) {
            if (data.at(j) < data.at(min_index)){
                min_index = j;
            }
        }
        int temp = data[i];
        data[i] = data[min_index];
        data[min_index] = temp;
    }
}

// it actually has to start at index 1 not 0 as the book says
void bubbleSort(std::vector<int>& data) {
    int length = data.size();
    bool not_sorted = true;
    while (not_sorted) {
        not_sorted = false;
        for (int i = 1; i < length; i++) {
            if (data[i] < data[i - 1]) {
                int temp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = temp;
                not_sorted = true;
            }
        }
    }
}

// We use recursion in this function
void quickSort(std::vector<int>& data, int start, int end) {
    if (start >= end) {
        return;
    }

    int divider = data[start];
    int lo = start;
    int hi = end;

    while (true) {
        while (data[hi] >= divider) {
            hi--;
            if (hi <= lo) break;
        }

        if (hi <= lo) {
            data[lo] = divider;
            break;
        }
        data[lo] = data[hi];
        lo++;

        while (data[lo] < divider) {
            lo++;
            if (lo >= hi) break;
        }

        if (lo >= hi) {
            lo = hi;
            data[hi] = divider;
            break;
        }
        data[hi] = data[lo];
    }

    quickSort(data, start, lo - 1);
    quickSort(data, lo + 1, end);
}

void mergeSort(std::vector<int> &data, std::vector<int> &scratch, int start, int end) {
    if (start == end) return;

    int mid = (start + end) / 2;

    mergeSort(data, scratch, start, mid);
    mergeSort(data, scratch, mid + 1, end);

    int left_i = start;
    int right_i = mid + 1;
    int scratch_i = left_i;

    while (left_i <= mid && right_i <= end) {
        if (data[left_i] <= data[right_i]) {
            scratch[scratch_i] = data[left_i];
            left_i++;
        } else {
            scratch[scratch_i] = data[right_i];
            right_i++;
        }
        scratch_i++;
    }

    for (int i = left_i; i <= mid; i++) {
        scratch[scratch_i] = data[i];
        scratch_i++;
    }

    for (int i = right_i; i <= end; i++) {
        scratch[scratch_i] = data[i];
        scratch_i++;
    }

    for (int i = start; i <= end; i++) {
        data[i] = scratch[i];
    }
}

void countingSort(std::vector<int> &data, int max_value) {
    std::vector<int> counts(max_value + 1, 0);

    for (int i = 0; i < data.size(); i++) {
        counts[data[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_value; i++) {
        for (int j = 0; j < counts[i]; j++) {
            data[index] = i;
            index++;
        }
    }
}