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
#include "CEcoFL1SymbolSet.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFL1SymbolSet
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_QueryInterface(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFL1SymbolSet) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFL1SymbolSet*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFL1SymbolSet*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFL1SymbolSet
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_AddRef(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

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
 *   Функция Release для интерфейса IEcoFL1SymbolSet
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_Release(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFL1SymbolSet_2C4F446F((IEcoFL1SymbolSet*)pCMe);
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
 *   Функция возвращает имя состояния
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Name(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Count
 * </сводка>
 *
 * <описание>
 *   Функция возвращает количество символов
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Count(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Count;
}

/*
 *
 * <сводка>
 *   Функция get_Length
 * </сводка>
 *
 * <описание>
 *   Функция возвращает длину символа
 * </описание>
 *
 */
uint8_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Length(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Length;
}

/*
 *
 * <сводка>
 *   Функция set_Length
 * </сводка>
 *
 * <описание>
 *   Функция задает длину символов
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_Length(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint8_t value) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Length = value;
}

/*
 *
 * <сводка>
 *   Функция get_Align
 * </сводка>
 *
 * <описание>
 *   Функция возвращает выравнивание символов
 * </описание>
 *
 */
uint8_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Align(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Align;
}


/*
 *
 * <сводка>
 *   Функция set_Align
 * </сводка>
 *
 * <описание>
 *   Функция задает выравнивание символов
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_Align(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint8_t value) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Align = value;
}

/*
 *
 * <сводка>
 *   Функция IsComplement
 * </сводка>
 *
 * <описание>
 *   Функция возвращает является ли класс комплементарным
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsComplement(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_IsComplement;
}

/*
 *
 * <сводка>
 *   Функция set_Complement
 * </сводка>
 *
 * <описание>
 *   Функция задает состояние комплементарности
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_Complement(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ bool_t value) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_IsComplement = value;
}

/*
 *
 * <сводка>
 *   Функция IsTerminal
 * </сводка>
 *
 * <описание>
 *   Функция возвращает является ли класс терминальным
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsTerminal(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_IsTerminal;
}

/*
 *
 * <сводка>
 *   Функция set_Terminal
 * </сводка>
 *
 * <описание>
 *   Функция задает состояние терминальности
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_Terminal(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ bool_t value) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_IsTerminal = value;
}

/*
 *
 * <сводка>
 *   Функция IsEmpty
 * </сводка>
 *
 * <описание>
 *   Функция возвращает является ли класс пустым
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsEmpty(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Count == 0;
}

/*
 *
 * <сводка>
 *   Функция IsWord
 * </сводка>
 *
 * <описание>
 *   Функция возвращает является ли класс словом
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsWord(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_IsWord;
}

/*
 *
 * <сводка>
 *   Функция IsRange
 * </сводка>
 *
 * <описание>
 *   Функция возвращает является ли класс диапазоном
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsRange(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0) {
        return 0;
    }

    return pCMe->m_IsRange;
}

/*
 *
 * <сводка>
 *   Функция AddSymbol
 * </сводка>
 *
 * <описание>
 *   Функция добавляет символ в класс
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_AddSymbol(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits, /* out */ uint32_t* index) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_Symbols == 0) {
        return -1;
    }

    if (pCMe->m_IsWord) {
        return -1;
    }

    if (pCMe->m_IsRange) {
        return -1;
    }

    /* Добавление символа в список */
    pCMe->m_Symbols->pVTbl->Add(pCMe->m_Symbols, Symbol);
    pCMe->m_Count++;
    return 0;
}

/*
 *
 * <сводка>
 *   Функция get_Symbol
 * </сводка>
 *
 * <описание>
 *   Функция возвращает символ по индексу
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Symbol(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t index, /* out */ byte_t** Symbol, /* out */ uint8_t* offsetBits) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;
    uint32_t count = 0;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_Symbols == 0) {
        return -1;
    }

    if (pCMe->m_IsRange == 1 || pCMe->m_IsWord == 1) {
        return -1;
    }

    count = pCMe->m_Symbols->pVTbl->Count(pCMe->m_Symbols);

    if (index >= count) {
        return -1;
    }

    *Symbol = (byte_t*)pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, index);
    return 0;
}


