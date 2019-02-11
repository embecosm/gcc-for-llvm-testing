/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target gcc_frontend } */

struct s { _Complex float i; };
void g(struct s *);

float a1 (float dd)
{
  struct s sv;
  sv.i = dd;
  float d = __real__ sv.i;
  g(&sv);
  return d;
}

/* { dg-final { scan-tree-dump "Replaced REALPART_EXPR.*with dd" "fre1" } } */
