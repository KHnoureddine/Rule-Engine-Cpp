#ifndef RULESLISTENER_H_
#define RULESLISTENER_H_

#include "RulesTree.h"

class RulesListener {
	public:
	RulesListener();
	~RulesListener();

 bool beforeEvaluate(RulesTree rules, Fact facts);
 bool afterEvaluate(RulesTree rules, Fact facts);
 bool beforeExecute(RulesTree rules, Fact facts);
 bool afterExecute(RulesTree rules, Fact facts);
 bool onSuccess(RulesTree rules, Fact facts);
 bool onFailure(RulesTree rules, Fact facts);
};
#endif /* RULESLISTENER_H_ */
