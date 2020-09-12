#include "observable.h"
#include "observer.h"

auto driverFunction()
  -> void
  {
  auto observable = new Observable;

  auto observer1 = new Observer(*observable);
  auto observer2 = new Observer(*observable);

  observable->ChangeStatus("The weather is sunny now!");
  observer2->Detach();

  observable->ChangeStatus("The weather is cloudy now!");
  auto observer3 = new Observer(*observable);

  observer1->Detach();
  auto observer4 = new Observer(*observable);

  observable->ChangeStatus("The weather is rainy now!");
  observable->ChangeStatus("The weather is rainy now!");
  observable->TriggeredEvent();
  observer4->Detach();  
  observer3->Detach();

  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete observable;
  }

auto main()
	-> int 
	{
  driverFunction();
  return 0;
	}