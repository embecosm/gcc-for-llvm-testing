/* { dg-require-effective-target gcc_frontend } */
struct s{struct s{int i;}x;};	/* { dg-error "nested redefinition" } */
