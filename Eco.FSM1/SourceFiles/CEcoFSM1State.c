/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1State
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1State
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFSM1State.h"
#include "CEcoFSM1Event.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1State
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_QueryInterface(/* in */ IEcoFSM1StatePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1State) ) {
        *ppv = &pCMe->m_pVTblIState;
        pCMe->m_pVTblIState->AddRef((IEcoFSM1State*)&pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIState;
        pCMe->m_pVTblIState->AddRef((IEcoFSM1State*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFSM1State
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_AddRef(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

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
 *   Функция Release для интерфейса IEcoFSM1State
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_Release(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1State_2C4F446F((IEcoFSM1State*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
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
int16_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_get_Id(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Id;
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
char_t* ECOCALLMETHOD CEcoFSM1State_2C4F446F_get_Name(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция set_Name
 * </сводка>
 *
 * <описание>
 *   Функция задает имя состояния
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1State_2C4F446F_set_Name(/* in */ IEcoFSM1StatePtr_t me, /* in */ char_t* Name) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    if ( pCMe->m_Name != 0 ) {
        pCMe->m_pIString->pVTbl->Free(pCMe->m_pIString, pCMe->m_Name);
        pCMe->m_Name = 0;
    }

    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
    }

}

/*
 *
 * <сводка>
 *   Функция IsInitial
 * </сводка>
 *
 * <описание>
 *   Функция возвращает состояния
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_IsInitial(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Initial;
}

/*
 *
 * <сводка>
 *   Функция set_Initial
 * </сводка>
 *
 * <описание>
 *   Функция задает состояния
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1State_2C4F446F_set_Initial(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t isInitial) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Initial = isInitial;
}

/*
 *
 * <сводка>
 *   Функция IsFinal
 * </сводка>
 *
 * <описание>
 *   Функция возвращает состояния
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_IsFinal(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Final;
}

/*
 *
 * <сводка>
 *   Функция set_Final
 * </сводка>
 *
 * <описание>
 *   Функция задает состояния
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1State_2C4F446F_set_Final(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t IsFinal) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Final = IsFinal;
}

/*
 *
 * <сводка>
 *   Функция IsTrap
 * </сводка>
 *
 * <описание>
 *   Функция возвращает состояния
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_IsTrap(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Trap;
}

/*
 *
 * <сводка>
 *   Функция set_Trap
 * </сводка>
 *
 * <описание>
 *   Функция задает состояния
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1State_2C4F446F_set_Trap(/* in */ IEcoFSM1StatePtr_t me, /* in */ bool_t IsTrap) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    pCMe->m_Trap = IsTrap;
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
void ECOCALLMETHOD CEcoFSM1State_2C4F446F_set_Parameter(/* in */ IEcoFSM1StatePtr_t me, /* in */ voidptr_t value) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

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
voidptr_t ECOCALLMETHOD CEcoFSM1State_2C4F446F_get_Parameter(/* in */ IEcoFSM1StatePtr_t me) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Parametr;
}

/* Create Virtual Table */
IEcoFSM1StateVTbl g_x6242C2A931D94FB9A1CB8AC693AD6EB4VTbl_2C4F446F = {
    CEcoFSM1State_2C4F446F_QueryInterface,
    CEcoFSM1State_2C4F446F_AddRef,
    CEcoFSM1State_2C4F446F_Release,
    CEcoFSM1State_2C4F446F_get_Id,
    CEcoFSM1State_2C4F446F_get_Name,
    CEcoFSM1State_2C4F446F_set_Name,
    CEcoFSM1State_2C4F446F_IsInitial,
    CEcoFSM1State_2C4F446F_set_Initial,
    CEcoFSM1State_2C4F446F_IsFinal,
    CEcoFSM1State_2C4F446F_set_Final,
    CEcoFSM1State_2C4F446F_IsTrap,
    CEcoFSM1State_2C4F446F_set_Trap,
    CEcoFSM1State_2C4F446F_get_Parameter,
    CEcoFSM1State_2C4F446F_set_Parameter
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
int16_t ECOCALLMETHOD createCEcoFSM1State_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* in */ int16_t Id, /* out */ IEcoFSM1State** ppIState) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1State_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIState == 0 || pIUnkSystem == 0 ) {
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
    pCMe = (CEcoFSM1State_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1State_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1State */
    pCMe->m_pVTblIState = &g_x6242C2A931D94FB9A1CB8AC693AD6EB4VTbl_2C4F446F;

    pCMe->m_Initial = 0;
    pCMe->m_Final = 0;
    pCMe->m_Trap = 0;
    pCMe->m_pIString = 0;
    pCMe->m_Name = 0;
    pCMe->m_Parametr = 0;

    /* Сохраняем идентификатор */
    pCMe->m_Id = Id;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1State_2C4F446F((IEcoFSM1State*)pCMe);
    }

    /* Сохраняем имя состояния */
    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
    }

    /* Возврат указателя на интерфейс */
    *ppIState = (IEcoFSM1State*)pCMe;

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
void ECOCALLMETHOD deleteCEcoFSM1State_2C4F446F(/* in */ IEcoFSM1State* pIState) {
    CEcoFSM1State_2C4F446F* pCMe = (CEcoFSM1State_2C4F446F*)pIState;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIState != 0 ) {
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
