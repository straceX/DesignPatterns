#pragma once

struct IObserver;

struct IObservable 
	{
	virtual ~IObservable() = default;
	/*The subscription management methods.*/
  	virtual auto Attach(IObserver *observer) -> void = 0;
  	virtual auto Detach(IObserver *observer) -> void = 0;
  	virtual auto Notify() 					 -> void = 0;
  	};
