// { dg-do compile }
/* { dg-require-effective-target gcc_frontend } */
// { dg-options "-Wstrict-aliasing=2 -fstrict-aliasing" }

struct s {
  char    *p;
};

void
func(struct s *ptr)
{
  *(void **)&ptr->p = 0; /* { dg-warning "type-punned pointer" } */
}
