#include "Rule.h"

Rule::Rule(){}
Rule::Rule(string name,string description, int priority,vector <Condition> ruleConditions,vector <Action> ruleActions){
	this->name=name;
	this->description=description;
	this->priority=priority;
	this->ruleConditions= ruleConditions;
	this->ruleActions= ruleActions;

}

Rule::~Rule(){

}

int Rule::evaluate(Fact fact){
	int j=0;
	int evalValue=0;
	while (j < ruleConditions.size()){
		evalValue+=ruleConditions[j].validator(fact.factValue);
		j++;
	}
	if(evalValue>2){
		evalValue=3;
	}

	return evalValue;
}
