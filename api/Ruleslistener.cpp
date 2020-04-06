#include "RulesListener.h"

RulesListener::RulesListener(){

}
RulesListener::~RulesListener(){

}
bool RulesListener::beforeEvaluate(RulesTree rules, Fact facts){
	bool beforeEva=false;

	if(!(rules.isEmpty())){

		for(int i=0;i<facts.facts.size();i++){
			beforeEva |= rules.exists(facts.facts[i].factName);
		}
	}
	return beforeEva;
}

bool RulesListener::afterEvaluate(RulesTree rules, Fact facts){
}

bool RulesListener::beforeExecute(RulesTree rules, Fact facts){

}

bool RulesListener::afterExecute(RulesTree rules, Fact facts){


}
bool RulesListener::onSuccess(RulesTree rules, Fact facts){
}
bool RulesListener::onFailure(RulesTree rules, Fact facts){

}
