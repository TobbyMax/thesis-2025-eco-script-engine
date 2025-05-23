/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoGlushkov1Sink
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoGlushkov1Sink
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoGlushkov1Sink.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoGlushkov1Events
 * </описание>
 *
 */
int16_t CEcoGlushkov1Sink_QueryInterface(/* in */ struct IEcoGlushkov1Events* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoGlushkov1Events) ) {
        *ppv = &pCMe->m_pVTbIEvents;
        pCMe->m_pVTbIEvents->AddRef((IEcoGlushkov1Events*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTbIEvents;
        pCMe->m_pVTbIEvents->AddRef((IEcoGlushkov1Events*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoGlushkov1Events
 * </описание>
 *
 */
uint32_t CEcoGlushkov1Sink_AddRef(/* in */ struct IEcoGlushkov1Events* me) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)me;

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
 *   Функция Release для интерфейса IEcoGlushkov1Events
 * </описание>
 *
 */
uint32_t CEcoGlushkov1Sink_Release(/* in */ struct IEcoGlushkov1Events* me) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoGlushkov1Sink((IEcoGlushkov1Events*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}


/*
 *
 * <сводка>
 *   Функция OnInfoMessage
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoGlushkov1Sink_OnInfoMessage(/* in */ struct IEcoGlushkov1Events* me, /* in */ char_t* messsage) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)me;

    /* Проверка указателей */
    if (me == 0) {
        return;
    }

    pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, messsage);

    return;
}

/*
 *
 * <сводка>
 *   Функция OnSubordinationRule
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoGlushkov1Sink_OnSubordinationRule(/* in */ struct IEcoGlushkov1Events* me, /* in */ uint16_t position, /* in */ uint16_t index) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)me;

    /* Проверка указателей */
    if (me == 0) {
        return;
    }

    pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "Subordination position %d at %d", position, index);

    return;
}

/* Create Virtual Table */
IEcoGlushkov1EventsVTbl g_xCD50BE2384284365A7E4F88087792392VTbl = {
    CEcoGlushkov1Sink_QueryInterface,
    CEcoGlushkov1Sink_AddRef,
    CEcoGlushkov1Sink_Release,
    CEcoGlushkov1Sink_OnInfoMessage,
    CEcoGlushkov1Sink_OnSubordinationRule
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
int16_t createCEcoGlushkov1Sink(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ IEcoLog1* pILog, /* out */ IEcoGlushkov1Events** ppISubscriber) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoGlushkov1Sink* pCMe = 0;

    /* Проверка указателей */
    if (ppISubscriber == 0 || pIUnkSystem == 0) {
        return result;
    }


   /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

   /* Проверка */
 /*   if (result != 0 && pISys == 0) {
        return result;
    } */ pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoGlushkov1Sink*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoGlushkov1Sink));

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoGlushkov1Events */
    pCMe->m_pVTbIEvents = &g_xCD50BE2384284365A7E4F88087792392VTbl;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoGlushkov1Sink((IEcoGlushkov1Events*)pCMe);
    }

    /* Инициализация данных */
    pCMe->m_pILog = pILog;

    /* Возврат указателя на интерфейс */
    *ppISubscriber = (IEcoGlushkov1Events*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
    pISys->pVTbl->Release(pISys);

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
void deleteCEcoGlushkov1Sink(/* in */ IEcoGlushkov1Events* pISubscriber) {
    CEcoGlushkov1Sink* pCMe = (CEcoGlushkov1Sink*)pISubscriber;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pISubscriber != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
