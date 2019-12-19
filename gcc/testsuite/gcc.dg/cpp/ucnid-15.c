/* Verify macro definitions with UCNs in argument names are output in
   -dD output with the original spelling.  */
/* { dg-do preprocess } */
/* { dg-options "-std=c99 -dD" } */
#define a(\u00c1) x:\u00C1:y:\u00c1:z
/* { dg-final { scan-file ucnid-15.i "#define a\\((\\\\u00c1\\|Á))x:(\\\\u00C1:|Á)y:(\\\\u00c1|Á):z" } } */
