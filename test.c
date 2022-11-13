#include <stdio.h>
#include <assert.h>

typedef int* It;
typedef int Elem;

#include "stl.h"

int main(int argc, const char* argv[]) {
  int arr[6] = {1, 2, 3, 3, 4, 5};
  print(arr, arr + 6);
  
  assert(arr + 4 == find_(arr, arr + 6, 4));
  assert(arr + 4 == find(arr, arr + 6, 4));
  assert(arr + 2 == lower_bound_(arr, arr + 6, 3));
  assert(arr + 2 == lower_bound(arr, arr + 6, 3));
  assert(arr + 4 == upper_bound_(arr, arr + 6, 3));
  assert(arr + 4 == upper_bound(arr, arr + 6, 3));
  
  int none[6] = {1, 2, 3, 3, 5, 6};
  print(none, none + 6);
  
  assert(none + 6 == find_(none, none + 6, 4));
  assert(none + 6 == find(none, none + 6, 4));
  assert(none + 4 == lower_bound_(none, none + 6, 4));
  assert(none + 4 == lower_bound(none, none + 6, 4));
  assert(none + 4 == upper_bound_(none, none + 6, 4));
  assert(none + 4 == upper_bound(none, none + 6, 4));

  assert(is_sorted_(none, none + 6));
  assert(is_sorted(none, none + 6));
  
  int notsort_1[6] = {6, 5, 4, 3, 2, 1};
  print(notsort_1, notsort_1 + 6);
  
  binary_insertion_sort_(notsort_1, notsort_1 + 6);
  print(notsort_1, notsort_1 + 6);
  assert(is_sorted(notsort_1, notsort_1 + 6));

  int notsort_2[6] = {6, 5, 4, 3, 2, 1};
  binary_insertion_sort(notsort_2, notsort_2 + 6);
  print(notsort_2, notsort_2 + 6);
  assert(is_sorted(notsort_2, notsort_2 + 6));
  
  int notsort_3[6] = {6, 5, 4, 3, 2, 1};
  insertion_sort_(notsort_3, notsort_3 + 6);
  print(notsort_3, notsort_3 + 6);
  assert(is_sorted(notsort_3, notsort_3 + 6));
  
  int notsort_4[6] = {6, 5, 4, 3, 2, 1};
  insertion_sort(notsort_4, notsort_4 + 6);
  print(notsort_4, notsort_4 + 6);
  assert(is_sorted(notsort_4, notsort_4 + 6));
  
  
  return 0;
}
