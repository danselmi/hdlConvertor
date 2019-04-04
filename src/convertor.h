#pragma once

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <unistd.h>

#include "hdlObjects/context.h"

#include "vhdlConvertor/vhdlParser/vhdlLexer.h"
#include "vhdlConvertor/vhdlParser/vhdlParser.h"
#include "vhdlConvertor/designFileParser.h"

#include "verilogConvertor/Verilog2001Parser/Verilog2001Lexer.h"
#include "verilogConvertor/Verilog2001Parser/Verilog2001Parser.h"
#include "verilogConvertor/source_textParser.h"

#define SV_PARSER

#ifdef SV_PARSER
#include "svConverter/sv2012Parser/sv2012Lexer.h"
#include "svConverter/sv2012Parser/sv2012Parser.h"
#include "svConverter/source_textParser.h"
#endif

#include "verilogPreproc/vPreprocessor.h"

#include "exception.h"
#include "syntaxErrorLogger.h"
#include "langue.h"
#include "parserContainer.h"

class Convertor {

public:
	std::string fileName;
	Langue lang;
	bool hierarchyOnly;
	static bool debug;

	Context * parse(
			std::vector<std::string> fileNames,
			Langue lang,
			std::vector<std::string>,
			bool hierarchyOnly,
			bool debug);

	std::string verilog_pp(const std::string, std::vector<std::string> incdir, unsigned int mode );

};
