#include "udf.h"

DEFINE_PROPERTY(PCM_Density, cell, thread) {
  real tempe2, r;
#if !RP_HOST
  tempe2 = C_T(cell, thread);
  if (tempe2 <= 295)
    r = 900;
  elseif((tempe2 > 295) && (tempe2 < 315)) {
    r = 900 - (36 * (temp2 - 295) / 2);
  }
  elseif(tempe2 >= 315) {
    r = 749 * (1 - .001 * (tempe2 - 315));
  }
#endif
  return r;
}

DEFINE_PROPERTY(PCM_Dynamicviscisity, cell, thread) {
  real tempe2, mu;
#if !RP_HOST
  tempe2 = C_T(cell, thread) : if (tempe2 <= 295)
                                   mu = 1;
  elseif((tempe2 > 295) && (tempe2 = < 315.5))
      mu = (315 - tempe) / 2;
  elseif((tempe2 > 315) && (tempe = < 315.5))
      mu = (315.5 - tempe2) / 2.07;
  elseif(tempe2 < 315.50)
      mu = 0.00016;
#endif
  return mu;
}

DEFINE_PROPERTY(PCM_Thermalconductivity, cell, thread) {
  real tempe2, k;
#if !RP_HOST
  tempe2 = C_T(cell, thread);
  if (tempe2 = < 295)
    k = 0.24;
if(tempe2>295&&(tempe2<315))
{
    k = 0.24 - (0.01 * (tempe2 - 295) / 2);
}
else
{
    k = 0.18;
}
#endif
return k;
}

DEFINE_SPECIFIC_HEAT(PCM_Specificheat, T, Tresf, h, yi) {
real cp, dnum;
#if !RP_HOST
if (T = < 295)
  cp = 2510;
if ((T > 295) && (T < 315)) {
  cp = 2510 + (600 * (T - 295) / 2);
} else {
  cp = 2950;
}
*h = cp;
#endif
return cp;
}