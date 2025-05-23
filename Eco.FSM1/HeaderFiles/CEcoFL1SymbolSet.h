/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFL1SymbolSet
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFL1SymbolSet
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_LANGUAGE_1_H__
#define __C_ECO_FINITE_LANGUAGE_1_H__

#include "IEcoFL1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IEcoFSM1.h"

typedef struct CEcoFL1SymbolSet_2C4F446F {

    /* Таблица функций интерфейса IEcoFL1SymbolSet */
    IEcoFL1SymbolSetVTbl* m_pVTblIEvent;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    IEcoList1* m_Ranges;
    IEcoList1* m_Symbols;
    char_t* m_Name;
    int16_t m_Id;
    bool_t m_IsWord;
    bool_t m_IsEmpty;
    bool_t m_IsRange;
    uint32_t m_Count;
    uint32_t m_Length;
    uint32_t m_Align;
    bool_t m_IsComplement;
    bool_t m_IsTerminal;
    uint32_t m_WordPosition;
    IEcoFSM1State* m_pIWordFailedState;
    IEcoFSM1State* m_pIWordState;
    bool_t m_IsFinished;

} CEcoFL1SymbolSet_2C4F446F, *CEcoFL1SymbolSet_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFL1SymbolSet_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* in */ int16_t Id, /* out */ IEcoFL1SymbolSet** ppISymbolSet);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFL1SymbolSet_2C4F446F(/* in */ IEcoFL1SymbolSet* pIEvent);

#endif /* __C_ECO_FINITE_LANGUAGE_1_H__ */
