#include <stdio.h>
#include <stdlib.h>

int getlimit() {
  int limit;
  char input[200];

  printf("Enter the speed limit: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &limit);
  }
  return limit;
}

int getspeed() {
  int speed;
  char input[200];

  printf("Enter the driver's speed: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &speed);
  }
  return speed;
}

int calculatefine(int excess) {
  int fine;
  if (excess <= 10) {
    fine = 50;
  } else if (excess <= 20) {
    fine = 100;
  } else {
    fine = 200;
  }
  return fine;
}

int main() {
  int speed_limit, driver_speed, fine = 0;

  // Get user input for speed limit
  speed_limit = getlimit();

  // Get user input for driver's speed
  driver_speed = getspeed();

  // Determine if the driver is speeding
  if (driver_speed > speed_limit) {
    int excess_speed = driver_speed - speed_limit;

    // Calculate fine based on how much over the limit
    fine = calculatefine(excess_speed);

    printf("Fine: $%d\n", fine);
  } else {
    printf("No fine needed.\n");
  }

  return 0;
}