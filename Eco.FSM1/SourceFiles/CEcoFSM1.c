/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoFSM1.h"
#include "CEcoFSM1Event.h"
#include "CEcoFSM1StateMachine.h"
#include "CEcoFSM1EventProcessing.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1_2C4F446F_QueryInterface(/* in */ IEcoFSM1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1) ) {
        *ppv = &pCMe->m_pVTblIFSM;
        pCMe->m_pVTblIFSM->AddRef((IEcoFSM1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIFSM;
        pCMe->m_pVTblIFSM->AddRef((IEcoFSM1*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFSM1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1_2C4F446F_AddRef(/* in */ IEcoFSM1Ptr_t me) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;

    /* Проверка указателя */
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
 *   Функция Release для интерфейса IEcoFSM1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1_2C4F446F_Release(/* in */ IEcoFSM1Ptr_t me) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1_2C4F446F((IEcoFSM1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция CreateEvent
 * </сводка>
 *
 * <описание>
 *   Функция возвращает интерфейс конечного автомата
 * </описание>
 *
 */
IEcoFSM1Event* ECOCALLMETHOD CEcoFSM1_2C4F446F_CreateEvent(/* in */ IEcoFSM1Ptr_t me, /* in */ char_t* Name, /* in */ int16_t Id, /* in */ bool_t isNull) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;
    IEcoFSM1Event* pIEvent = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    createCEcoFSM1Event_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, Id, isNull, &pIEvent);

    return pIEvent;
}

/*
 *
 * <сводка>
 *   Функция CreateStateMachine
 * </сводка>
 *
 * <описание>
 *   Функция возвращает интерфейс конечного автомата
 * </описание>
 *
 */
IEcoFSM1StateMachine* ECOCALLMETHOD CEcoFSM1_2C4F446F_CreateStateMachine(/* in */ IEcoFSM1Ptr_t me, /* in */ char_t* Name) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;
    IEcoFSM1StateMachine* pIStateMachine = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    createCEcoFSM1StateMachine_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, &pIStateMachine);

    return pIStateMachine;
}

/*
 *
 * <сводка>
 *   Функция get_EventProcessing
 * </сводка>
 *
 * <описание>
 *   Функция возвращает интерфейс обработчика событий конечного автомата
 * </описание>
 *
 */
IEcoFSM1EventProcessing* ECOCALLMETHOD CEcoFSM1_2C4F446F_get_EventProcessing(/* in */ IEcoFSM1Ptr_t me, /* in */ IEcoFSM1StateMachine* StateMachine) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;
    IEcoFSM1EventProcessing* pIEventProcessing = 0;

        /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    createCEcoFSM1EventProcessing_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, StateMachine, &pIEventProcessing);

    return pIEventProcessing;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoFSM1_2C4F446F(/*in*/ IEcoFSM1Ptr_t me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Инициализация данных */

    return 0;
}

/* Create Virtual Table */
IEcoFSM1VTbl g_x7ACB8256EEB340FA8E839A9AF03464D5VTbl_2C4F446F = {
    CEcoFSM1_2C4F446F_QueryInterface,
    CEcoFSM1_2C4F446F_AddRef,
    CEcoFSM1_2C4F446F_Release,
    CEcoFSM1_2C4F446F_CreateStateMachine,
    CEcoFSM1_2C4F446F_get_EventProcessing
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
int16_t ECOCALLMETHOD createCEcoFSM1_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoFSM1** ppIEcoFSM1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIEcoFSM1 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoFSM1_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1 */
    pCMe->m_pVTblIFSM = &g_x7ACB8256EEB340FA8E839A9AF03464D5VTbl_2C4F446F;

    /* Инициализация данных */

    /* Возврат указателя на интерфейс */
    *ppIEcoFSM1 = (IEcoFSM1*)pCMe;

    /* Освобождение */
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
void ECOCALLMETHOD deleteCEcoFSM1_2C4F446F(/* in */ IEcoFSM1* pIEcoFSM1) {
    CEcoFSM1_2C4F446F* pCMe = (CEcoFSM1_2C4F446F*)pIEcoFSM1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoFSM1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
