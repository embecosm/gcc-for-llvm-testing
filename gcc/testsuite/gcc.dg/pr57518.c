/* PR rtl-optimization/57518 */

/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ira" } */
/* { dg-require-effective-target gcc_internals } */

char ip[10];
int total;

void foo() {
  int t;

  t = ip[2];
  total = t & 0x3;
}

/* { dg-final { scan-rtl-dump-not "REG_EQUIV\[^\n\]*mem\[^\n\]*\"ip\".*subreg" "ira" } } */
