#include "observer.h"

#include <iostream>

int Observer::m_currentId = 0;

Observer::Observer(Observable &observable) 
  : m_observable(observable)
  , m_id{++Observer::m_currentId}
  {
  m_observable.Attach(this);
  std::cout<< "New observer(" << m_id << ") is created.\n";
  }

Observer::~Observer() 
  {
  std::cout<< "Observer(" << m_id << ") is destructed.\n";
  }

auto Observer::Detach()
  -> void
  {
  m_observable.Detach(this);
  std::cout<< "Observer(" << m_id << ") is detached.\n";
  }

auto Observer::Action() const
  -> void
  {
  std::cout<< "Observer(" << m_id << ") : wheater is updated : " << m_statusInfoFromObservable << "\n";
  }

auto Observer::Alert() const
  -> void
  {
  std::cout<< "Tornado is coming!..\n";
  }

//---IObserver---
auto Observer::UpdateStatus(const std::string &newMesg)
  -> void
  {
  m_statusInfoFromObservable = newMesg;
  if (m_statusInfoFromObservable == "Tornado")
    {
    Alert();
    return;
    }
  Action();
  }