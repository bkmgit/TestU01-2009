/* After compiling TESTU01 and adding the libraries to your paths,
 * compile this program with
 * cc -O3 speedsquares32.c squares32.c \
 *     -o speedsquares32 -ltestu01 -lprobdist -lmylib -lm
 * then run it using ./speedsquares32.c
 */

#include "unif01.h"
#include "ulec.h"

uint32_t squares32 (void);

int main (void)
{
	unif01_Gen *gen;

	gen = unif01_CreateExternGenBits("squares32", squares32);
	unif01_TimerSumGenWr (gen, 100000000, FALSE);
	ulec_DeleteGen (gen);

	return 0;
}
