#include "InferenceRulesEngine.h"

InferenceRulesEngine::InferenceRulesEngine(){}

InferenceRulesEngine::~InferenceRulesEngine(){}

int InferenceRulesEngine::InferenceEngine(RulesTree rules, Fact facts){
	int InferenceEngineReturn = 0;
    int i=0;
    int factsPosition=0;
	while(factsPosition<facts.facts.size()){
		for(int j=0;j<rules.rules.size();j++){
			if( facts.facts[i].factName == rules.rules[j].name){
				InferenceEngineReturn=rules.rules[j].ruleActions[rules.rules[j].evaluate(facts.facts[i])].execute(facts);
			}
		}
		i=InferenceEngineReturn;
		factsPosition++;
		if(i==0)break;
	}
	return (factsPosition*10+i);
};
