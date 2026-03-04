#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159

double rectangle_area(double* params) {
  return params[0] * params[1];
}

double circle_area(double* params) {
  return PI * params[0] * params[0];
}

double triangle_area(double* params) {
  return 0.5 * params[0] * params[1];
}

void print_area(char* shape, double area) {
  printf("%s Area: %.2f\n", shape, area);
}

/*
* Pass the arguments of the program and the number of arguments for the shape area
* Returns the type converted arguments in an array
*/
double* change_params(char** args, int reqargs) {
  double* params = malloc(reqargs * sizeof(double));
  for (int i=0;i<reqargs;i++) {
    params[i] = atof(args[i+2]);
  }
  return params;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage:\n");
    printf("  ./shapes rectangle width height\n");
    printf("  ./shapes triangle base height\n");
    printf("  ./shapes circle radius\n");
    return 1;
  }

  char *shape = argv[1];
  double area = 0.0;

  if (strcmp(shape, "rectangle") == 0) {
    if (argc != 4) {
      printf("Error: Rectangle needs width and height.\n");
      return 1;
    }

    double* params = change_params(argv,2);
    area = rectangle_area(params);
    free(params);
    print_area(shape,area);


  } else if (strcmp(shape, "triangle") == 0) {
    if (argc != 4) {
      printf("Error: Triangle needs base and height.\n");
      return 1;
    }

    double* params = change_params(argv,2);
    area = rectangle_area(params);
    free(params);
    print_area(shape,area);


  } else if (strcmp(shape, "circle") == 0) {
    if (argc != 3) {
      printf("Error: Circle needs radius.\n");
      return 1;
    }

    double* params = change_params(argv,1);
    area = rectangle_area(params);
    free(params);
    print_area(shape,area);


  } else {
    printf("Error: Unknown shape '%s'. Use rectangle, triangle, or circle.\n", shape);
    return 1;
  }

  return 0;
}