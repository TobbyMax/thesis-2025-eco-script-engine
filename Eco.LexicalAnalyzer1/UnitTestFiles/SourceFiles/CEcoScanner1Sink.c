/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoScanner1Sink
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoScanner1Sink
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoScanner1Sink.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLexicalAnalyzer1Events
 * </описание>
 *
 */
int16_t CEcoScanner1Sink_QueryInterface(/* in */ struct IEcoLexicalAnalyzer1Events* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLexicalAnalyzer1Events) ) {
        *ppv = &pCMe->m_pVTbIEvents;
        pCMe->m_pVTbIEvents->AddRef((IEcoLexicalAnalyzer1Events*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTbIEvents;
        pCMe->m_pVTbIEvents->AddRef((IEcoLexicalAnalyzer1Events*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoLexicalAnalyzer1Events
 * </описание>
 *
 */
uint32_t CEcoScanner1Sink_AddRef(/* in */ struct IEcoLexicalAnalyzer1Events* me) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;

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
 *   Функция Release для интерфейса IEcoLexicalAnalyzer1Events
 * </описание>
 *
 */
uint32_t CEcoScanner1Sink_Release(/* in */ struct IEcoLexicalAnalyzer1Events* me) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoScanner1Sink((IEcoLexicalAnalyzer1Events*)pCMe);
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
void CEcoScanner1Sink_OnInfoMessage(/* in */ struct IEcoLexicalAnalyzer1Events* me, /* in */ char_t* messsage) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;

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
 *   Функция OnProcessing
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoScanner1Sink_OnProcessing(/* in */ struct IEcoLexicalAnalyzer1Events* me, /* in */ IEcoFSM1State* pISourceState, /* in */ uchar_t eventSymbol, /* in */IEcoFSM1State* pITargeState) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;
    char_t pszStr[4] = {0};

    /* Проверка указателей */
    if (me == 0) {
        return;
    }
    if (eventSymbol == ' ') {
        pszStr[0] = 'S';
        pszStr[1] = 'P';
    }
    else if (eventSymbol == '\t') {
        pszStr[0] = 'H';
        pszStr[1] = 'T';
    }
    else if (eventSymbol == '\n') {
        pszStr[0] = 'C';
        pszStr[1] = 'R';
    }
    else if (eventSymbol == '\r') {
        pszStr[0] = 'L';
        pszStr[1] = 'F';
    }
    else  {
        pszStr[0] = eventSymbol;
    }

    pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "Processing: (%s) --- %s ---> %s", pISourceState->pVTbl->get_Name(pISourceState), pszStr, pITargeState->pVTbl->get_Name(pITargeState));

    return;
}

/*
 *
 * <сводка>
 *   Функция OnToken
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoScanner1Sink_OnToken(/* in */ struct IEcoLexicalAnalyzer1Events* me, /* in */ IEcoLexicalAnalyzer1Token* pIToken) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)me;

    /* Проверка указателей */
    if (me == 0) {
        return;
    }
    if (pIToken->pVTbl->IsEOF(pIToken)) {
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "Token: EOF");
    }
    else {
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "Token: %s", pIToken->pVTbl->get_Description(pIToken));
    }
    return;
}

/* Create Virtual Table */
IEcoLexicalAnalyzer1EventsVTbl g_xA5278D51F9BC42559E067CC2166A0FB9VTbl = {
    CEcoScanner1Sink_QueryInterface,
    CEcoScanner1Sink_AddRef,
    CEcoScanner1Sink_Release,
    CEcoScanner1Sink_OnInfoMessage,
    CEcoScanner1Sink_OnProcessing,
    CEcoScanner1Sink_OnToken
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
int16_t createCEcoScanner1Sink(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ IEcoLog1* pILog, /* out */ IEcoLexicalAnalyzer1Token** ppISubscriber) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoScanner1Sink* pCMe = 0;

    /* Проверка указателей */
    if (ppISubscriber == 0 || pIUnkSystem == 0) {
        return result;
    }


   /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

/* Проверка */
  /*  if (result != 0 && pISys == 0) {
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
    pCMe = (CEcoScanner1Sink*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoScanner1Sink));

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoScanner1Events */
    pCMe->m_pVTbIEvents = &g_xA5278D51F9BC42559E067CC2166A0FB9VTbl;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoScanner1Sink((IEcoLexicalAnalyzer1Token*)pCMe);
    }

    /* Инициализация данных */
    pCMe->m_pILog = pILog;

    /* Возврат указателя на интерфейс */
    *ppISubscriber = (IEcoLexicalAnalyzer1Token*)pCMe;

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
void deleteCEcoScanner1Sink(/* in */ IEcoLexicalAnalyzer1Token* pISubscriber) {
    CEcoScanner1Sink* pCMe = (CEcoScanner1Sink*)pISubscriber;
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
