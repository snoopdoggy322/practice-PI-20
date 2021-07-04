#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  float numerator;
  float denominator;
} fraction;

int NOD(int n1, int n2)
{
  int div;
  if (n1 == n2)
    return n1;
  int d = n1 - n2;
  if (d < 0)
  {
    d = -d;
    div = NOD(n1, d);
  }
  else
    div = NOD(n2, d);
  return div;
}

int NOK(int n1, int n2)
{
  return n1 * n2 / NOD(n1, n2);
}

fraction substracFraction(fraction a, fraction b)
{
  fraction result;
  if (a.denominator == b.denominator)
  {
    result.numerator = a.numerator - b.numerator;
    result.denominator = a.denominator;
    return result;
  }
  float nok;
  nok = NOK(a.denominator, b.denominator);
  result.numerator = (nok / a.numerator) - (nok / b.numerator);
  result.denominator = nok;
  return result;
}

int main()
{
  float a1, a2, b1, b2;
  printf(" int numenator and int denominator a \n");
  scanf("%f%f", &a1, &a2);
  printf("int numenator and int denominator b \n");
  scanf("%f%f", &b1, &b2);
  
  fraction frc1 = {a1, a2};
  fraction frc2 = {b1, b2};
  fraction frcResult = substracFraction(frc1, frc2);
  printf("%.2f / %.2f", frcResult.numerator, frcResult.denominator);
}