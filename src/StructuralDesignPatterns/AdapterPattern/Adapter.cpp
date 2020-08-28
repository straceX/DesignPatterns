#include "Adapter.h"

using namespace Toolkit;

auto MathsV1::divide(const double lhs, const double rhs)
  -> double
  {
  return lhs/rhs;
  }

auto MathsV2::divide(const double lhs, const double rhs)
  -> double
  {
    return rhs/lhs;
  }

auto Adapter::divide(const double lhs, const double rhs)
  -> double
  {
    return MathsV2::divide(rhs, lhs);
  }