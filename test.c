#include <stdio.h>
#include <assert.h>

typedef int* It;
typedef int Elem;

#include "stl.h"

int main(int argc, const char* argv[]) {
  int arr[6] = {1, 2, 3, 3, 4, 5};

  for (It it = arr; it != arr + 6; ++it)
    printf("%c %d ", (it == arr) ? '{' : ',', *it);
  printf("}\n");
  
  assert(arr + 4 == find_(arr, arr + 6, 4));
  assert(arr + 4 == find(arr, arr + 6, 4));
  assert(arr + 2 == lower_bound_(arr, arr + 6, 3));
  assert(arr + 2 == lower_bound(arr, arr + 6, 3));
  assert(arr + 4 == upper_bound_(arr, arr + 6, 3));
  assert(arr + 4 == upper_bound(arr, arr + 6, 3));
  
  int none[6] = {1, 2, 3, 3, 5, 6};

  for (It it = none; it != none + 6; ++it)
    printf("%c %d ", (it == none) ? '{' : ',', *it);
  printf("}\n");
  
  assert(none + 6 == find_(none, none + 6, 4));
  assert(none + 6 == find(none, none + 6, 4));
  assert(none + 4 == lower_bound_(none, none + 6, 4));
  assert(none + 4 == lower_bound(none, none + 6, 4));
  assert(none + 4 == upper_bound_(none, none + 6, 4));
  assert(none + 4 == upper_bound(none, none + 6, 4));
  
  return 0;
}
