#ifndef __AND_HPP__
#define __AND_HPP__

#include "Connector.hpp"

class And : public Connector {
	private:
		string leftLeaf;
		string rightLeaf;

	public:
		And(string left, string right) : Connector() { }
		
		virtual setLeftLeaf() {
			leftLeaf = left;
		}

		virtual setRightLeaf() {
			rightLeaf = right;
		}

		virtual int isLeftTrue() {
			Executor doLeft = Executor(leftLeaf);
		
		}
		
		virtual int isRightTrue() {
			
		}
#endif //__AND_HPP__
