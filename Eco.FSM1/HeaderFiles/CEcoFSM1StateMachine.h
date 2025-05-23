/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1StateMachine
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFSM1StateMachine
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_STATE_MACHINE_1_STATE_MACHINE_H__
#define __C_ECO_FINITE_STATE_MACHINE_1_STATE_MACHINE_H__

#include "IEcoFSM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoList1.h"
#include "IdEcoString1.h"
#include "IdEcoData1.h"

typedef struct CEcoFSM1StateMachine_2C4F446F {

    /* Таблица функций интерфейса IEcoFSM1StateMachine */
    IEcoFSM1StateMachineVTbl* m_pVTblIStateMachine;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейсная шина */
    IEcoInterfaceBus1* m_pIBus;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Интерфейсы для работы с управляющей таблицей */
    IEcoData1* m_pIData;
    IEcoData1Table* m_TransitionTable;

    /* Данные экземпляра */
    IEcoList1* m_States;
    IEcoList1* m_Transitions;
    IEcoList1* m_Events;
    IEcoFL1Alphabet* m_Alphabet;
    char_t* m_Name;
    int16_t m_Id;

} CEcoFSM1StateMachine_2C4F446F, *CEcoFSM1StateMachine_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFSM1StateMachine_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* out */ IEcoFSM1StateMachine** ppIStateMachine);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFSM1StateMachine_2C4F446F(/* in */ IEcoFSM1StateMachine* pITable);

#endif /* __C_ECO_FINITE_STATE_MACHINE_1_STATE_MACHINE_H__ */
