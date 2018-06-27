/* { dg-options "-ffat-lto-objects" } */
/* { dg-require-effective-target gcc_internals } */
void
asm_invalid_register_name()
{
  asm("":::"this_is_an_invalid_register_name");	/* { dg-error "unknown register" } */
}
