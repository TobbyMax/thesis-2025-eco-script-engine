/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoFL1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoFL1
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

#ifndef __I_ECO_FORMAL_LANGUAGE_1_H__
#define __I_ECO_FORMAL_LANGUAGE_1_H__

#include "IEcoBase1.h"
#include "IEcoList1.h"
#include "IEcoFSM1State.h"

/* IEcoFL1SymbolSet IID = {F7C67779-CC53-4119-9D29-DF94B3858D54} */
#ifndef __IID_IEcoFL1SymbolSet
static const UGUID IID_IEcoFL1SymbolSet = {0x01, 0x10, {0xF7, 0xC6, 0x77, 0x79, 0xCC, 0x53, 0x41, 0x19, 0x9D, 0x29, 0xDF, 0x94, 0xB3, 0x85, 0x8D, 0x54} };
#endif /* __IID_IEcoFL1SymbolSet */

typedef struct IEcoFL1SymbolSet* IEcoFL1SymbolSetPtr_t;

typedef struct IEcoFL1SymbolSetVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFL1SymbolSetPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFL1SymbolSetPtr_t me);

    /* IEcoFL1SymbolSet */
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFL1SymbolSetPtr_t me);
    int16_t (ECOCALLMETHOD *get_Id)(/* in */ IEcoFL1SymbolSetPtr_t me);
    uint32_t (ECOCALLMETHOD *get_Count)(/* in */ IEcoFL1SymbolSetPtr_t me);
    uint8_t (ECOCALLMETHOD *get_Length)(/* in */ IEcoFL1SymbolSetPtr_t me);
    void (ECOCALLMETHOD *set_Length)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint8_t value);
    uint8_t (ECOCALLMETHOD *get_Align)(/* in */ IEcoFL1SymbolSetPtr_t me);
    void (ECOCALLMETHOD *set_Align)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint8_t value);
    bool_t (ECOCALLMETHOD *IsComplement)(/* in */ IEcoFL1SymbolSetPtr_t me);
    void (ECOCALLMETHOD *set_Complement)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ bool_t value);
    bool_t (ECOCALLMETHOD *IsTerminal)(/* in */ IEcoFL1SymbolSetPtr_t me);
    void (ECOCALLMETHOD *set_Terminal)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ bool_t value);
    bool_t (ECOCALLMETHOD *IsEmpty)(/* in */ IEcoFL1SymbolSetPtr_t me);
    bool_t (ECOCALLMETHOD *IsWord)(/* in */ IEcoFL1SymbolSetPtr_t me);
    bool_t (ECOCALLMETHOD *IsRange)(/* in */ IEcoFL1SymbolSetPtr_t me);
    bool_t (ECOCALLMETHOD *IsExist)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits); 
    int16_t (ECOCALLMETHOD *AddSymbol)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits, /* out */ uint32_t* index);
    int16_t (ECOCALLMETHOD *get_Symbol)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t index, /* out */ byte_t** Symbol, /* out */ uint8_t* offsetBits);
    int16_t (ECOCALLMETHOD *AddSymbolRange)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t start, /* in */ uint32_t end, /* out */ uint32_t* index);
    int16_t (ECOCALLMETHOD *get_SymbolRange)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t index, /* out */ uint32_t* start, /* out */ uint32_t* end);
    int16_t (ECOCALLMETHOD *set_Word)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* word, /* in */ uint8_t length);
    int16_t (ECOCALLMETHOD *get_Word)(/* in */ IEcoFL1SymbolSetPtr_t me, /* out */ byte_t** word, /* out */ uint8_t* length);
    void (ECOCALLMETHOD *set_WordState)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ IEcoFSM1State* state);
    IEcoFSM1State* (ECOCALLMETHOD *get_WordState)(/* in */ IEcoFL1SymbolSetPtr_t me);
    void (ECOCALLMETHOD *set_WordFailedState)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ IEcoFSM1State* state);
    IEcoFSM1State* (ECOCALLMETHOD *get_WordFailedState)(/* in */ IEcoFL1SymbolSetPtr_t me);
    IEcoFSM1State* (ECOCALLMETHOD *InvokeBySymbol)(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits);
    bool_t (ECOCALLMETHOD *IsFinished)(/* in */ IEcoFL1SymbolSetPtr_t me);

} IEcoFL1SymbolSetVTbl, *IEcoFL1SymbolSetVTblPtr;

interface IEcoFL1SymbolSet {
    struct IEcoFL1SymbolSetVTbl *pVTbl;
} IEcoFL1SymbolSet;


/* IEcoFL1Alphabet IID = {34832ECF-CA8E-4B16-93F0-C735F0CA9F8D} */
#ifndef __IID_IEcoFL1Alphabet
static const UGUID IID_IEcoFL1Alphabet = {0x01, 0x10, {0x34, 0x83, 0x2E, 0xCF, 0xCA, 0x8E, 0x4B, 0x16, 0x93, 0xF0, 0xC7, 0x35, 0xF0, 0xCA, 0x9F, 0x8D} };
#endif /* __IID_IEcoFL1Alphabet */

typedef struct IEcoFL1Alphabet* IEcoFL1AlphabetPtr_t;

typedef struct IEcoFL1AlphabetVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoFL1AlphabetPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoFL1AlphabetPtr_t me);

    /* IEcoFL1Alphabet */
    char_t* (ECOCALLMETHOD *get_Name)(/* in */ IEcoFL1AlphabetPtr_t me);
    IEcoFL1SymbolSet* (ECOCALLMETHOD *AddSymbolSet)(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ char_t* Name);
    IEcoFL1SymbolSet* (ECOCALLMETHOD *get_SymbolSet)(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ uint32_t index);
    IEcoList1* (ECOCALLMETHOD *get_SymbolSets)(/* in */ IEcoFL1AlphabetPtr_t me);

} IEcoFL1AlphabetVTbl, *IEcoFL1AlphabetVTblPtr;

interface IEcoFL1Alphabet {
    struct IEcoFL1AlphabetVTbl *pVTbl;
} IEcoFL1Alphabet;


#endif /* __I_ECO_FORMAL_LANGUAGE_1_H__ */



