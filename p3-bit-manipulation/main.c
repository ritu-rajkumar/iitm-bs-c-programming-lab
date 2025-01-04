#include <stdio.h>

/*
Note:
  This is an interactive program in which
  the inputs are passed in an interactive manner.

Run the below command to compile and run this program.
  gcc main.c -o main && ./main
*/

void toggle_every_kth_room(int *lights, int k)
{
  int mask = 0;
  for (int i = (k - 1); i < 16; i++)
  {
    mask |= 1 << i;
  }
  *lights ^= mask;
}

void toggle_even_rooms(int *lights)
{
  // Use the above function to toggle the even rooms
  // toggle_every_kth_room(...);
  int mask = 0x5555;
  *lights ^= mask;
}

int get_mask()
{
  int mask = 0;
  int input;
  while (1) {
    scanf("%d", &input);
    if (input == -1) {
      break;
    }
    mask |= (1 << input);
  }
  return mask;
}

void turn_on_lights(int *lights)
{
  int mask = get_mask();
  *lights |= mask; // Turn on the lights using bitwise OR
}

void turn_off_lights(int *lights)
{
  int mask = get_mask();
  *lights &= ~mask; // Turn off the lights using bitwise AND with negation
}

int count_lights(int lights)
{
  int count = 0;
  for (int i = 0; i < 16; i++) {
    count += (lights >> i) & 1; // Count the number of bits set to 1
  }
  return count;
}

void print_bin(int a)
{
  for (int i = 15; i >= 0; i--)
  {
    printf("%d", (a >> i) & 1);
    if (i % 4 == 0)
      printf(" ");
  }
  printf("\n");
}

int main()
{

  int lights;
  printf("Enter a positive integer: ");
  scanf("%d", &lights);
  printf("The 16-bit binary representation is:\t");
  print_bin(lights);

  // Task 1
  int k;
  printf("Enter the value for k: ");
  scanf("%d", &k);
  toggle_every_kth_room(&lights, k);
  printf("After toggling every k-th room (k=%d):\t", k);
  print_bin(lights);

  // Task 2
  toggle_even_rooms(&lights);
  printf("After toggling lights in even rooms:\t");
  print_bin(lights);

  puts("");

  // Task 3
  printf("Numbers to turn on (end with -1): \n");
  turn_on_lights(&lights);
  printf("After turning ON the given lights:\t");
  print_bin(lights);

  // Task 4
  printf("Numbers to turn off (end with -1): \n");
  turn_off_lights(&lights);
  printf("After turning OFF the given lights:\t");
  print_bin(lights);

  // Task 5
  int l = count_lights(lights);
  printf("Total number of lights ON = %d\n", l);
  return 0;
}
