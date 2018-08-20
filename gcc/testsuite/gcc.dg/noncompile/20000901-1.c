/* { dg-require-effective-target gcc_frontend } */
struct foo bar[] = { {"baz"} }; /* { dg-error "array type has incomplete element type" } */
