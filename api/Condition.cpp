#include"Condition.h"

Condition::Condition(string name,string conditionOp, int conditionValidator){
	this->conditionName=name;
	this->conditionOp=conditionOp;
	this->conditionValidator=conditionValidator;
}
Condition::Condition(){
}
Condition::~Condition(){
}
void Condition::addCondition(Condition condition){
	this->when.push_back(condition);
}



