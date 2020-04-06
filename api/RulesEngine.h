#ifndef RULESENGINE_H_
#define RULESENGINE_H_

#include "../core/InferenceRulesEngine.h"

class RulesEngine {
	public:
 RulesEngine();
~RulesEngine();
void fire(RulesTree rules, Fact facts);

};
#endif /* RULESENGINE_H_ */
