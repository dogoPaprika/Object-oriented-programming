#pragma once
#pragma once
class Observer
{
public:
	virtual void update() = 0;
	Observer() {};
	virtual ~Observer() {};
};