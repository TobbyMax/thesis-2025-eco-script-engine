/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFL1Alphabet
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFL1Alphabet
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

typedef struct CEcoFL1Alphabet_2C4F446F {

    /* Таблица функций интерфейса IEcoFL1Alphabet */
    IEcoFL1AlphabetVTbl* m_pVTblIEvent;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    IEcoList1* m_SymbolSets;
    char_t* m_Name;
} CEcoFL1Alphabet_2C4F446F, *CEcoFL1Alphabet_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFL1Alphabet_2C4F446F(IEcoUnknown *pIUnkSystem, IEcoUnknown *pIUnkOuter, char_t *Name,
                                                     IEcoFL1Alphabet **ppIAlphabet);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFL1Alphabet_2C4F446F(/* in */ IEcoFL1Alphabet* pIEvent);

#endif /* __C_ECO_FINITE_LANGUAGE_1_H__ */
