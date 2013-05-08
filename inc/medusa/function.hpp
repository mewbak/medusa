#ifndef _MEDUSA_FUNCTION_
#define _MEDUSA_FUNCTION_

#include <list>

#include "medusa/namespace.hpp"
#include "medusa/multicell.hpp"
#include "medusa/control_flow_graph.hpp"

MEDUSA_NAMESPACE_BEGIN

//! Function is a MultiCell which handles a function.
class Function : public MultiCell
{
public:
  typedef std::list<Function> List;

  Function(u16 Size, u16 InsnCnt, ControlFlowGraph const& rCfg)
    : MultiCell(MultiCell::FunctionType, Size)
    , m_InsnCnt(InsnCnt)
    , m_ParamCnt()
    , m_Cfg(rCfg)
  {}

  //! This method returns the number of instruction.
  u16 GetInstructionCounter(void) const { return m_InsnCnt; }
  u8 GetParameterCounter(void) const { return m_ParamCnt; }
  ControlFlowGraph const& GetControlFlowGraph(void) const { return m_Cfg; }

  void SetParameterCounter(u8 ParamCnt) { m_ParamCnt = ParamCnt; }

  virtual bool DisplayCell(void) const { return true; }

  bool Contains(Address const& rAddress) const;

private:
  u16              m_InsnCnt;
  u8               m_ParamCnt;
  ControlFlowGraph m_Cfg;
};

MEDUSA_NAMESPACE_END

#endif // !_MEDUSA_FUNCTION_