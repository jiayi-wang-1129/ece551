int max(int num1, int num2) {
  if (num1 > num2) {
    return num1;
  }
  else {
    return num2;
  }
}
void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w;
  w = max(size1, (x_offset + size2));

  //compute the max of size1 and (y_offset + size2).  Call this h
  int h;
  h = max(size1, y_offset + size2);
  //count from 0 to h. Call the number you count with y
  for (int y = 0; y < h; y++) {
    //count from 0 to w. Call the number you count with x
    for (int x = 0; x < w; x++) {
      //check if  EITHE
      if (((x >= x_offset && x < x_offset + size2) ||
           ((y >= y_offset && y < y_offset + size2) &&
            (x == x_offset || x == x_offset + size2 - 1)))) {
        printf("*");
      }

      else {
        if ((x < size1 && (y == 0 || y == size1 - 1)) ||
            ((y < size1) && (x == 0 || x == size1 - 1))) {
          printf("#");
        }
        else {
          printf(" ");
        }
      }
    }
    printf("/n");
    //if not,
    // check if EITHER
    //    x is less than size1 AND (y is either 0 or size1-1)
  }
}
