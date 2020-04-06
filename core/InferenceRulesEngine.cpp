#include "InferenceRulesEngine.h"

InferenceRulesEngine::InferenceRulesEngine(){}

InferenceRulesEngine::~InferenceRulesEngine(){}

void InferenceRulesEngine::InferenceEngine(RulesTree rules, Fact facts){

	for(int i=0;i<facts.facts.size();i++){

		for(int j=0;j<rules.rules.size();j++){

			if( facts.facts[i].factName == rules.rules[j].name){

//				cout<<"I find it "<<rules.rules[j].name<<" "<<j<<" "<<facts.facts[i].factName<<" "<<i<<" "<<endl;
//				cout<<rules.rules[j].evaluate(facts.facts[i])<<endl;
				rules.rules[j].ruleActions[rules.rules[j].evaluate(facts.facts[i])].execute(facts);

			}
		}


	}
};
