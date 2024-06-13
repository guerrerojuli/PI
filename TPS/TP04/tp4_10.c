int dcm(int a, int b) {
  int auxi;

  do{
    auxi = a % b;
    a = b;
    b = auxi;
  } while(auxi > 0);

  return a;
}
