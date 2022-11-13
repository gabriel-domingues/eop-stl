// It models ForwardIterator
// Elem is element type of It
// returns true if all adjacent elements
// in the range [f, l) obey a weak ordering
// i.e. a total preorder
bool is_sorted_(It f, It l) {
  if (f == l) return true;
  It s = f; ++s; // s is the successor
  if (s == l) return true;
  return (*f <= *s) && is_sorted_(s, l);
}

// It models ForwardIterator
// Elem is element type of It
// returns true if all adjacent elements
// in the range [f, l) obey a weak ordering
// i.e. a total preorder
bool is_sorted(It f, It l) {
  if (f == l) return true;
  It s = f; ++s; // s is the successor
  while (!(s == l) && *f <= *s)
    ++s, ++f;
  return s == l;
}

// It models RandomAccessIterator
// Elem is element type of It
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void binary_insertion_sort_(It f, It l) {
  if (f == l) return;
  It end = l; end--; // end is the last element
  binary_insertion_sort_(f, end);
  It m = upper_bound(f, end, *end);
  rotate(m, end, l);
}

// It models RandomAccessIterator
// Elem is element type of It
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void binary_insertion_sort(It f, It l) {
  for (It it = f; it != l; ++it) {
    It end = it; ++end; // end is the last element
    It m = upper_bound(f, it, *it);
    rotate(m, it, end);
  }
}

// It models BidirectionalIterator
// Elem is element type of It
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void insertion_sort_(It f, It l) {
  if (f == l) return;
  It end = l; end--; // end is the last element
  insertion_sort_(f, end);
  for (It m = end; !(end == f) && *end < *(--m); --end)
    swap(m, end);
}


// It models BidirectionalIterator
// Elem is element type of It
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void insertion_sort(It f, It l) {
  for (It it = f; it != l; ++it) {
    for (It m = it, end = it;
	 !(end == f) && *end < *(--m); --end)
      swap(m, end);
  }
}
