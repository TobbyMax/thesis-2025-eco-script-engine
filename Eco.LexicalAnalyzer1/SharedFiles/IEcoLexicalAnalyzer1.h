/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLexicalAnalyzer1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLexicalAnalyzer1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO__LEXICAL_ANALYZER_1_H__
#define __I_ECO__LEXICAL_ANALYZER_1_H__

#include "IEcoBase1.h"
#include "IEcoRL1.h"
#include "IEcoBNF1.h"
#include "IEcoLexicalAnalyzer1Token.h"
#include "IEcoLexicalAnalyzer1Scanner.h"

/* IEcoLexicalAnalyzer1 IID = {DFB72921-A0FF-4F1D-93C7-F321AEB315E4} */
#ifndef __IID_IEcoLexicalAnalyzer1
static const UGUID IID_IEcoLexicalAnalyzer1 = {0x01, 0x10, {0xDF, 0xB7, 0x29, 0x21, 0xA0, 0xFF, 0x4F, 0x1D, 0x93, 0xC7, 0xF3, 0x21, 0xAE, 0xB3, 0x15, 0xE4} };
#endif /* __IID_IEcoLexicalAnalyzer1 */

typedef struct IEcoLexicalAnalyzer1* IEcoLexicalAnalyzer1Ptr_t;

typedef struct IEcoLexicalAnalyzer1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoLexicalAnalyzer1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoLexicalAnalyzer1Ptr_t me);

    /* IEcoLexicalAnalyzer1 */
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_FileScannerByFA)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoFSM1StateMachinePtr_t pIFA, /* in */ char_t* fileName);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_MemoryScannerByFA)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoFSM1StateMachinePtr_t pIFA, /* in */ char_t* buffer, /* in */ int32_t size);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_FileScannerByRG)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoRL1GrammarPtr_t pIGrammar, /* in */ char_t* fileName);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_MemoryScannerByRG)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoRL1GrammarPtr_t pIGrammar, /* in */ char_t* buffer, /* in */ int32_t size);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_FileScannerByRE)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoRL1ExpressionPtr_t pIExpression, /* in */ char_t* fileName);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_MemoryScannerByRE)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoRL1ExpressionPtr_t pIExpression, /* in */ char_t* buffer, /* in */ int32_t size);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_FileScannerByBNF)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoBNF1Ptr_t pIGrammar, /* in */ char_t* fileName);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_MemoryScannerByBNF)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ IEcoBNF1Ptr_t pIGrammar, /* in */ char_t* buffer, /* in */ int32_t size);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_FileScannerByDirectImpl)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ ECO_FUNC_RECOGNITION_INDIVIDUAL_TOKEN func, /* in */ char_t* fileName);
    IEcoLexicalAnalyzer1ScannerPtr_t (ECOCALLMETHOD *new_MemoryScannerByDirectImpl)(/* in */ IEcoLexicalAnalyzer1Ptr_t me, /* in */ ECO_FUNC_RECOGNITION_INDIVIDUAL_TOKEN func, /* in */ char_t* buffer, /* in */ int32_t size);


} IEcoLexicalAnalyzer1VTbl, *IEcoLexicalAnalyzer1VTblPtr;

interface IEcoLexicalAnalyzer1 {
    struct IEcoLexicalAnalyzer1VTbl *pVTbl;
} IEcoLexicalAnalyzer1;

#endif /* __I_ECO__LEXICAL_ANALYZER_1_H__ */
