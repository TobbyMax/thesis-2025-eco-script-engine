/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoOutputDiagnostic
 * </сводка>
 *
 * <описание>
 *   Данный файл описывает прототипы функций вывода диагностичекской/отладочной информации
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoFSM1.h"
#include "IEcoBNF1.h"
#include "IEcoParser1LRk.h"
#include "IEcoLexicalAnalyzer1Scanner.h"
#include "IEcoLog1.h"
#include "IEcoString1.h"
#include "IEcoMemoryAllocator1.h"
#include "IEcoAST1.h"


#define ECO_LANG_ASM    1
#define ECO_LANG_C89    2
#define ECO_LANG_OBJC   3
#define ECO_LANG_LUA    4

/* Прототипы функций */
bool_t OutputDiagnosticInfoOfFA(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoFSM1StateMachine* pIFA);
bool_t OutputDiagnosticInfoOfBNF(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoBNF1* pGrammar);
bool_t OutputDiagnosticInfoOfScanner(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoLexicalAnalyzer1Scanner* pIScanner);
bool_t OutputDiagnosticInfoOfScannerStep(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoLexicalAnalyzer1Token* pIToken);
bool_t OutputDiagnosticInfoOfParserStep(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoString1* pIStr, /* in */ IEcoParser1Action* pIAction);
bool_t OutputDiagnosticInfoOfLRk(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoMemoryAllocator1* pIMem, /* in */ IEcoString1* pIStr, /* in */ IEcoParser1LRk* pILRk);
bool_t OutputDiagnosticInfoOfAST(/* in */ uint16_t langId, /* in */ IEcoLog1* pILog, /* in */ IEcoMemoryAllocator1* pIMem, /* in */ IEcoString1* pIStr, /* in */ IEcoAST1* pIAST);
