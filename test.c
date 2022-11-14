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

  int notsort[6] = {6, 5, 4, 2, 3, 1};
  int sorts[6] = {6, 5, 4, 2, 3, 1};

  copy(notsort, notsort + 6, sorts);
  binary_insertion_sort_(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  binary_insertion_sort(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));

  copy(notsort, notsort + 6, sorts);
  insertion_sort_(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  insertion_sort(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  merge_sort_(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  merge_sort(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));

  copy(notsort, notsort + 6, sorts);
  It p_ = partition_(sorts, sorts + 6, 4);
  printf("%ld : ", p_ - sorts);
  print(sorts, sorts + 6);
  assert(p_ == sorts + 3);
  
  copy(notsort, notsort + 6, sorts);
  It p = partition(sorts, sorts + 6, 4);
  printf("%ld : ", p - sorts);
  print(sorts, sorts + 6);
  assert(p == sorts + 3);
  
  copy(notsort, notsort + 6, sorts);
  It sp_ = stable_partition_(sorts, sorts + 6, 4);
  printf("%ld : ", sp_ - sorts);
  print(sorts, sorts + 6);
  assert(sp_ == sorts + 3);

  copy(notsort, notsort + 6, sorts);
  quicksort_(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  quicksort(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));

  copy(notsort, notsort + 6, sorts);
  quicksort_order_(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));
  
  copy(notsort, notsort + 6, sorts);
  quicksort_order(sorts, sorts + 6);
  print(sorts, sorts + 6);
  assert(is_sorted(sorts, sorts + 6));

  
  return 0;
}
