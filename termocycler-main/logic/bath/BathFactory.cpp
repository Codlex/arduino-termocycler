#ifndef BATH_FACTORY_H
#define BATH_FACTORY_H


#include "cold/ColdBath.cpp"
#include "hot/HotBath.cpp"


class BathFactory {
public:
	static HotBath* createHot() {
		return new HotBath();
	}

	static ColdBath* createCold() {
		return new ColdBath();
	}

};

#endif
