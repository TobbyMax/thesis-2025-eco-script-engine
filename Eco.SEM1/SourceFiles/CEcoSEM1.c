/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSEM1_67CDDD73
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSEM1_67CDDD73
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include <IdEcoMap1.h>
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoSEM1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSEM1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSEM1_67CDDD73_QueryInterface(/* in */ IEcoSEM1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSEM1) ) {
        *ppv = &pCMe->m_pVTblIEcoSEM1;
        pCMe->m_pVTblIEcoSEM1->AddRef((IEcoSEM1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoSEM1;
        pCMe->m_pVTblIEcoSEM1->AddRef((IEcoSEM1*)pCMe);
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoSEM1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_AddRef(/* in */ IEcoSEM1Ptr_t me) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
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
 *   Функция Release для интерфейса IEcoSEM1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_Release(/* in */ IEcoSEM1Ptr_t me) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSEM1_67CDDD73((IEcoSEM1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция set_Bindings
 * </сводка>
 *
 * <описание>
 *   Функция устанавливает ассоциированный массив для хранения привязок в глобальный скоуп
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_set_Bindings(IEcoSEM1Ptr_t* me, IEcoMap1* pBindingsMap) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)*me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || pBindingsMap == 0) {
        return ERR_ECO_POINTER;
    }

    /* Установка ассоциированного массива */
    pCMe->m_pIScriptContext->pVTbl->set_Bindings(pCMe->m_pIScriptContext, pBindingsMap, ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL);

    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция get_Bindings
 * </сводка>
 *
 * <описание>
 *   Функция возвращает ассоциированный массив для хранения привязок из глобального скоупа
 * </описание>
 *
 */
IEcoMap1* ECOCALLMETHOD CEcoSEM1_67CDDD73_get_Bindings(IEcoSEM1Ptr_t* me) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат ассоциированного массива */
    return pCMe->m_pIScriptContext->pVTbl->get_Bindings(pCMe->m_pIScriptContext, ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL);
}

/*
 *
 * <сводка>
 *   Функция Put
 * </сводка>
 *
 * <описание>
 *   Функция добавляет значение в глобальный скоуп
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_Put(IEcoSEM1Ptr_t* me, const char* key, void* value) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || key == 0) {
        return ERR_ECO_POINTER;
    }

    /* Добавление значения в глобальный скоуп */
    return pCMe->m_pIScriptContext->pVTbl->set_Attribute(pCMe->m_pIScriptContext, key, value,
                                                         ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL);
}

/*
 * <сводка>
 *   Функция Get
 * </сводка>
 *
 * <описание>
 *   Функция возвращает значение из глобального скоупа
 * </описание>
 *
 */
void* ECOCALLMETHOD CEcoSEM1_67CDDD73_Get(IEcoSEM1Ptr_t* me, const char* key) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || key == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат значения из глобального скоупа */
    return pCMe->m_pIScriptContext->pVTbl->get_Attribute(pCMe->m_pIScriptContext, key,
                                                         ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL);
}

/*
 *
 * <сводка>
 *   Функция GetEngineByName
 * </сводка>
 *
 * <описание>
 *   Функция возвращает движок скриптов по имени
 * </описание>
 *
 */
IEcoSE1* ECOCALLMETHOD CEcoSEM1_67CDDD73_GetEngineByName(IEcoSEM1Ptr_t* me, const char* shortName) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || shortName == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат движка скриптов по имени */
    return pCMe->m_pIScriptEnginesByName->pVTbl->Get(pCMe->m_pIScriptEnginesByName, shortName);
}

/*
 *
 * <сводка>
 *   Функция GetEngineByExtension
 * </сводка>
 *
 * <описание>
 *   Функция возвращает движок скриптов по расширению
 * </описание>
 *
 */
IEcoSE1* ECOCALLMETHOD CEcoSEM1_67CDDD73_GetEngineByExtension(IEcoSEM1Ptr_t* me, const char* extension) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || extension == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат движка скриптов по расширению */
    return pCMe->m_pIScriptEnginesByExtension->pVTbl->Get(pCMe->m_pIScriptEnginesByExtension, extension);
}