/*
 *
 * <сводка>
 *   Функция AddSymbolRange
 * </сводка>
 *
 * <описание>
 *   Функция добавляет диапазон символов в класс
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_AddSymbolRange(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t start, /* in */ uint32_t end, /* out */ uint32_t* index) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0) {
        return -1;
    }

    if (pCMe->m_Ranges == 0) {
        return -1;
    }

    if (pCMe->m_IsWord == 1) {
        return -1;
    }

    pCMe->m_IsRange = 1;

    /* Добавление диапазона в список */
    pCMe->m_Ranges->pVTbl->Add(pCMe->m_Ranges, (void*) start);
    pCMe->m_Ranges->pVTbl->Add(pCMe->m_Ranges, (void*) end);

    pCMe->m_Count = end - start + 1;
    return 0;
}

/*
 *
 * <сводка>
 *   Функция get_SymbolRange
 * </сводка>
 *
 * <описание>
 *   Функция возвращает диапазон символов по индексу
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_SymbolRange(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ uint32_t index, /* out */ uint32_t* start, /* out */ uint32_t* end) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;
    uint32_t count = 0;

    if (me == 0 || pCMe->m_IsRange == 0) {
        return -1;
    }

    count = pCMe->m_Ranges->pVTbl->Count(pCMe->m_Ranges);

    if (index >= count/2) {
        return -1;
    }

    *start = (uint32_t)pCMe->m_Ranges->pVTbl->Item(pCMe->m_Ranges, index * 2);
    *end = (uint32_t)pCMe->m_Ranges->pVTbl->Item(pCMe->m_Ranges, index * 2 + 1);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция set_Word
 * </сводка>
 *
 * <описание>
 *   Функция задает слово
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_Word(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* word, /* in */ uint8_t length) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;
    uint32_t i = 0;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_IsWord = 1;

    /* Добавление слова */
    for (i = 0; i < length; i++) {
        pCMe->m_Symbols->pVTbl->Add(pCMe->m_Symbols,  pCMe->m_pIString->pVTbl->Substring(pCMe->m_pIString, (char_t*)word, i, 1));
    }
    pCMe->m_Count = length;
    return 0;
}

