/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1Event
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1Event
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFSM1Event.h"
#include "CEcoFL1SymbolSet.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1Event
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_QueryInterface(/* in */ IEcoFSM1EventPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1Event) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFSM1Event*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEvent;
        pCMe->m_pVTblIEvent->AddRef((IEcoFSM1Event*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFSM1Event
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_AddRef(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

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
 *   Функция Release для интерфейса IEcoFSM1Event
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_Release(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1Event_2C4F446F((IEcoFSM1Event*)pCMe);
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
char_t* ECOCALLMETHOD CEcoFSM1Event_2C4F446F_get_Name(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция IsNull
 * </сводка>
 *
 * <описание>
 *   Функция возвращает состояния
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_IsNull(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Null;
}

/*
 *
 * <сводка>
 *   Функция set_Null
 * </сводка>
 *
 * <описание>
 *   Функция задает состояния
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1Event_2C4F446F_set_Null(/* in */ IEcoFSM1EventPtr_t me, /* in */ bool_t isNull) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Null = isNull;
}

/*
 *
 * <сводка>
 *   Функция set_Parameter
 * </сводка>
 *
 * <описание>
 *   Функция сохраняет указатель на параметр
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1Event_2C4F446F_set_Parameter(/* in */ IEcoFSM1EventPtr_t me, /* in */ voidptr_t value) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Parametr = value;

}

/*
 *
 * <сводка>
 *   Функция get_Parameter
 * </сводка>
 *
 * <описание>
 *   Функция возвращает параметр
 * </описание>
 *
 */
voidptr_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_get_Parameter(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Parametr;
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
int16_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_get_Id(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Id;
}

/*
 *
 * <сводка>
 *   Функция IsSymbolClass
 * </сводка>
 *
 * <описание>
 *   Функция проверяет является ли событие символьным классом
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1Event_2C4F446F_IsSymbolClass(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_IsSymbolClass;
}

/*
 *
 * <сводка>
 *   Функция AddSymbolSet
 * </сводка>
 *
 * <описание>
 *   Функция добавляет символьный набор
 * </описание>
 *
 */
IEcoFL1SymbolSet* ECOCALLMETHOD CEcoFSM1Event_2C4F446F_AddSymbolSet(/* in */ IEcoFSM1EventPtr_t me, /* in */ char_t* Name) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;
    IEcoFL1SymbolSet* pISymbolSet = 0;
    int16_t result = -1;
    int16_t nSymbolSetId = 0;

    if (me == 0 || pCMe->m_SymbolSets == 0) {
        return 0;
    }

    pCMe->m_IsSymbolClass = 1;

    nSymbolSetId = (int16_t) pCMe->m_SymbolSets->pVTbl->Count(pCMe->m_SymbolSets);
    result = createCEcoFL1SymbolSet_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name,nSymbolSetId, &pISymbolSet);
    if (result != 0 || pISymbolSet == 0) {
        return 0;
    }

    pCMe->m_SymbolSets->pVTbl->Add(pCMe->m_SymbolSets, pISymbolSet);

    return pISymbolSet;
}


/*
 *
 * <сводка>
 *   Функция AddExistingSymbolSet
 * </сводка>
 *
 * <описание>
 *   Функция добавляет существующий символьный набор
 * </описание>
 *
 */
IEcoFL1SymbolSet* ECOCALLMETHOD CEcoFSM1Event_2C4F446F_AddExistingSymbolSet(/* in */ IEcoFSM1EventPtr_t me, /* in */ IEcoFL1SymbolSet* pISymbolSet) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 || pISymbolSet == 0) {
        return 0;
    }

    pCMe->m_IsSymbolClass = 1;

    pCMe->m_SymbolSets->pVTbl->Add(pCMe->m_SymbolSets, pISymbolSet);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция get_SymbolSet
 * </сводка>
 *
 * <описание>
 *   Функция возвращает символьный набор
 * </описание>
 *
 */

IEcoFL1SymbolSet* ECOCALLMETHOD CEcoFSM1Event_2C4F446F_get_SymbolSet(/* in */ IEcoFSM1EventPtr_t me, /* in */ uint32_t index) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;
    IEcoFL1SymbolSet* pSymbolSet = 0;

    if (me == 0 || pCMe->m_SymbolSets == 0) {
        return 0;
    }

    pSymbolSet = pCMe->m_SymbolSets->pVTbl->Item(pCMe->m_SymbolSets, index);

    return pSymbolSet;
}

/*
 *
 * <сводка>
 *   Функция get_SymbolSets
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список символьных наборов
 * </описание>
 *
 */
IEcoList1* ECOCALLMETHOD CEcoFSM1Event_2C4F446F_get_SymbolSets(/* in */ IEcoFSM1EventPtr_t me) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)me;

    if (me == 0 || pCMe->m_SymbolSets == 0) {
        return 0;
    }

    return pCMe->m_SymbolSets;
}

/* Create Virtual Table */
IEcoFSM1EventVTbl g_x1BFBB309B33F4E86AABE0C41ED5E256CVTbl_2C4F446F = {
    CEcoFSM1Event_2C4F446F_QueryInterface,
    CEcoFSM1Event_2C4F446F_AddRef,
    CEcoFSM1Event_2C4F446F_Release,
    CEcoFSM1Event_2C4F446F_get_Name,
    CEcoFSM1Event_2C4F446F_get_Id,
    CEcoFSM1Event_2C4F446F_IsNull,
    CEcoFSM1Event_2C4F446F_set_Null,
    CEcoFSM1Event_2C4F446F_IsSymbolClass,
    CEcoFSM1Event_2C4F446F_AddSymbolSet,
    CEcoFSM1Event_2C4F446F_AddExistingSymbolSet,
    CEcoFSM1Event_2C4F446F_get_SymbolSet,
    CEcoFSM1Event_2C4F446F_get_SymbolSets,
    CEcoFSM1Event_2C4F446F_get_Parameter,
    CEcoFSM1Event_2C4F446F_set_Parameter
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
int16_t ECOCALLMETHOD createCEcoFSM1Event_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* in */ int16_t Id, /* in */ bool_t isNull, /* out */ IEcoFSM1Event** ppIEvent) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1Event_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIEvent == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoFSM1Event_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1Event_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1Event */
    pCMe->m_pVTblIEvent = &g_x1BFBB309B33F4E86AABE0C41ED5E256CVTbl_2C4F446F;

    pCMe->m_pIString = 0;
    pCMe->m_Name = 0;
    pCMe->m_Null = isNull;
    /* Сохраняем идентификатор */
    pCMe->m_Id = Id;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1Event_2C4F446F((IEcoFSM1Event*)pCMe);
    }

    /* Создание экземпляра списка для символьных наборов */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_SymbolSets);
    if (result != 0 || pCMe->m_SymbolSets == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1Event_2C4F446F((IEcoFSM1Event*)pCMe);
    }

    /* Сохраняем имя состояния */
    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
    }

    /* Возврат указателя на интерфейс */
    *ppIEvent = (IEcoFSM1Event*)pCMe;

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
void ECOCALLMETHOD deleteCEcoFSM1Event_2C4F446F(/* in */ IEcoFSM1Event* pIEvent) {
    CEcoFSM1Event_2C4F446F* pCMe = (CEcoFSM1Event_2C4F446F*)pIEvent;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEvent != 0 ) {
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
