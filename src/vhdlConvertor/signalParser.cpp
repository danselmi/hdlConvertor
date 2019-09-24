#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::vector<HdlVariableDef*> * VhdlSignalParser::visitSignal_declaration(
		vhdlParser::Signal_declarationContext* ctx) {
	//signal_declaration
	//	: SIGNAL identifier_list COLON
	//	subtype_indication ( signal_kind )? ( VARASGN expression )? SEMI
	//	;
	return VhdlInterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
}

}
}