/*
 *
 * <сводка>F
 *   Функция get_Word
 * </сводка>
 *
 * <описание>
 *   Функция возвращает слово
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Word(/* in */ IEcoFL1SymbolSetPtr_t me, /* out */ byte_t** word, /* out */ uint8_t* length) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;
    uint32_t iSymbol = 0;

    if (me == 0 || pCMe->m_IsWord == 0) {
        return -1;
    }

    *length = pCMe->m_Count;
    *word = (byte_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(byte_t) * (*length));
    for (iSymbol = 0; iSymbol < (*length); iSymbol++) {
        word[iSymbol] = pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, iSymbol);
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция IsExist
 * </сводка>
 *
 * <описание>
 *   Функция проверяет наличие символа в классе
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsExist(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits) {
    CEcoFL1SymbolSet_2C4F446F *pCMe = (CEcoFL1SymbolSet_2C4F446F *) me;
    bool_t match = 0;

    if (me == 0) {
        return 0;
    }

    if (pCMe->m_IsWord && pCMe->m_WordPosition < pCMe->m_Count) {
        return (pCMe->m_pIString->pVTbl->Compare(
                pCMe->m_pIString, (char_t*)Symbol,
                (char_t*)pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, pCMe->m_WordPosition)
        ) == 0);
    } else if (pCMe->m_IsRange && pCMe->m_Ranges != 0) {
        uint32_t count = 0;
        uint32_t start = 0;
        uint32_t end = 0;
        uint32_t i = 0;

        count = pCMe->m_Ranges->pVTbl->Count(pCMe->m_Ranges);

        for (i = 0; i < count/2; i++) {
            start = (uint32_t) pCMe->m_Ranges->pVTbl->Item(pCMe->m_Ranges, i * 2);
            end = (uint32_t) pCMe->m_Ranges->pVTbl->Item(pCMe->m_Ranges, i * 2 + 1);

            match = Symbol[0] >= start && Symbol[0] <= end;
            if (match == 1 && pCMe->m_IsComplement == 1) {
                return 0;
            } else if (match == 1) {
                return 1;
            }
        }
    } else if (pCMe->m_Symbols != 0) {
        uint32_t count = 0;
        uint32_t i = 0;

        count = pCMe->m_Symbols->pVTbl->Count(pCMe->m_Symbols);

        for (i = 0; i < count; i++) {
            byte_t* curr = pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, i);
            match = (pCMe->m_pIString->pVTbl->Compare(
                    pCMe->m_pIString, (char_t*)Symbol,
                    (char_t*)pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, i)
                    ) == 0);
            if (match == 1 && pCMe->m_IsComplement == 1) {
                return 0;
            } else if (match == 1) {
                return 1;
            }
        }
    }

    if (pCMe->m_IsComplement == 1) {
        return 1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция get_Id
 * </сводка>
 *
 * <описание>
 *   Функция возвращает идентификатор состояния
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_Id(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Id;
}

/*
 *
 * <сводка>
 *   Функция set_WordState
 * </сводка>
 *
 * <описание>
 *   Функция задает внутреннее состояние слова
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_WordState(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ IEcoFSM1State* state) {
    CEcoFL1SymbolSet_2C4F446F *pCMe = (CEcoFL1SymbolSet_2C4F446F *) me;

    if (me == 0) {
        return;
    }

    pCMe->m_pIWordState = state;
}

/*
 *
 * <сводка>
 *   Функция get_WordState
 * </сводка>
 *
 * <описание>
 *   Функция возвращает внутреннее состояние слова
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_WordState(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0) {
        return 0;
    }

    return pCMe->m_pIWordState;
}

/*
 *
 * <сводка>
 *   Функция set_WordFailedState
 * </сводка>
 *
 * <описание>
 *   Функция задает состояние ошибки
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_set_WordFailedState(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ IEcoFSM1State* state) {
    CEcoFL1SymbolSet_2C4F446F *pCMe = (CEcoFL1SymbolSet_2C4F446F *) me;

    if (me == 0) {
        return;
    }

    pCMe->m_pIWordFailedState = state;
}

/*
 *
 * <сводка>
 *   Функция get_WordFailedState
 * </сводка>
 *
 * <описание>
 *   Функция возвращает состояние ошибки
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_get_WordFailedState(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0) {
        return 0;
    }

    return pCMe->m_pIWordFailedState;
}

/*
 *
 * <сводка>
 *   Функция InvokeBySymbol
 * </сводка>
 *
 * <описание>
 *   Функция вызывает автомат по символу
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_InvokeBySymbol(/* in */ IEcoFL1SymbolSetPtr_t me, /* in */ byte_t* Symbol, /* in */ uint8_t lengthBits, /* in */ uint8_t offsetBits) {
    CEcoFL1SymbolSet_2C4F446F *pCMe = (CEcoFL1SymbolSet_2C4F446F *) me;
    bool_t match = 0;

    if (me == 0 || pCMe->m_IsWord == 0) {
        return 0;
    }

    if (pCMe->m_WordPosition >= pCMe->m_Count) {
        return 0;
    }
    match = (pCMe->m_pIString->pVTbl->Compare(
            pCMe->m_pIString, (char_t *) Symbol,
            (char_t *) pCMe->m_Symbols->pVTbl->Item(pCMe->m_Symbols, pCMe->m_WordPosition)
    ) == 0);
    if (match == 1) {
        ++pCMe->m_WordPosition;
        pCMe->m_IsFinished = 0;
        if (pCMe->m_WordPosition == pCMe->m_Count) {
            pCMe->m_IsFinished = 1;
            pCMe->m_WordPosition = 0;
        }
        return pCMe->m_pIWordState;
    }

    pCMe->m_IsFinished = 1;
    pCMe->m_WordPosition = 0;
    return pCMe->m_pIWordFailedState;
}

/*
 *
 * <сводка>
 *   Функция IsFinished
 * </сводка>
 *
 * <описание>
 *   Функция проверяет завершение обработки слова вложенным автоматом
 * </описание>
 *
 *
 */
bool_t ECOCALLMETHOD CEcoFL1SymbolSet_2C4F446F_IsFinished(/* in */ IEcoFL1SymbolSetPtr_t me) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)me;

    if (me == 0 || pCMe->m_IsWord == 0) {
        return 0;
    }

    return pCMe->m_IsFinished;
}

