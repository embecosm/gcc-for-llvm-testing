/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */

void ldt_add_entry(void)
{
   __asm__ ("" :: "m"(({unsigned __v; __v;})));	/* { dg-warning "memory input 0 is not directly addressable" } */
}
