#ifndef CONDITION_H_
#define CONDITION_H_
#include"Fact.h"

class Condition {
	public:
	string conditionName;
	string conditionOp;
	int conditionValidator;
	vector <Condition> when;

	Condition();
	~Condition();
    Condition(string conditionName,string conditionOp, int conditionValidator);
	void addCondition(Condition condition);

	function <int(int)> validator=[this](int factVal){
		int what=0;//neither

		if(conditionOp=="greater"){
			if (conditionValidator < factVal )
				what=1;
		}
		else if(conditionOp=="less"){
			if (conditionValidator > factVal )
				what=2;
		}
		else if(conditionOp=="equal"){
			if (conditionValidator == factVal )
				what=3;
		}
		return what;
	};

};

#endif /* CONDITION_H_ */
