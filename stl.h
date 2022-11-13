/*  A C-like implementation of the STL
 *  algorithms for educational purposes.
 *
 *  Writer: gabriel-domingues
 */

// It models ForwardIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element == val
// or last if there was none
It find_(It f, It l, Elem val) {
  if (f == l) return l;
  if (*f == val) return f;
  else return find_(++f, l, val);
}

// It models ForwardIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element == val
// or last if there was none
It find(It f, It l, Elem val) {
  while (!(f == l || *f == val))
    ++f;
  return f;
}

// It models RandomAccessIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element >= val
// or last if there was none
It lower_bound_(It f, It l, Elem val) {
  if (f == l) return l;
  It m = f + (l - f) / 2;
  if (*m < val) return lower_bound_(m + 1, l, val);
  else return lower_bound_(f, m, val);
}

// It models RandomAccessIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element >= val
// or last if there was none
It lower_bound(It f, It l, Elem val) {
  while (!(f == l)) {
    It m = f + (l - f) / 2;
    if (*m < val) f = m + 1;
    else l = m;
  }
  return f;
}

// It models RandomAccessIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element > val
// or last if there was none
It upper_bound_(It f, It l, Elem val) {
  if (f == l) return l;
  It m = f + (l - f) / 2;
  if (*m > val) return upper_bound_(f, m, val);
  else return upper_bound_(m + 1, l, val);
}

// It models RandomAccessIterator
// Elem is element type of It
// returns the first element in [f, l)
// such that element > val
// or last if there was none
It upper_bound(It f, It l, Elem val) {
  while (!(f == l)) {
    It m = f + (l - f) / 2;
    if (*m > val) l = m;
    else f = m + 1;
  }
  return f;
}

