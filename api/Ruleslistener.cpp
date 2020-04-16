#include "RulesListener.h"

RulesListener::RulesListener(){

}
RulesListener::~RulesListener(){

}

bool RulesListener::beforeEvaluate(RulesTree rules, Fact facts){
	bool beforeEva=false;

	if(! ( (rules.isEmpty()) || (facts.facts.empty()) ) ){
		beforeEva=true;
		for(int i=0;i<facts.facts.size();i++){
			beforeEva &= rules.exists(facts.facts[i].factName);
		}
	}
	return beforeEva;
}

Fact RulesListener::afterEvaluate(RulesTree rules, Fact facts){
	Fact factsBox;
	Fact factNothing("nothing", 0);

	for(int i=0;i<facts.facts.size();i++){
		factsBox.addFact(factNothing);
	}
	for(int i=0;i<facts.facts.size();i++){
		factsBox.facts[i]=facts.facts[i];
	}
	for(int i=0;i<facts.facts.size();i++){
		for(int j=0;j<rules.rules.size();j++){
			if(factsBox.facts[i].factName == rules.rules[j].name){
                	facts.facts[rules.rules[j].priority]=factsBox.facts[i];
                }
			}
		}

    return facts;
}

int RulesListener::afterExecute(RulesTree rules, Fact facts,int codeRes){
	int afterExecuteReturn=1;
	int numFact=0;
	int lastFact=0;
	numFact=codeRes/10;
	lastFact=codeRes %10;

	if(numFact==rules.rules.size()){
		if(lastFact==0){
			afterExecuteReturn=1;
			cout<<"execute all Rules with success"<<endl;
		}
	}
	else if(numFact<rules.rules.size()){
		if(lastFact==0){
			afterExecuteReturn=1;
			cout<<"execute "<<numFact<<" Rules with success"<<endl;
		}
	}
	else {
		if(lastFact!=0){
			afterExecuteReturn=0;
			cout<<"Problem in rule "<<lastFact<<endl;
		}
	}
	return afterExecuteReturn;
}
