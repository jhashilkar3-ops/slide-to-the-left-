#include "slide.hpp"

static void shiftLeftOnce(int arr[], int size) {
   int temp = arr[0];
   for (int i = 0; i < size - 1; i++)
      arr[i] = arr[i + 1];
   arr[size - 1] = temp;
}

static void shiftRightOnce(int arr[], int size) {
   int temp = arr[size - 1];
   for (int i = size - 1; i > 0; i--)
      arr[i] = arr[i - 1];
   arr[0] = temp;
}


void arrayShift(int arr[], int size, int shifts) {
   if (size <= 0) return;
   shifts = shifts % size;
   for (int i = 0; i < shifts; i++)
      shiftLeftOnce(arr, size);
}

void arrayShiftLeft(int arr[], int size, int shifts) {
   arrayShift(arr, size, shifts);
}

void arrayShiftRight(int arr[], int size, int shifts) {
   if (size <= 0) return;
   shifts = shifts % size;
   for (int i = 0; i < shifts; i++)
      shiftRightOnce(arr, size);
}


void vectorShift(std::vector<int>& vec, int shifts) {
   int size = static_cast<int>(vec.size());
   if (size <= 0) return;
   shifts = shifts % size;
   if (shifts == 0) return;

   auto reverseRange = [&](int lo, int hi) {
      while (lo < hi) {
         int tmp  = vec[lo];
         vec[lo]  = vec[hi];
         vec[hi]  = tmp;
         lo++; hi--;
      }
   };

   reverseRange(0,      shifts - 1);
   reverseRange(shifts, size - 1);
   reverseRange(0,      size - 1);
}
