#ifndef __AND_HPP__
#define __AND_HPP__

#include "Connector.hpp"
#include "Parser.hpp"
#include "Executor.hpp"

class And : public Connector {
	private:
		std::string leftLeaf;
		std::string rightLeaf;

	public:
		And(std::string left, std::string right) : Connector() {
			leftLeaf = left;
			rightLeaf = right;

		}
		
		//virtual setLeftLeaf(std::string left);

		//virtual setRightLeaf(std::string right);

		virtual int isLeftTrue() {
			Executor toCheck = Executor();
			return toCheck.execute(leftLeaf);
		};
		
		virtual int isRightTrue(){
			Executor toCheck = Executor();
			return toCheck.execute(rightLeaf);
		};
};
#endif //__AND_HPP__
