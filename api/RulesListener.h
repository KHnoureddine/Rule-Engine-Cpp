#ifndef RULESLISTENER_H_
#define RULESLISTENER_H_

#include "RulesTree.h"

class RulesListener {
	public:
	RulesListener();
	~RulesListener();

 bool beforeEvaluate(RulesTree rules, Fact facts);
 Fact afterEvaluate(RulesTree rules, Fact facts);
 int  afterExecute(RulesTree rules, Fact facts,int codeRes);
};
#endif /* RULESLISTENER_H_ */
