/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLexicalAnalyzer1Token
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLexicalAnalyzer1Token
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

#ifndef __I_ECO__LEXICAL_ANALYZER_1_TOKEN_H__
#define __I_ECO__LEXICAL_ANALYZER_1_TOKEN_H__

#include "IEcoBase1.h"

/* IEcoLexicalAnalyzer1Token IID = {56A98F9C-971E-489B-8079-D436A48AF8FC} */
#ifndef __IID_IEcoLexicalAnalyzer1Token
static const UGUID IID_IEcoLexicalAnalyzer1Token = {0x01, 0x10, {0x56, 0xA9, 0x8F, 0x9C, 0x97, 0x1E, 0x48, 0x9B, 0x80, 0x79, 0xD4, 0x36, 0xA4, 0x8A, 0xF8, 0xFC} };
#endif /* __IID_IEcoLexicalAnalyzer1Token */

typedef struct IEcoLexicalAnalyzer1Token* IEcoLexicalAnalyzer1TokenPtr_t;

typedef struct IEcoLexicalAnalyzer1TokenVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);

    /* IEcoLexicalAnalyzer1Token */
    int16_t (ECOCALLMETHOD *get_Type)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);        /* правило в грамматике */
    char_t* (ECOCALLMETHOD *get_Lexeme)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);      /* лексема */
    void (ECOCALLMETHOD *set_Tag)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me, /* in */ char_t* tag);
    char_t* (ECOCALLMETHOD *get_Tag)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);         /* пользовательские параметры, например для расскарашивания текста */
    char_t* (ECOCALLMETHOD *get_Description)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me); /* описание, из правил */
    uint32_t (ECOCALLMETHOD *get_Line)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);       /* информация о строке */
    uint32_t (ECOCALLMETHOD *get_Column)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);     /* информация о колонке */
    char_t* (ECOCALLMETHOD *get_Source)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);      /* имя файла, номер буфера */
    uint32_t (ECOCALLMETHOD *get_Position)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);   /* позиция в файле, смещение в буфере */
    uint16_t (ECOCALLMETHOD *get_Length)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);     /* длина лексемы */
    bool_t (ECOCALLMETHOD *IsEOF)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);            /* специальный токен - конец файла */
    bool_t (ECOCALLMETHOD *IsError)(/* in */ IEcoLexicalAnalyzer1TokenPtr_t me);          /* специальный токен - ошибка (состояние ловушки) */

} IEcoLexicalAnalyzer1TokenVTbl, *IEcoLexicalAnalyzer1TokenVTblPtr;

interface IEcoLexicalAnalyzer1Token {
    struct IEcoLexicalAnalyzer1TokenVTbl *pVTbl;
} IEcoLexicalAnalyzer1Token;

#endif /* __I_ECO__LEXICAL_ANALYZER_1_TOKEN_H__ */
