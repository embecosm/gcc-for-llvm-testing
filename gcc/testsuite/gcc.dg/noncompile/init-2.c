/* { dg-require-effective-target gcc_frontend } */
int d[][] = { {1}, {2}, {3} };	/* { dg-error "incomplete element type" } */
