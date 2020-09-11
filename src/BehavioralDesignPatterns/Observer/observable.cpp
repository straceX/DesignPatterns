#include "observable.h"

#include <iostream>

Observable::~Observable() 
  {
  std::cout << "Goodbye, I was the Observable.\n";
  }

auto Observable::Attach(IObserver *observer)
  -> void 
  {
  m_observerList.push_back(observer);
  }
  
auto Observable::Detach(IObserver *observer)
  -> void 
  {
  m_observerList.remove(observer);
  }

auto Observable::Notify()
  -> void
  {
  PrintObserverCount();
  for (auto observer : m_observerList) 
    observer->UpdateStatus(m_status);
  }

auto Observable::ChangeStatus(std::string status)
  -> void 
  {
  if(m_status == status)
    return;
  m_status = status;
  Notify();
  }

auto Observable::PrintObserverCount() const
  -> void 
  {
  std::cout<< "There are =" << m_observerList.size() << " observers in the list.\n";
  }

auto Observable::TriggeredEvent()
  -> void
  {
  m_status = "Tornado";
  Notify();
  }