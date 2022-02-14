/*  Copyright (c) 2022 Bernard Widynski
                                   
  This code can be used under the terms of the GNU General Public License
  as published by the Free Software Foundation, either version 3 of the
  License, or any later version. See the GPL license at URL
  http://www.gnu.org/licenses

Modified by Benson Muite in 2022 for use with TestU01

*/

#include <stdint.h>

static uint64_t ctr = 5342;
static uint64_t key = 521;

uint32_t squares32(void) {
  uint64_t x, y, z;
  y = x = ctr * ++key; z = y + key;
  x = x*x + y; x = (x>>32) | (x<<32);        /* round 1 */
  x = x*x + z; x = (x>>32) | (x<<32);        /* round 2 */
  x = x*x + y; x = (x>>32) | (x<<32);        /* round 3 */
  return (x*x + z) >> 32;                    /* round 4 */
}
