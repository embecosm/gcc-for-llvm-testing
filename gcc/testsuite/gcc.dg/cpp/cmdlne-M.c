/* Copyright (C) 2002 Free Software Foundation, Inc.  */

/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-M" } */

/* Test that dependency output suppresses warnings by implying -w.  */

#warning bogus /* { dg-bogus "warning" "warning not suppressed" } */
