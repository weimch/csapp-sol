void remdiv(long x, long y, long *qp, long *rp) {
  long q = x / y;
  long r = x % y;
  *qp = q;
  *rp = r;
}