/*----------------------------------------------------------
 * Lab #4: Sorting Algorithms
 *
 * Date: October-2023
 * Authors:
 *           A01749879 Julio Cesar Vivas Medina
 *           A01798380 Ulises Jaramillo Portilla
 *----------------------------------------------------------*/
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "Lab4_Sorting.h"

int main(){
    //sizes vectors
    std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000, 10000000};

    int sizeV = sizes.size();
    int MaxV = 1000;

    //vectors for unsorted, ascending, and descending data
    std::vector<std::vector<int>> unsorted(sizeV);
    std::vector<std::vector<int>> ascending(sizeV);
    std::vector<std::vector<int>> descending(sizeV);

    //resize all vectors inside vectors unsorted, ascending, and descending
    for(int i = 0; i < sizeV; ++i){
        unsorted[i].resize(sizes[i]);
        ascending[i].resize(sizes[i]);
        descending[i].resize(sizes[i]);
    }

    //fill unsorted, ascending and descending with the correct values
    for(int i = 0; i < sizeV; ++i){
        fill_random(unsorted[i], MaxV);
        fill_incremental(ascending[i], MaxV);
        fill_decremental(descending[i], MaxV);
    }

    //select which vector to sort and cout the runtime
    int pick;
    std::cout << "Select to Sort: \n 1) Unsorted \n 2) Ascending \n 3) Descending \n\n--> ";
    std::cin >> pick;

    if(pick == 1){
        for(int i = 0; i < sizeV; ++i){
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(unsorted[i]);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;

            std::cout << "Runtime for " << sizes[i] << " Unsorted vector size: " << total_time << " with insertionSort" << "\n";
            std::cout << "SORTED?: " << std::is_sorted(unsorted[i].begin(),unsorted[i].end()) << " " << "\n";
        }
    }else if(pick == 2){
        for(int i = 0; i < sizeV; ++i){
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(ascending[i]);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;

            std::cout << "Runtime for " << sizes[i] << " Ascending vector size: " << total_time << " with insertionSort" << "\n";
            std::cout << "SORTED?: " << std::is_sorted(ascending[i].begin(),ascending[i].end()) << " " << "\n";
        }
    }else if(pick == 3){
        for(int i = 0; i < sizeV; ++i){
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(descending[i]);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            double total_time = duration.count() / 1'000'000.0;

            std::cout << "Runtime for " << sizes[i] << " Descending vector size: " << total_time << " with insertionSort" << "\n";
            std::cout << "SORTED?: " << std::is_sorted(descending[i].begin(),descending[i].end()) << " " << "\n";
        }
    }
    return 0;
}