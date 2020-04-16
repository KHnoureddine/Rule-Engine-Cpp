#include"RulesEngine.h"

RulesEngine::RulesEngine(){

}

RulesEngine::~RulesEngine(){

}


int RulesEngine::fire(RulesTree rules, Fact facts){

	RulesListener rulesListener;
	InferenceRulesEngine inferenceRulesEngine;
	int res=0;

	if(rulesListener.beforeEvaluate(rules, facts)){
		Fact factsNew;
		factsNew=rulesListener.afterEvaluate(rules, facts);
		res=inferenceRulesEngine.InferenceEngine(rules, factsNew);
		rulesListener.afterExecute(rules, factsNew,res);

	}


}