/*
 *
 * <сводка>
 *   Функция GetEngineByMimeType
 * </сводка>
 *
 * <описание>
 *   Функция возвращает движок скриптов по MIME типу
 * </описание>
 *
 */
IEcoSE1* ECOCALLMETHOD CEcoSEM1_67CDDD73_GetEngineByMimeType(IEcoSEM1Ptr_t* me, const char* mimeType) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || mimeType == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат движка скриптов по MIME типу */
    return pCMe->m_pIScriptEnginesByMimeType->pVTbl->Get(pCMe->m_pIScriptEnginesByMimeType, mimeType);
}

/*
 *
 * <сводка>
 *   Функция RegisterEngineName
 * </сводка>
 *
 * <описание>
 *   Функция регистрирует движок скриптов по имени
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_RegisterEngineName(IEcoSEM1Ptr_t* me, const char* shortName, IEcoSE1* pEngine) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || shortName == 0 || pEngine == 0) {
        return ERR_ECO_POINTER;
    }

    pEngine->pVTbl->AddRef(pEngine); /* Увеличение счетчика ссылок на движок скриптов */
    pEngine->pVTbl->set_Context(pEngine, pCMe->m_pIScriptContext); /* Установка контекста движка скриптов */

    /* Регистрация движка скриптов по имени */
    return pCMe->m_pIScriptEnginesByName->pVTbl->Set(pCMe->m_pIScriptEnginesByName, shortName, pEngine);
}

/*
 *
 * <сводка>
 *   Функция RegisterEngineExtension
 * </сводка>
 *
 * <описание>
 *   Функция регистрирует движок скриптов по расширению
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_RegisterEngineExtension(IEcoSEM1Ptr_t* me, const char* extension, IEcoSE1* pEngine) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || extension == 0 || pEngine == 0) {
        return ERR_ECO_POINTER;
    }

    pEngine->pVTbl->AddRef(pEngine); /* Увеличение счетчика ссылок на движок скриптов */
    pEngine->pVTbl->set_Context(pEngine, pCMe->m_pIScriptContext); /* Установка контекста движка скриптов */

    /* Регистрация движка скриптов по расширению */
    return pCMe->m_pIScriptEnginesByExtension->pVTbl->Set(pCMe->m_pIScriptEnginesByExtension, extension, pEngine);
}

/*
 *
 * <сводка>
 *   Функция RegisterEngineMimeType
 * </сводка>
 *
 * <описание>
 *   Функция регистрирует движок скриптов по MIME типу
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSEM1_67CDDD73_RegisterEngineMimeType(IEcoSEM1Ptr_t* me, const char* mimeType, IEcoSE1* pEngine) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0 || mimeType == 0 || pEngine == 0) {
        return ERR_ECO_POINTER;
    }

    pEngine->pVTbl->AddRef(pEngine); /* Увеличение счетчика ссылок на движок скриптов */
    pEngine->pVTbl->set_Context(pEngine, pCMe->m_pIScriptContext); /* Установка контекста движка скриптов */

    /* Регистрация движка скриптов по MIME типу */
    return pCMe->m_pIScriptEnginesByMimeType->pVTbl->Set(pCMe->m_pIScriptEnginesByMimeType, mimeType, pEngine);
}

