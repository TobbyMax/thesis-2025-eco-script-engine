/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1Transition
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1Transition
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFSM1Transition.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1Transition
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_QueryInterface(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1Transition) ) {
        *ppv = &pCMe->m_pVTblITransition;
        pCMe->m_pVTblITransition->AddRef((IEcoFSM1Transition*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblITransition;
        pCMe->m_pVTblITransition->AddRef((IEcoFSM1Transition*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFSM1Transition
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_AddRef(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

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
 *   Функция Release для интерфейса IEcoFSM1Transition
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_Release(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1Transition_2C4F446F((IEcoFSM1Transition*)pCMe);
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
char_t* ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Name(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

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
 *   Функция сохраняет указатель на параметр
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_set_Name(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ char_t* value) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return;
    }

    if (pCMe->m_Name != 0) {
        pCMe->m_pIString->pVTbl->Free(pCMe->m_pIString, pCMe->m_Name);
        pCMe->m_Name = 0;
    }
    pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, value);
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
int16_t ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Id(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Id;
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
void ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_set_Parameter(/* in */ IEcoFSM1TransitionPtr_t me, /* in */ voidptr_t value) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

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
voidptr_t ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Parameter(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Parametr;
}

/*
 *
 * <сводка>
 *   Функция get_Event
 * </сводка>
 *
 * <описание>
 *   Функция возвращает событие
 * </описание>
 *
 */
IEcoFSM1Event* ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Event(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Event;
}

/*
 *
 * <сводка>
 *   Функция get_Source
 * </сводка>
 *
 * <описание>
 *   Функция возвращает исходное состояние
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Source(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Source;
}
/*
 *
 * <сводка>
 *   Функция get_Target
 * </сводка>
 *
 * <описание>
 *   Функция возвращает конечное состояние
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1Transition_2C4F446F_get_Target(/* in */ IEcoFSM1TransitionPtr_t me) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Target;
}

/* Create Virtual Table */
IEcoFSM1TransitionVTbl g_x00C3032A56F24474B4FD6F837D907909VTbl_2C4F446F = {
    CEcoFSM1Transition_2C4F446F_QueryInterface,
    CEcoFSM1Transition_2C4F446F_AddRef,
    CEcoFSM1Transition_2C4F446F_Release,
    CEcoFSM1Transition_2C4F446F_get_Name,
    CEcoFSM1Transition_2C4F446F_set_Name,
    CEcoFSM1Transition_2C4F446F_get_Id,
    CEcoFSM1Transition_2C4F446F_get_Parameter,
    CEcoFSM1Transition_2C4F446F_set_Parameter,
    CEcoFSM1Transition_2C4F446F_get_Event,
    CEcoFSM1Transition_2C4F446F_get_Source,
    CEcoFSM1Transition_2C4F446F_get_Target
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
int16_t ECOCALLMETHOD createCEcoFSM1Transition_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ int16_t Id, /* in */ IEcoFSM1Event* Event, /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target, /* out */ IEcoFSM1Transition** ppITransition) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1Transition_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppITransition == 0 || pIUnkSystem == 0 || Event == 0 || Source == 0 || Target == 0) {
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
    pCMe = (CEcoFSM1Transition_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1Transition_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1Transition */
    pCMe->m_pVTblITransition = &g_x00C3032A56F24474B4FD6F837D907909VTbl_2C4F446F;

    pCMe->m_pIString = 0;
    /* Сохраняем указателя на список состояний */
    pCMe->m_Event = Event;
    pCMe->m_Event->pVTbl->AddRef(pCMe->m_Event);
    pCMe->m_Source = Source;
    pCMe->m_Source->pVTbl->AddRef(pCMe->m_Source);
    pCMe->m_Target = Target;
    pCMe->m_Target->pVTbl->AddRef(pCMe->m_Target);
    pCMe->m_Parametr = 0;
    pCMe->m_Name = 0;
    /* Сохраняем идентификатор */
    pCMe->m_Id = Id;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1Transition_2C4F446F((IEcoFSM1Transition*)pCMe);
    }

    /* Сохраняем имя состояния */
    if (Event->pVTbl->get_Name(Event) != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Event->pVTbl->get_Name(Event));
    }

    /* Возврат указателя на интерфейс */
    *ppITransition = (IEcoFSM1Transition*)pCMe;

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
void ECOCALLMETHOD deleteCEcoFSM1Transition_2C4F446F(/* in */ IEcoFSM1Transition* pITransition) {
    CEcoFSM1Transition_2C4F446F* pCMe = (CEcoFSM1Transition_2C4F446F*)pITransition;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pITransition != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pCMe->m_pIString->pVTbl->Free(pCMe->m_pIString, pCMe->m_Name);
        }
        if ( pCMe->m_Parametr != 0 ) {
            pCMe->m_pIString->pVTbl->Free(pCMe->m_pIString, (char_t*)pCMe->m_Parametr);
        }
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }
        if ( pCMe->m_Event != 0 ) {
            pCMe->m_Event->pVTbl->Release(pCMe->m_Event);
        }
        if ( pCMe->m_Source != 0 ) {
            pCMe->m_Source->pVTbl->Release(pCMe->m_Source);
        }
        if ( pCMe->m_Target != 0 ) {
            pCMe->m_Target->pVTbl->Release(pCMe->m_Target);
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
