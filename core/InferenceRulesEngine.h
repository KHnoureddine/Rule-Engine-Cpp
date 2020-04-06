#ifndef INFERENCERULES_H_
#define INFERENCERULES_H_

#include "../api/RulesListener.h"


class InferenceRulesEngine{
	public:
	InferenceRulesEngine();
	~InferenceRulesEngine();
	void InferenceEngine(RulesTree rules, Fact facts);
};
#endif /* INFERENCERULES_H_ */
