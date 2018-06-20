/* Copyright (C) 2000 Free Software Foundation, Inc.  */

/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */

/* Test shift operators.  */

#if 1 << 4 != 16
#error		/* { dg-bogus "error" "<< +ve shift" } */
#endif

#if 19 >> 2 != 4
#error		/* { dg-bogus "error" ">> +ve shift" } */
#endif

#if 17 << -2 != 17 >> 2
#error		/* { dg-bogus "error" "<< -ve shift" } */
#endif

#if 25 >> -2 != 25 << 2
#error		/* { dg-bogus "error" ">> -ve shift" } */
#endif

