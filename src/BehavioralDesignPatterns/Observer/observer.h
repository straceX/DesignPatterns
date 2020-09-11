#pragma once

#include "iobserver.h"
#include "observable.h"

class Observer : public IObserver 
  {
  public:
    Observer(Observable &observable);
    virtual ~Observer();
    
    auto Detach()       -> void;
    auto Action() const -> void;
    auto Alert()  const -> void;

    //---IObserver---
    auto UpdateStatus(const std::string &newMesg) -> void override;

  private:
    std::string  m_statusInfoFromObservable;
    Observable  &m_observable;
    const int    m_id;
    static int   m_currentId;
  };