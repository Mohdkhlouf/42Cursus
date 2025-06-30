#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream>

class Sample{
public:

	int x;
	int const pi;
	
	Sample(void);
	~Sample(void);

	void print(void);
};

#endif