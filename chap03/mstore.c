long mult2(long, long);

long multstore(long x, long y, long *dest) {
  long t = mult2(x, y);
  *dest = t;
}
