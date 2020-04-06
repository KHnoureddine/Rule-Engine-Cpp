#ifndef RULESTREE_H_
#define RULESTREE_H_

#include <stdlib.h>
#include <string>
#include "Rule.h"
using namespace std;

class RulesTree {
	public:
	RulesTree();
    ~RulesTree();
    vector <Rule> rules;

	bool exists(string name);
	bool isEmpty();
	int  registeRule(Rule rule);
	void clear(Rule rule);
	void clearAll();
};
#endif /* RULESTREE_H_ */
