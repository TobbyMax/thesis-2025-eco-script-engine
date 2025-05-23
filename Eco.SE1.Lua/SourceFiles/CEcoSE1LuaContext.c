/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSE1LuaContext_8E62028C
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSE1LuaContext_8E62028C
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
#include "CEcoSE1LuaContext.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSE1LuaContext
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_QueryInterface(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSE1ScriptContext) ) {
        *ppv = &pCMe->m_pVTblIEcoSE1ScriptContext;
        pCMe->m_pVTblIEcoSE1ScriptContext->pVTbl->AddRef((IEcoSE1ScriptContext*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoSE1ScriptContext;
        pCMe->m_pVTblIEcoSE1ScriptContext->pVTbl->AddRef((IEcoSE1ScriptContext*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoSE1LuaContext
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_AddRef(/* in */ IEcoSE1ScriptContextPtr_t me) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;

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
 *   Функция Release для интерфейса IEcoSE1LuaContext
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_Release(/* in */ IEcoSE1ScriptContextPtr_t me) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSE1LuaContext_8E62028C((IEcoSE1ScriptContext*)pCMe);
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
 *   Функция устанавливает ассоциированный массив для хранения наборов атрибутов по id scope.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_set_Bindings(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ IEcoMap1* pBindings, /* in */ int32_t scope) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;
    IEcoMap1* pIBindings = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0 || scope < 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pIBindings);
    if (result != 0 || pIBindings == 0) {
        return ERR_ECO_POINTER;
    }
    pIBindings->pVTbl->InitByType(pCMe->m_pIBindingsMap, ECO_COMPARATOR_1_INTEGER_32_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);
    result = pCMe->m_pIBindingsMap->pVTbl->Set(pCMe->m_pIBindingsMap, scope, pIBindings);
    if (result != 0) {
        return ERR_ECO_POINTER;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция get_Bindings
 * </сводка>
 *
 * <описание>
 *   Функция возвращает ассоциированный массив для хранения наборов атрибутов по id scope.
 * </описание>
 *
 */
static IEcoMap1* ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_get_Bindings(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ int32_t scope) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;

    /* Проверка указателей */
    if (me == 0 || scope < 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_pIBindingsMap->pVTbl->Get(pCMe->m_pIBindingsMap, scope);
}

/*
 *
 * <сводка>
 *   Функция set_Attribute
 * </сводка>
 *
 * <описание>
 *   Функция устанавливает значение атрибута в указанном scope.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_set_Attribute(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ void* value, /* in */ int32_t scope) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;
    IEcoMap1* pIBinding = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0 || name == 0 || scope < 0) {
        return ERR_ECO_POINTER;
    }

    pIBinding = pCMe->m_pIBindingsMap->pVTbl->Get(pCMe->m_pIBindingsMap, scope);
    if (pIBinding == 0) {
        return ERR_ECO_POINTER;
    }

    result = pIBinding->pVTbl->Set(pIBinding, name, value);
    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Attribute
 * </сводка>
 *
 * <описание>
 *   Функция возвращает значение атрибута в указанном scope.
 * </описание>
 *
 */
static void* ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_get_Attribute(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ int32_t scope) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;
    IEcoMap1* pIBinding = 0;

    /* Проверка указателей */
    if (me == 0 || name == 0 || scope < 0) {
        return 0;
    }

    pIBinding = pCMe->m_pIBindingsMap->pVTbl->Get(pCMe->m_pIBindingsMap, scope);
    if (pIBinding == 0) {
        return 0;
    }

    return pIBinding->pVTbl->Get(pIBinding, name);
}

/*
 *
 * <сводка>
 *   Функция RemoveAttribute
 * </сводка>
 *
 * <описание>
 *   Функция удаляет атрибут в указанном scope.
 * </описание>
 *
 */
static void* ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_RemoveAttribute(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name, /* in */ int32_t scope) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;
    IEcoMap1* pIBinding = 0;
    void* value = 0;

    /* Проверка указателей */
    if (me == 0 || name == 0 || scope < 0) {
        return 0;
    }

    pIBinding = pCMe->m_pIBindingsMap->pVTbl->Get(pCMe->m_pIBindingsMap, scope);
    if (pIBinding == 0) {
        return 0;
    }
    value = pIBinding->pVTbl->Get(pIBinding, name);
    if (value == 0) {
        return 0;
    }
    pIBinding->pVTbl->Remove(pIBinding, name);

    return value;
}

/*
 *
 * <сводка>
 *   Функция GetAttributeInAnyScope
 * </сводка>
 *
 * <описание>
 *   Функция возвращает значение атрибута в любом scope.
 * </описание>
 *
 */
IEcoMap1IteratorPtr_t (ECOCALLMETHOD *Get_IterBegin)(/* in */ IEcoMap1Ptr_t me);
IEcoMap1IteratorPtr_t (ECOCALLMETHOD *Get_IterEnd)(/* in */ IEcoMap1Ptr_t me);
IEcoMap1IteratorPtr_t (ECOCALLMETHOD *Get_IterByKey)(/* in */ IEcoMap1Ptr_t me, /* in */ voidptr_t key);

static void* ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_GetAttributeInAnyScope(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name) {
    CEcoSE1LuaContext_8E62028C *pCMe = (CEcoSE1LuaContext_8E62028C *) me;
    IEcoMap1* pIBindings = 0;
    IEcoMap1Iterator* pIMapIter = 0;
    IEcoMap1* pIBindingsMap = 0;
    int32_t scope = 0;
    void* value = 0;

    /* Проверка указателей */
    if (me == 0 || name == 0) {
        return 0;
    }
    pIBindingsMap = pCMe->m_pIBindingsMap;
    if (pIBindingsMap == 0) {
        return 0;
    }

    for (pIMapIter = pIBindingsMap->pVTbl->Get_IterBegin(pIBindings); pIMapIter->pVTbl->Get_Key(pIMapIter); pIMapIter->pVTbl->GoToNext(pIMapIter)) {
        scope = (int32_t)pIMapIter->pVTbl->Get_Key(pIMapIter);
        pIBindings = (IEcoMap1*)pIMapIter->pVTbl->Get_Value(pIMapIter);
        value = pIBindings->pVTbl->Get(pIBindings, name);
        if (value != 0) {
            return value;
        }
    }

    return 0; /* ERR_ECO_NOTFOUND */
}

/*
 *
 * <сводка>
 *   Функция GetScopeByAttribute
 * </сводка>
 *
 * <описание>
 *   Функция возвращает scope, в котором находится атрибут.
 * </описание>
 *
 */
static int32_t ECOCALLMETHOD CEcoSE1LuaContext_8E62028C_GetScopeByAttribute(/* in */ IEcoSE1ScriptContextPtr_t me, /* in */ const char* name) {
    CEcoSE1LuaContext_8E62028C *pCMe = (CEcoSE1LuaContext_8E62028C *) me;
    IEcoMap1* pIBindings = 0;
    IEcoMap1Iterator* pIMapIter = 0;
    IEcoMap1* pIBindingsMap = 0;
    int32_t scope = 0;

    /* Проверка указателей */
    if (me == 0 || name == 0) {
        return -1; /* ERR_ECO_POINTER */
    }
    pIBindingsMap = pCMe->m_pIBindingsMap;
    if (pIBindingsMap == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    for (pIMapIter = pIBindingsMap->pVTbl->Get_IterBegin(pIBindings); pIMapIter->pVTbl->Get_Key(pIMapIter); pIMapIter->pVTbl->GoToNext(pIMapIter)) {
        scope = (int32_t)pIMapIter->pVTbl->Get_Key(pIMapIter);
        pIBindings = (IEcoMap1*)pIMapIter->pVTbl->Get_Value(pIMapIter);
        if (pIBindings->pVTbl->Contains(pIBindings, name)) {
            return scope;
        }
    }

    return -1; /* ERR_ECO_NOTFOUND */
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
int16_t ECOCALLMETHOD initCEcoSE1LuaContext_8E62028C(/*in*/ IEcoSE1ScriptContextPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)me;
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

/* Create Virtual Table IEcoSE1LuaContext */
IEcoSE1ScriptContextVTbl g_x3BBB11F275CF432AA54845F3DBFCAAB6VTbl_8E62028C = {
    CEcoSE1LuaContext_8E62028C_QueryInterface,
    CEcoSE1LuaContext_8E62028C_AddRef,
    CEcoSE1LuaContext_8E62028C_Release,
    CEcoSE1LuaContext_8E62028C_set_Bindings,
    CEcoSE1LuaContext_8E62028C_get_Bindings,
    CEcoSE1LuaContext_8E62028C_set_Attribute,
    CEcoSE1LuaContext_8E62028C_get_Attribute,
    CEcoSE1LuaContext_8E62028C_RemoveAttribute,
    CEcoSE1LuaContext_8E62028C_GetAttributeInAnyScope,
    CEcoSE1LuaContext_8E62028C_GetScopeByAttribute
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
int16_t ECOCALLMETHOD createCEcoSE1LuaContext_8E62028C(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSE1ScriptContextPtr_t* ppIEcoSE1LuaContext) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSE1LuaContext_8E62028C* pCMe = 0;
    IEcoMap1* pIGlobalBindings = 0;
    IEcoMap1* pIEngineBindings = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoSE1LuaContext == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoSE1LuaContext_8E62028C*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSE1LuaContext_8E62028C));
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

    /* Создание таблицы функций интерфейса IEcoSE1LuaContext */
    pCMe->m_pVTblIEcoSE1ScriptContext = &g_x3BBB11F275CF432AA54845F3DBFCAAB6VTbl_8E62028C;

    /* Инициализация данных */
    pCMe->m_Id = 0;
    pCMe->m_pIBindingsMap = 0;

    /* Получение интерфейса для работы с ассоциированным массивом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pCMe->m_pIBindingsMap);
    if (result != 0 || pCMe->m_pIBindingsMap == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoSE1LuaContext_8E62028C((IEcoSE1ScriptContext*)pCMe);
    }
    pCMe->m_pIBindingsMap->pVTbl->InitByType(pCMe->m_pIBindingsMap, ECO_COMPARATOR_1_INTEGER_32_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);

    /* Создание bindings для engine scope */
    result = pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pIEngineBindings);
    pCMe->m_pIBindingsMap->pVTbl->InitByType(pCMe->m_pIBindingsMap, ECO_COMPARATOR_1_INTEGER_32_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);
    result = pCMe->m_pIBindingsMap->pVTbl->Set(pCMe->m_pIBindingsMap, ECO_SCRIPT_ENGINE_1_SCOPE_ENGINE, pIEngineBindings);
    /* Создание bindings для global scope */
    result = pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pIGlobalBindings);
    pCMe->m_pIBindingsMap->pVTbl->InitByType(pCMe->m_pIBindingsMap, ECO_COMPARATOR_1_INTEGER_32_TYPE, ECO_COMPARATOR_1_OBJECT_TYPE);
    result = pCMe->m_pIBindingsMap->pVTbl->Set(pCMe->m_pIBindingsMap, ECO_SCRIPT_ENGINE_1_SCOPE_GLOBAL, pIGlobalBindings);

    /* Возврат указателя на интерфейс */
    *ppIEcoSE1LuaContext = (IEcoSE1ScriptContext*)pCMe;

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
void ECOCALLMETHOD deleteCEcoSE1LuaContext_8E62028C(/* in */ IEcoSE1ScriptContextPtr_t pIEcoSE1LuaContext) {
    CEcoSE1LuaContext_8E62028C* pCMe = (CEcoSE1LuaContext_8E62028C*)pIEcoSE1LuaContext;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoSE1LuaContext != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pIBindingsMap != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_pIBindingsMap);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
