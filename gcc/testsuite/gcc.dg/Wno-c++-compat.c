/* Copyright (C) 2005  Free Software Foundation.

   by Gabriel Dos Reis  <gdr@integrable-solutions.net>  */

/* { dg-do compile }  */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-Wno-c++-compat" } */

extern const int foo = 42;      /* { dg-warning "initialized and declared" } */

