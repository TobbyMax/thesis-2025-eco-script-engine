/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1State
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFSM1State
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_STATE_MACHINE_1_STATE_H__
#define __C_ECO_FINITE_STATE_MACHINE_1_STATE_H__

#include "IEcoFSM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoFSM1State_2C4F446F {

    /* Таблица функций интерфейса IEcoFSM1State */
    IEcoFSM1StateVTbl* m_pVTblIState;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    char_t* m_Name;
    int16_t m_Id;
    bool_t m_Initial;
    bool_t m_Final;
    bool_t m_Trap;
    void* m_Parametr;

} CEcoFSM1State_2C4F446F, *CEcoFSM1State_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFSM1State_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* in */ int16_t Id, /* out */ IEcoFSM1State** ppIState);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFSM1State_2C4F446F(/* in */ IEcoFSM1State* pIState);

#endif /* __C_ECO_FINITE_STATE_MACHINE_1_STATE_H__ */
