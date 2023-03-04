#include <stdio.h>

void thousands(int *num_ptr);
void hundreds(int *num_ptr);
void tens(int *num_ptr);
void units(int *num_ptr);

int main(void)
{
  int num, *num_ptr = &num;

  printf("Enter num: ");
  scanf("%d", &num);
  if (num % 1000 > 3)
    printf("This program cannot generate the roman numeral of numbers greater than or equal to 4000");
  else
  {
    printf("The roman numeral of %d is ", num);
    thousands(num_ptr);
  }
  return (0);
}

// for thousands

void thousands(int *num_ptr)
{
  int th, i;

  th = *num_ptr / 1000;

  if (th != 0)
  {
    for (i = 0; i < th; i++)
      putchar('M');
    *num_ptr -= (th * 1000);
  }
  hundreds(num_ptr);
}

// for hundreds

void hundreds(int *num_ptr)
{
  int hun, i;

  hun = *num_ptr / 100;

  if (hun != 0)
  {
    if (hun < 4)
    {
      for (i = 0; i < hun; i++)
        putchar('C');
    }
    else if (hun == 4)
        printf("CD");
    else if (hun == 5)
      putchar('D');
    else if (hun > 5 && hun < 9)
    {
      putchar('D');
      hun -= 5;
      for (i = 0; i < hun; i++)
        putchar('C');
      hun += 5;
    }
    else
    {
      printf("CM");
    }
    *num_ptr -= (hun * 100);
  }
  tens(num_ptr);
}

// for tens

void tens(int *num_ptr)
{
  int ten, i;

  ten = *num_ptr / 10;

  if (ten != 0)
  {
    if (ten < 4)
    {
      for (i = 0; i < ten; i++)
        putchar('X');
    }
    else if (ten == 4)
      printf("LX");
    else if (ten == 5)
      putchar('L');
    else if (ten > 5 && ten < 9)
    {
      putchar('L');
      ten -= 5;
      for (i = 0; i < ten; i++)
        putchar('X');
      ten += 5;
    }
    else
      printf("XC");

    *num_ptr -= (ten * 10);
  }
  units(num_ptr);
}

// for units

void units(int *num_ptr)
{
  int unit, i;

  unit = *num_ptr;

  if (unit != 0)
  {
    if (unit < 4)
    {
      for (i = 0; i < unit; i++)
        putchar('I');
    }
    else if (unit == 4)
      printf("IV");
    else if (unit == 5)
      putchar('V');
    else if (unit > 5 && unit < 9)
    {
      putchar('V');
      unit -= 5;
      for (i = 0; i < unit; i++)
        putchar('I');
      unit += 5;
    }
    else
      printf("IX");
  }
}