/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFL1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFL1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFL1Alphabet.h"
#include <CEcoFL1SymbolSet.h>

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFL1Alphabet
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_QueryInterface(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFL1Alphabet) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFL1Alphabet*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFL1Alphabet*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoFL1Alphabet
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_AddRef(/* in */ IEcoFL1AlphabetPtr_t me) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoFL1Alphabet
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_Release(/* in */ IEcoFL1AlphabetPtr_t me) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFL1Alphabet_2C4F446F((IEcoFL1Alphabet*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает имя алфавита
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_get_Name(/* in */ IEcoFL1AlphabetPtr_t me) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция AddSymbolSet
 * </сводка>
 *
 * <описание>
 *   Функция добавляет набор символов в алфавит
 * </описание>
 *
 */
IEcoFL1SymbolSet* ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_AddSymbolSet(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ char_t* Name) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;
    IEcoFL1SymbolSet* pISymbolSet = 0;
    int16_t result = -1;
    int16_t nSymbolSetId = 0;

    if (me == 0 || pCMe->m_SymbolSets == 0) {
        return 0;
    }

    nSymbolSetId = (int16_t) pCMe->m_SymbolSets->pVTbl->Count(pCMe->m_SymbolSets);
    result = createCEcoFL1SymbolSet_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, nSymbolSetId, &pISymbolSet);
    if (result != 0 || pISymbolSet == 0) {
        return 0;
    }

    pCMe->m_SymbolSets->pVTbl->Add(pCMe->m_SymbolSets, pISymbolSet);

    return pISymbolSet;
}

/*
 *
 * <сводка>
 *   Функция get_SymbolSet
 * </сводка>
 *
 * <описание>
 *   Функция возвращает набор символов по индексу
 * </описание>
 *
 */
IEcoFL1SymbolSet* ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_get_SymbolSet(/* in */ IEcoFL1AlphabetPtr_t me, /* in */ uint32_t index) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;
    IEcoFL1SymbolSet* pISymbolSet = 0;

    if (me == 0 ) {
        return -1;
    }

    pISymbolSet = (IEcoFL1SymbolSet*)pCMe->m_SymbolSets->pVTbl->Item(pCMe->m_SymbolSets, index);
    return pISymbolSet;
}

/*
 *
 * <сводка>
 *   Функция get_SymbolSets
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список наборов символов
 * </описание>
 *
 */
IEcoList1* ECOCALLMETHOD CEcoFL1Alphabet_2C4F446F_get_SymbolSets(/* in */ IEcoFL1AlphabetPtr_t me) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_SymbolSets;
}


/* Create Virtual Table */
IEcoFL1AlphabetVTbl g_x34832ECFCA8E4B1693F0C735F0CA9F8DVTbl_2C4F446F = {
    CEcoFL1Alphabet_2C4F446F_QueryInterface,
    CEcoFL1Alphabet_2C4F446F_AddRef,
    CEcoFL1Alphabet_2C4F446F_Release,
    CEcoFL1Alphabet_2C4F446F_get_Name,
    CEcoFL1Alphabet_2C4F446F_AddSymbolSet,
    CEcoFL1Alphabet_2C4F446F_get_SymbolSet,
    CEcoFL1Alphabet_2C4F446F_get_SymbolSets
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoFL1Alphabet_2C4F446F(IEcoUnknown *pIUnkSystem, IEcoUnknown *pIUnkOuter, char_t *Name, IEcoFL1Alphabet **ppIAlphabet) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFL1Alphabet_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIAlphabet == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (voidptr_t*)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (voidptr_t*)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (voidptr_t*) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoFL1Alphabet_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFL1Alphabet_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFL1Alphabet */
    pCMe->m_pVTblIEvent = &g_x34832ECFCA8E4B1693F0C735F0CA9F8DVTbl_2C4F446F;

    pCMe->m_pIString = 0;
    pCMe->m_Name = 0;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFL1Alphabet_2C4F446F((IEcoFL1Alphabet*)pCMe);
    }

    /* Создание экземпляра списка для символьных наборов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_SymbolSets);
    if (result != 0 || pCMe->m_SymbolSets == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFL1Alphabet_2C4F446F((IEcoFL1Alphabet*)pCMe);
    }

    /* Сохраняем имя состояния */
    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
    }

    /* Возврат указателя на интерфейс */
    *ppIAlphabet = (IEcoFL1Alphabet*)pCMe;

    /* Освобождение интерфейсной шиной */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoFL1Alphabet_2C4F446F(/* in */ IEcoFL1Alphabet* pIAlphabet) {
    CEcoFL1Alphabet_2C4F446F* pCMe = (CEcoFL1Alphabet_2C4F446F*)pIAlphabet;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIAlphabet != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pCMe->m_pIString->pVTbl->Free(pCMe->m_pIString, pCMe->m_Name);
        }
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }

        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
