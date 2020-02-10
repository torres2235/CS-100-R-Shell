#ifndef __AND_HPP__
#define __AND_HPP__

#include "Connector.hpp"

class And : public Connector {
	private:
		Connector* leftLeaf;
		Connector* rightLeaf;

	public:
		And(Connector* left, Connector* right) : Connector() {
			leftLeaf = left;
			rightLeaf = right;
		}
		
		virtual bool isLeftTrue() {
		
		}

		virtual bool isRightTrue() {

		}
#endif //__AND_HPP__
