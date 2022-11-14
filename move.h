// It models Reference
// Elem is element type of It
// swaps the values of each pointer
void swap(It a, It b) {
  Elem tmp = *a;
  *a = *b;
  *b = tmp;
}

// It models BidirectionalIterator
void reverse(It f, It l) {
  if (f == l) return;
  if (f == --l) return;
  swap(f, l);
  reverse(++f, l);
}

// It models BidirectionalIterator
// rotates so that *m is at the front
// return the final place of l
It rotate(It f, It m, It l) {
  reverse(f, m);
  reverse(m, l);
  reverse(f, l);
  return f + (l - m);
}

It copy(It f, It l, It out) {
  for (; !(f == l); ++out, ++f)
    *out = *f;
  return out;
}

It buffer(ptrdiff_t n) {
  assert(n > 0);
  It buff = (It) malloc(n * sizeof(Elem));
  if (buff == NULL) exit(1);
  return buff;
}
