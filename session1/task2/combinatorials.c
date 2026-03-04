#include <stdlib.h>
#include <stdio.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n) {
  // the base case - this determines when the recursion should stop
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

int Choose(int n, int r) {
  // nCr should return the total combinations of r items out of n.
  // This is calculated by: n! / (r! (n - r)!)
  return factorial(n)/(factorial(r)*factorial(n-r));
}

int Perms(int n, int r) {
  // nPr should return the total permutations of r items out of n.
  // This is calculated by: n! / (n-r)!
  return factorial(n)/factorial(n-r);
}

int main(int argc, char **argv) {
  /*
  The program should accept a command line argument as follows:
  ./combinatorials n C r
  ./combinatorials n P r

  where n and r are both positive integers, and r is always less than or equal to n.

  for example:
  ./combinatorials 7 C 2

  Your program should then calculate and print out the correct result

  Add appropriate validation to your program to make your code robust.

  You should try and use functions to write your program.

  */

  if (argc != 4) {
    printf("Usage: ./combinatorials n C r or ./combinatorials n P r, where n>=r\n");
    return 1;
  }

  int result = 0;

  int n = atoi(argv[1]);
  int r = atoi(argv[3]);

  if (n <= 0 || r<= 0 || r>n) {
    printf("Usage: ./combinatorials n C r or ./combinatorials n P r, where n>=r\n");
    printf("Both n and r must be positive integers\n");
  }

  switch (argv[2][0]) {
    case 'C':
      result = Choose(n,r);
      break;
    case 'P':
      result = Perms(n,r);
      break;
    default:
      printf("Usage: ./combinatorials n C r or ./combinatorials n P r\n");
      return 1;
  }

  printf("%d %c %d = %d\n", n, argv[2][0], r, result);
}