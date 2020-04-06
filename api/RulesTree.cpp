#include "RulesTree.h"

RulesTree::RulesTree(){
}
RulesTree::~RulesTree(){
}
void RulesTree::clearAll(){
	this->rules.clear();
}

bool RulesTree::exists(string name){
		bool existance = false;
		int i=0;
		while( ( i < rules.size() ) && ( existance == false ) )
		{
			if(rules[i].name  ==name)
				existance = true;
			i++;
		}
	return existance;
}

void RulesTree::clear(Rule rule){
	bool existance = false;
			int i=0;
			while( ( i < rules.size() ) && ( existance == false ) )
			{
				if(rules[i].name  == rule.name)
					{existance = true;
					rules.erase(rules.begin()+i);
					}
				i++;
			}
}

bool RulesTree::isEmpty(){
	return this->rules.empty();
}

int  RulesTree::registeRule(Rule rule){

	this->rules.push_back(rule);
	return (rules.size()-1);

}
