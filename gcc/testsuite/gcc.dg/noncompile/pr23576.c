/* { dg-require-effective-target gcc_frontend } */
struct ipr_path_entry path[0]; /* { dg-error "array type has incomplete element type" } */
