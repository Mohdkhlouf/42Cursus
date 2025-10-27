#include "Dummy.hpp"

Dummy::Dummy():ATarget("Dummy"){}

ATarget *Dummy::clone() const{
	return (new Dummy);
};
