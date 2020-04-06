#include"RulesEngine.h"

RulesEngine::RulesEngine(){

}
RulesEngine::~RulesEngine(){

}


void RulesEngine::fire(RulesTree rules, Fact facts){
	InferenceRulesEngine inferenceRulesEngine;
	RulesListener rulesListener;

	rulesListener.beforeExecute(rules, facts);

	if(rulesListener.beforeEvaluate(rules, facts)){
		inferenceRulesEngine.InferenceEngine(rules, facts);
	}


}
