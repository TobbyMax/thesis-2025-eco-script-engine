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
 *   Данный заголовок описывает реализацию компонента CEcoFSM1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_STATE_MACHINE_1_H__
#define __C_ECO_FINITE_STATE_MACHINE_1_H__

#include "IEcoFSM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoFSM1_2C4F446F {

    /* Таблица функций интерфейса IEcoFSM1 */
    IEcoFSM1VTbl* m_pVTblIFSM;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */

} CEcoFSM1_2C4F446F, *CEcoFSM1_2C4F446FPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoFSM1_2C4F446F(/*in*/ struct IEcoFSM1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFSM1_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoFSM1** ppIEcoFSM1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFSM1_2C4F446F(/* in */ IEcoFSM1* pIEcoFSM1);

#endif /* __C_ECO_FINITE_STATE_MACHINE_1_H__ */
