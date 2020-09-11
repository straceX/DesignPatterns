#pragma once

#include "iobservable.h"
#include "iobserver.h"

#include <string>
#include <list>

/*The Observable notifies observers when the state changes.*/
class Observable : public IObservable
  {
  public:
    Observable() = default;
    virtual ~Observable();

    auto ChangeStatus(std::string status) -> void;
    auto PrintObserverCount() const       -> void;
    auto TriggeredEvent()                 -> void;

    //---IObservable---
    auto Attach(IObserver *observer) -> void override;
    auto Detach(IObserver *observer) -> void override;
    auto Notify()                    -> void override;

  private:
    std::list<IObserver *> m_observerList;
    std::string            m_status;
  };