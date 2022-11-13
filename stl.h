/*  A C-like implementation of the STL
 *  algorithms for educational purposes.
 *
 *  Writer: gabriel-domingues
 */

#include <stdbool.h>

It print(It f, It l) {
  for (It it = f; it != l; ++it)
    printf("%c %d ", (it == f) ? '{' : ',', *it);
  printf("}\n");
}

#include "move.h"
#include "search.h"
#include "sort.h"