IEcoList1* ECOCALLMETHOD CEcoSEM1_67CDDD73_GetEngines(IEcoSEM1Ptr_t* me) {
    CEcoSEM1_67CDDD73 *pCMe = (CEcoSEM1_67CDDD73 *) *me;

    /* Проверка указателей */
    if (me == 0 || pCMe == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    /* Возврат списка движков скриптов */
    return pCMe->m_pIScriptEnginesByName->pVTbl->ToValueList(pCMe->m_pIScriptEnginesByName);
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
int16_t ECOCALLMETHOD initCEcoSEM1_67CDDD73(/*in*/ IEcoSEM1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IEcoSEM1 */
IEcoSEM1VTbl g_xE6E96975768648C3B0755143CE324AACVTbl_67CDDD73 = {
    CEcoSEM1_67CDDD73_QueryInterface,
    CEcoSEM1_67CDDD73_AddRef,
    CEcoSEM1_67CDDD73_Release,
    CEcoSEM1_67CDDD73_set_Bindings,
    CEcoSEM1_67CDDD73_get_Bindings,
    CEcoSEM1_67CDDD73_Put,
    CEcoSEM1_67CDDD73_Get,
    CEcoSEM1_67CDDD73_GetEngineByName,
    CEcoSEM1_67CDDD73_GetEngineByExtension,
    CEcoSEM1_67CDDD73_GetEngineByMimeType,
    CEcoSEM1_67CDDD73_RegisterEngineName,
    CEcoSEM1_67CDDD73_RegisterEngineExtension,
    CEcoSEM1_67CDDD73_RegisterEngineMimeType,
    CEcoSEM1_67CDDD73_GetEngines,
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
int16_t ECOCALLMETHOD createCEcoSEM1_67CDDD73(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSEM1Ptr_t* ppIEcoSEM1) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSEM1_67CDDD73* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoSEM1 == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }
	
	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoSEM1_67CDDD73*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSEM1_67CDDD73));
    if (pCMe == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }
	
    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoSEM1 */
    pCMe->m_pVTblIEcoSEM1 = &g_xE6E96975768648C3B0755143CE324AACVTbl_67CDDD73;

    /* Инициализация данных */
    pCMe->m_pIScriptEnginesByExtension = 0;
    pCMe->m_pIScriptEnginesByName = 0;
    pCMe->m_pIScriptEnginesByMimeType = 0;
    pCMe->m_pIScriptContext = 0;


    /* Получение интерфейса для работы с ассоциированным массивом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pCMe->m_pIScriptEnginesByExtension);
    if (result != 0 || pCMe->m_pIScriptEnginesByExtension == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSEM1_67CDDD73((IEcoSEM1*)pCMe);
    }
    pCMe->m_pIScriptEnginesByExtension->pVTbl->InitByType(pCMe->m_pIScriptEnginesByExtension, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);

    /* Получение интерфейса для работы с ассоциированным массивом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pCMe->m_pIScriptEnginesByName);
    if (result != 0 || pCMe->m_pIScriptEnginesByName == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSEM1_67CDDD73((IEcoSEM1*)pCMe);
    }
    pCMe->m_pIScriptEnginesByName->pVTbl->InitByType(pCMe->m_pIScriptEnginesByName, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);

    /* Получение интерфейса для работы с ассоциированным массивом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pCMe->m_pIScriptEnginesByMimeType);
    if (result != 0 || pCMe->m_pIScriptEnginesByName == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSEM1_67CDDD73((IEcoSEM1*)pCMe);
    }
    pCMe->m_pIScriptEnginesByMimeType->pVTbl->InitByType(pCMe->m_pIScriptEnginesByMimeType, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);

    /* Получение интерфейса для работы с контекстом скриптов */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoSE1ScriptContext,(void**)&pCMe->m_pIScriptContext);
    if (result != 0 || pCMe->m_pIScriptContext == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSEM1_67CDDD73((IEcoSEM1*)pCMe);
    }

    /* Возврат указателя на интерфейс */
    *ppIEcoSEM1 = (IEcoSEM1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
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
void ECOCALLMETHOD deleteCEcoSEM1_67CDDD73(/* in */ IEcoSEM1Ptr_t pIEcoSEM1) {
    CEcoSEM1_67CDDD73* pCMe = (CEcoSEM1_67CDDD73*)pIEcoSEM1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoSEM1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIScriptContext != 0 ) {
            pCMe->m_pIScriptContext->pVTbl->Release(pCMe->m_pIScriptContext);
        }
        if (pCMe->m_pIScriptEnginesByName != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_pIScriptEnginesByName);
        }
        if (pCMe->m_pIScriptEnginesByExtension != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_pIScriptEnginesByExtension);
        }
        if (pCMe->m_pIScriptEnginesByMimeType != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_pIScriptEnginesByMimeType);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
