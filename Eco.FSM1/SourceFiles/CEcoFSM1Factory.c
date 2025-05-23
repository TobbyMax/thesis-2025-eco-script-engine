/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEco.FSM1Factory
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию фабрики для компонента
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoFSM1.h"
#include "CEcoFSM1Factory.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция возвращает указатель на интерфейс
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_QueryInterface(IEcoComponentFactoryPtr_t me, const UGUID* riid, voidptr_t* ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory) ) {
        *ppv = me;
    }
    else {
        *ppv = 0;
        return -1;
    }
    ((IEcoUnknown*)(*ppv))->pVTbl->AddRef((IEcoUnknown*)*ppv);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_AddRef(/* in */ IEcoComponentFactoryPtr_t me) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;

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
 *   Функция уменьшает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_Release(/* in */ IEcoComponentFactoryPtr_t me) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoFSM1Factory(&pCMe->m_VtblICF);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализирует компонент с параметрами
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_Init(/* in */ IEcoComponentFactoryPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ voidptr_t pv) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Инициализация компонента */
    result = pCMe->m_pInitInstance(pv, pIUnkSystem);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Alloc
 * </сводка>
 *
 * <описание>
 *   Функция создает компонент
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_Alloc(/* in */ IEcoComponentFactoryPtr_t me, /* in */ IEcoUnknownPtr_t pISystem, /* in */ IEcoUnknownPtr_t pIUnknownOuter, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;
    IEcoUnknown* pIUnk = 0;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Агрегирование при условии если IID это IID_IEcoUnknown */
    if ( ( pIUnknownOuter != 0 ) && !IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        /* не поддерживает агрегирование */
        return -1;
    }

    /* Создание компонента */
    result = pCMe->m_pInstance(pISystem, pIUnknownOuter, (voidptr_t*)&pIUnk);
    if ( result != 0 || pIUnk == 0) {
        return -1;
    }

    /* Получение указателя на интерфейс */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, riid, ppv);

    /* Уменьшение ссылки запрошенной Фабрикой компонентов */
    pIUnk->pVTbl->Release(pIUnk);

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_get_Name(/* in */ IEcoComponentFactoryPtr_t me) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Version
 * </сводка>
 *
 * <описание>
 *   Функция возвращает версию компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_get_Version(/* in */ IEcoComponentFactoryPtr_t me) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Version;
}

/*
 *
 * <сводка>
 *   Функция get_Manufacturer
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование производителя компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFSM1_2C4F446FFactory_get_Manufacturer(/* in */ IEcoComponentFactoryPtr_t me) {
    CEcoFSM1_2C4F446FFactory* pCMe = (CEcoFSM1_2C4F446FFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_x5E7C610CB846447DB59A3C5A2C4F446FFactoryVTbl = {
    CEcoFSM1_2C4F446FFactory_QueryInterface,
    CEcoFSM1_2C4F446FFactory_AddRef,
    CEcoFSM1_2C4F446FFactory_Release,
    CEcoFSM1_2C4F446FFactory_Alloc,
    CEcoFSM1_2C4F446FFactory_Init,
    CEcoFSM1_2C4F446FFactory_get_Name,
    CEcoFSM1_2C4F446FFactory_get_Version,
    CEcoFSM1_2C4F446FFactory_get_Manufacturer
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция 
 * </описание>
 *
 */
CEcoFSM1_2C4F446FFactory g_x5E7C610CB846447DB59A3C5A2C4F446FFactory = {
    &g_x5E7C610CB846447DB59A3C5A2C4F446FFactoryVTbl,
    0,
    (CreateInstance)createCEcoFSM1_2C4F446F,
    (InitInstance)initCEcoFSM1_2C4F446F,
    "Eco.FSM\0",
    "1.0.0.0\0",
    "PeerF\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_x5E7C610CB846447DB59A3C5A2C4F446FFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_5E7C610CB846447DB59A3C5A2C4F446F = (IEcoComponentFactory*)&g_x5E7C610CB846447DB59A3C5A2C4F446FFactory;
#endif