/* Create Virtual Table */
IEcoFL1SymbolSetVTbl g_xF7C67779CC5341199D29DF94B3858D54VTbl_2C4F446F = {
    CEcoFL1SymbolSet_2C4F446F_QueryInterface,
    CEcoFL1SymbolSet_2C4F446F_AddRef,
    CEcoFL1SymbolSet_2C4F446F_Release,
    CEcoFL1SymbolSet_2C4F446F_get_Name,
    CEcoFL1SymbolSet_2C4F446F_get_Id,
    CEcoFL1SymbolSet_2C4F446F_get_Count,
    CEcoFL1SymbolSet_2C4F446F_get_Length,
    CEcoFL1SymbolSet_2C4F446F_set_Length,
    CEcoFL1SymbolSet_2C4F446F_get_Align,
    CEcoFL1SymbolSet_2C4F446F_set_Align,
    CEcoFL1SymbolSet_2C4F446F_IsComplement,
    CEcoFL1SymbolSet_2C4F446F_set_Complement,
    CEcoFL1SymbolSet_2C4F446F_IsTerminal,
    CEcoFL1SymbolSet_2C4F446F_set_Terminal,
    CEcoFL1SymbolSet_2C4F446F_IsEmpty,
    CEcoFL1SymbolSet_2C4F446F_IsWord,
    CEcoFL1SymbolSet_2C4F446F_IsRange,
    CEcoFL1SymbolSet_2C4F446F_IsExist,
    CEcoFL1SymbolSet_2C4F446F_AddSymbol,
    CEcoFL1SymbolSet_2C4F446F_get_Symbol,
    CEcoFL1SymbolSet_2C4F446F_AddSymbolRange,
    CEcoFL1SymbolSet_2C4F446F_get_SymbolRange,
    CEcoFL1SymbolSet_2C4F446F_set_Word,
    CEcoFL1SymbolSet_2C4F446F_get_Word,
    CEcoFL1SymbolSet_2C4F446F_set_WordState,
    CEcoFL1SymbolSet_2C4F446F_get_WordState,
    CEcoFL1SymbolSet_2C4F446F_set_WordFailedState,
    CEcoFL1SymbolSet_2C4F446F_get_WordFailedState,
    CEcoFL1SymbolSet_2C4F446F_InvokeBySymbol,
    CEcoFL1SymbolSet_2C4F446F_IsFinished,
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
int16_t ECOCALLMETHOD createCEcoFL1SymbolSet_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* in */ int16_t Id, /* out */ IEcoFL1SymbolSet** ppISymbolSet) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFL1SymbolSet_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppISymbolSet == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoFL1SymbolSet_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFL1SymbolSet_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFL1SymbolSet */
    pCMe->m_pVTblIEvent = &g_xF7C67779CC5341199D29DF94B3858D54VTbl_2C4F446F;

    pCMe->m_pIString = 0;
    pCMe->m_Name = 0;
    /* Сохраняем идентификатор */
    pCMe->m_Id = Id;
    pCMe->m_IsRange = 0;
    pCMe->m_IsWord = 0;
    pCMe->m_IsComplement = 0;
    pCMe->m_IsTerminal = 0;
    pCMe->m_Count = 0;
    pCMe->m_Length = 0;
    pCMe->m_Align = 0;
    pCMe->m_pIWordState = 0;
    pCMe->m_pIWordFailedState = 0;
    pCMe->m_WordPosition = 0;
    pCMe->m_IsFinished = 1;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFL1SymbolSet_2C4F446F((IEcoFL1SymbolSet*)pCMe);
    }

    /* Создание экземпляра списка для символов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_Symbols);
    if (result != 0 || pCMe->m_Symbols == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFL1SymbolSet_2C4F446F((IEcoFL1SymbolSet*)pCMe);
    }

    /* Создание экземпляра списка для диапазонов символов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_Ranges);
    if (result != 0 || pCMe->m_Ranges == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFL1SymbolSet_2C4F446F((IEcoFL1SymbolSet*)pCMe);
    }

    /* Сохраняем имя состояния */
    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
    }

    /* Возврат указателя на интерфейс */
    *ppISymbolSet = (IEcoFL1SymbolSet*)pCMe;

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
void ECOCALLMETHOD deleteCEcoFL1SymbolSet_2C4F446F(/* in */ IEcoFL1SymbolSet* pISymbolSet) {
    CEcoFL1SymbolSet_2C4F446F* pCMe = (CEcoFL1SymbolSet_2C4F446F*)pISymbolSet;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pISymbolSet != 0 ) {
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
