#include <stdio.h>
#include <limits.h>

int main() {

  printf("char: size = %zu Bytes. \n", sizeof(char));
  printf("short: size = %zu Bytes. Range = %d .. %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
  printf("int: size = %zu Bytes. Range = %d .. %d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("unsigned int: size = %zu Bytes. Range = %d .. %d\n", sizeof(unsigned int), INT_MIN, INT_MAX);
  printf("unsigned long: size = %zu Bytes. Range = 0 .. %ul\n", sizeof(unsigned long),  UINT_MAX);
  printf("unsigned long long: size = %zu Bytes. Range = 0 .. %llu\n", sizeof(unsigned long long), ULLONG_MAX);
  printf("long long: size = %zu Bytes. Range = %lld .. %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
  printf("float: size = %zu Bytes. \n", sizeof(float));
  printf("double: size = %zu Bytes.\n", sizeof(double));
 
  // completar

  
  return 0;
}
