void main() {
  int j = 0;
  for (int i = 0; i < 1 << 29; i++) {
    j += i * i;
  }
}
