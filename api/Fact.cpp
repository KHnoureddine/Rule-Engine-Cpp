#include"Fact.h"

Fact::Fact(){}
Fact::~Fact(){}

Fact::Fact(string factName,int factValue){
	this->factName=factName;
	this->factValue=factValue;
}
void Fact::addFact(Fact fact){
	this->facts.push_back(fact);
}

