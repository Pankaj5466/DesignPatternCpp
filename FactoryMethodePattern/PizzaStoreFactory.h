//This is PizzaStore using Factory Desing Pattern
#pragma once
#include "PizzaStore.h"
#include "ConcretePizzaClass.h"

/*
Factory Methode Defination:
Factory mehtode defines an inteface(PizzaStore) for creating an object, but lets subclasses(NYPizzaStore,ChicagoPizzaStore..etc) decide
which class to instantiate.
Factory methode lets a class defer instantiation to subclass
*/

//OrderPizza mehtode is superclass has no clue as which pizza we are creating; it just
//knows it can prepare ,bake ,cut and Box it!
//Above is the target of Factory Design Pattern (Decouple object creation)

class NYPizzaStore : public PizzaStore
{
	virtual Pizza* createPizza(string type) override //Implement the abstract methode
	{
		Pizza* p = nullptr;

		if (type._Equal("cheese"))
			p = new NYStyleCheesePizza();
		else if (type._Equal("pepperoni"))
			p = nullptr; // new PepperoniPizza();

		return p;
	}
};

//NOTE: Can be impleted in seperate Header file
class ChicagoStylePizzaStore :public PizzaStore
{
	virtual Pizza* createPizza(string type) override //Implement the abstract methode
	{
		Pizza* p = nullptr;

		if (type._Equal("cheese"))
			p = new ChicagoStyleCheesePizza();
		else if (type._Equal("pepperoni"))
			p = nullptr; // new PepperoniPizza();

		return p;
	}
};
