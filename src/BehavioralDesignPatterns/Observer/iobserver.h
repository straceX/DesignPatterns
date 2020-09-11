#pragma once

#include <string>

struct IObserver 
  {
  virtual ~IObserver() = default;
  virtual void UpdateStatus(const std::string &newMesg) = 0;
  };