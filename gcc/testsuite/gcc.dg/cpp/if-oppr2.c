/* Copyright (C) 2008 Free Software Foundation, Inc.  */

/* Another test of operator precedence.  */

/* { dg-do preprocess } */
/* { dg-options "" } */
/* { dg-require-effective-target gcc_frontend } */

#if 1 ? 2 : 3 , 0
#error
#endif
