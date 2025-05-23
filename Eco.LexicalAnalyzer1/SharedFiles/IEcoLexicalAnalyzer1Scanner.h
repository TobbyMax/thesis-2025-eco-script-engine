/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLexicalAnalyzer1Scanner
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLexicalAnalyzer1Scanner
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

#ifndef __I_ECO__LEXICAL_ANALYZER_1_SCANNER_H__
#define __I_ECO__LEXICAL_ANALYZER_1_SCANNER_H__

#include "IEcoBase1.h"
#include "IEcoFSM1.h"
#include "IEcoLexicalAnalyzer1Token.h"

#define ECO_LEXICAL_ANALYZER_RECOGNITION_FLAG_NEXT      0x00
#define ECO_LEXICAL_ANALYZER_RECOGNITION_FLAG_TOKEN     0x01
#define ECO_LEXICAL_ANALYZER_RECOGNITION_FLAG_SKIP      0x02
#define ECO_LEXICAL_ANALYZER_RECOGNITION_FLAG_CLEAN     0x04

/* Определение прототипов получение комонентов */
typedef int16_t (ECOCALLMETHOD *ECO_FUNC_RECOGNITION_INDIVIDUAL_TOKEN)(/* in */ uchar_t Symbol,
                                                                       /* in */ char_t* Lexem,
                                                                       /* in */ uint32_t Line,
                                                                       /* in */ uint32_t Column,
                                                                       /* in */ char_t* Source,
                                                                       /* in */ uint32_t Position,
                                                                       /* in */ uint32_t Length,
                                                                       /* out */ int32_t* Type,
                                                                       /* in | out */ char_t** Description,
                                                                       /* out */ uint16_t* Flag);

/* IEcoLexicalAnalyzer1Scanner IID = {32A56CF5-8AFB-4A14-8950-5DEE73324D5A} */
#ifndef __IID_IEcoLexicalAnalyzer1Scanner
static const UGUID IID_IEcoLexicalAnalyzer1Scanner = {0x01, 0x10, {0x32, 0xA5, 0x6C, 0xF5, 0x8A, 0xFB, 0x4A, 0x14, 0x89, 0x50, 0x5D, 0xEE, 0x73, 0x32, 0x4D, 0x5A} };
#endif /* __IID_IEcoLexicalAnalyzer1Scanner */

typedef struct IEcoLexicalAnalyzer1Scanner* IEcoLexicalAnalyzer1ScannerPtr_t;

typedef struct IEcoLexicalAnalyzer1ScannerVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me);

    /* IEcoLexicalAnalyzer1Scanner */
    IEcoFSM1StateMachine* (ECOCALLMETHOD *get_FSM)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me);
    IEcoLexicalAnalyzer1Token* (ECOCALLMETHOD *Scan)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me);
    int16_t (ECOCALLMETHOD *Recover)(/* in */ IEcoLexicalAnalyzer1ScannerPtr_t me, /* in */ IEcoLexicalAnalyzer1Token* pIToken);

} IEcoLexicalAnalyzer1ScannerVTbl, *IEcoLexicalAnalyzer1ScannerVTblPtr;

interface IEcoLexicalAnalyzer1Scanner {
    struct IEcoLexicalAnalyzer1ScannerVTbl *pVTbl;
} IEcoLexicalAnalyzer1Scanner;


/* IEcoLexicalAnalyzer1Events IID = {A5278D51-F9BC-4255-9E06-7CC2166A0FB9} */
#ifndef __IID_IEcoLexicalAnalyzer1Events
static const UGUID IID_IEcoLexicalAnalyzer1Events = {0x01, 0x10, {0xA5, 0x27, 0x8D, 0x51, 0xF9, 0xBC, 0x42, 0x55, 0x9E, 0x06, 0x7C, 0xC2, 0x16, 0x6A, 0x0F, 0xB9} };
#endif /* __IID_IEcoLexicalAnalyzer1Events */

typedef struct IEcoLexicalAnalyzer1Events* IEcoLexicalAnalyzer1EventsPtr_t;

typedef struct IEcoLexicalAnalyzer1EventsVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me);

    /* IEcoLexicalAnalyzer1Events */
    void (ECOCALLMETHOD *OnInfoMessage)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me, /* in */ char_t* messsage);
    void (ECOCALLMETHOD *OnProcessing)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me, /* in */ IEcoFSM1State* pISourceState, /* in */ uchar_t eventSymbol, /* in */IEcoFSM1State* pITargeState);
    void (ECOCALLMETHOD *OnToken)(/* in */ IEcoLexicalAnalyzer1EventsPtr_t me, /* in */ IEcoLexicalAnalyzer1Token* pIToken);

} IEcoLexicalAnalyzer1EventsVTbl, *IEcoLexicalAnalyzer1EventsVTblPtr;

interface IEcoLexicalAnalyzer1Events {
    struct IEcoLexicalAnalyzer1EventsVTbl *pVTbl;
} IEcoLexicalAnalyzer1Events;

#endif /* __I_ECO__LEXICAL_ANALYZER_1_SCANNER_H__ */
