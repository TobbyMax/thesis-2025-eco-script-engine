/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSEM1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSEM1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SCRIPT_ENGINE_MANAGER_1_H__
#define __C_ECO_SCRIPT_ENGINE_MANAGER_1_H__

#include "IEcoSEM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSEM1_67CDDD73 {

    /* Таблица функций интерфейса IEcoSEM1 */
    IEcoSEM1VTbl* m_pVTblIEcoSEM1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoSE1ScriptContext* m_pIScriptContext;
    IEcoMap1* m_pIScriptEnginesByName;
    IEcoMap1* m_pIScriptEnginesByMimeType;
    IEcoMap1* m_pIScriptEnginesByExtension;

} CEcoSEM1_67CDDD73, *CEcoSEM1_67CDDD73Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSEM1_67CDDD73(/*in*/ IEcoSEM1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSEM1_67CDDD73(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSEM1Ptr_t* ppIEcoSEM1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSEM1_67CDDD73(/* in */ IEcoSEM1Ptr_t pIEcoSEM1);

#endif /* __C_ECO_SCRIPT_ENGINE_MANAGER_1_H__ */
