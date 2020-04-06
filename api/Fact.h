#ifndef FACT_H_
#define FACT_H_

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Fact {
public:
string factName;
int factValue;
vector <Fact> facts;

Fact();
Fact(string factName,int factValue);
void addFact(Fact fact);
~Fact();
};



#endif /* FACT_H_ */
