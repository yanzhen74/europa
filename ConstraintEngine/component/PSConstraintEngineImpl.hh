#ifndef _H_PSConstraintEngineImpl
#define _H_PSConstraintEngineImpl

#include "PSConstraintEngine.hh"
#include "ConstraintEngineDefs.hh"

namespace EUROPA {
    
  class PSVariableImpl : public PSVariable
  {
  public:
    virtual ~PSVariableImpl(){}
	    
    virtual const std::string& getEntityType() const;

    virtual PSVarType getType(); // Data Type 

    virtual bool isEnumerated();
    virtual bool isInterval();

    virtual bool isNull();      // iif CurrentDomain is empty and the variable hasn't been specified    
    virtual bool isSingleton();
		   
    virtual PSVarValue getSingletonValue();    // Call to get value if isSingleton()==true 
	
    virtual PSList<PSVarValue> getValues();  // if isSingleton()==false && isEnumerated() == true
	
    virtual double getLowerBound();  // if isSingleton()==false && isInterval() == true
    virtual double getUpperBound();  // if isSingleton()==false && isInterval() == true
	    
    virtual void specifyValue(PSVarValue& v);
    virtual void reset();
	
    virtual double getViolation() const;
    virtual std::string getViolationExpl() const;

    virtual PSEntity* getParent();
	    
    virtual std::string toString();
  protected:
    friend class PSEngineImpl;
    friend class PSObjectImpl;
    friend class PSTokenImpl;

    PSVariableImpl(const ConstrainedVariableId& var);
  private:
    ConstrainedVariableId m_var;
    PSVarType m_type;
  };   
  
}	

#endif 
