#include "../include/utils/interval.h"

const interval interval::empty = interval(INF, -1 * INF);

const interval interval::universe = interval(-1 * INF, INF);