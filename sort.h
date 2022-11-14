ptrdiff_t min(ptrdiff_t a, ptrdiff_t b) { return (a < b) ? a : b ; }
ptrdiff_t max(ptrdiff_t a, ptrdiff_t b) { return (a < b) ? b : a ; }

// It models ForwardIterator
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
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void binary_insertion_sort_(It f, It l) {
  if (f == l) return;
  It end = l; --end; // end is the last element
  binary_insertion_sort_(f, end);
  It m = upper_bound(f, end, *end);
  rotate(m, end, l);
}

// It models RandomAccessIterator
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

// It models BidirectionalIterator
// accepts [f, m) and [m, l) sorted ranges
// writes to buff a sorted permutation of [f, l)
void merge(It f, It m, It l, It buff) {
  It out = buff;
  for (It s = f, r = m; !(s == m && r == l); ++out) {
    if (s == m || (!(r == l) && *s > *r))
      { *out = *r; ++r; }
    else
      { *out = *s; ++s; }
  }
  It l_ = copy(buff, out, f);
  assert(l_ == l);
};

// It models BidirectionalIterator
// accepts [f, m) and [m, l) sorted ranges
// and makes [f, l) sorted
void merge_(It f, It m, It l) {
  It buff = buffer(l - f);
  merge(f, m, l, buff);
  free(buff);
};

// It models RandomAccessIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void merge_sort_(It f, It l) {
  It m = f + (l - f) / 2;
  if (m == f || m == l) return;
  merge_sort_(f, m);
  merge_sort_(m, l);
  merge_(f, m, l);
}

// It models RandomAccessIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
// moreover, this sort is stable
// i.e. equivalent elements preserve order
void merge_sort(It f, It l) {
  ptrdiff_t n = l - f;
  It buff = buffer(n);
  if (n <= 1) return;
  for (ptrdiff_t step = 1; step < n; step *= 2) {
    for (ptrdiff_t delta = step; delta < n; delta += 2 * step)
      merge(f + (delta - step), f + delta, f + min(n, delta + step), buff);
  }
  free(buff);
}


// It models BidirectionalIterator
// Elem is element type of It
// permutes the elements in [f, l)
// and returns p such that
// [f, p) < val <= [p, l) 
It partition_(It f, It l, Elem val) {
  if (f == l) return l;
  if (*f < val) ++f;
  else swap(f, --l);
  return partition_(f, l, val);
}

// It models BidirectionalIterator
// Elem is element type of It
// permutes the elements in [f, l)
// and returns p such that
// [f, p) < val <= [p, l) 
It partition(It f, It l, Elem val) {
  while (!(f == l))
    if (*f < val) ++f;
    else swap(f, --l);
  return f;
}

// It models RandomAcessIterator
// Elem is element type of It
// permutes the elements in [f, l)
// and returns p such that
// [f, p) < val <= [p, l)
// moreover, this partition is stable
// i.e. equivalent elements preserve order
It stable_partition_(It f, It l, Elem val) {
  if (f == l) return l;
  It m = f + (l - f) / 2;
  if (m == f) return m + (*m < val);
  It r = stable_partition_(f, m, val);
  It s = stable_partition_(m, l, val);
  return rotate(r, m, s);
}

// It models BidirectionalIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
void quicksort_(It f, It l) {
  if (f == l) return;
  It pivot = f;
  It cut = partition(++pivot, l, *f);
  pivot = rotate(f, pivot, cut); // pivot in place
  quicksort_(f, pivot);
  quicksort_(cut, l);
}

// It models BidirectionalIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
void quicksort(It f, It l) {
  while (!(f == l)) {
    It pivot = f;
    It cut = partition(++pivot, l, *f);
    pivot = rotate(f, pivot, cut); // pivot in place 
    quicksort_(f, pivot);
    f = cut;
  }
}

// It models BidirectionalIterator
// Elem is element type of It
// permutes the elements in [f, l)
// such that is_sorted(f, l)
It partition_order(It f, It l, Elem val) {
  if (!(f == l)) --l;
  while(!(f == l)) {
    while (!(f == l) && *f < val) ++f;
    while (!(f == l) && *l > val) --l;
    swap(f, l);
  }
  return f;
}

// It models BidirectionalIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
void quicksort_order_(It f, It l) {
  if (f == l) return;
  It cut = partition_order(f, l, *f);
  quicksort_order_(f, cut);
  quicksort_order_(++cut, l);
}

// It models BidirectionalIterator
// permutes the elements in [f, l)
// such that is_sorted(f, l)
void quicksort_order(It f, It l) {
  for (It cut = f; !(f == l); f = ++cut) {
    cut = partition_order(f, l, *f);
    quicksort_order(f, cut);
  }
}
