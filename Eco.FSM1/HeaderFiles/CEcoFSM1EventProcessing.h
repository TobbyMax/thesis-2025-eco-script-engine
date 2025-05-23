/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1EventProcessing
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFSM1EventProcessing
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_STATE_MACHINE_1_EVENT_PROCESSING_H__
#define __C_ECO_FINITE_STATE_MACHINE_1_EVENT_PROCESSING_H__

#include "IEcoFSM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoString1.h"

typedef struct CEcoFSM1EventProcessing_2C4F446F {

    /* Таблица функций интерфейса IEcoFSM1EventProcessing */
    IEcoFSM1EventProcessingVTbl* m_pVTblIEventProcessing;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    IEcoFSM1StateMachine* m_pIStateMachine;
    IEcoFSM1State* m_pICurrentState;
    IEcoFSM1State* m_pIInitialState;
    IEcoFSM1State* m_pIFinalState;
    int16_t m_Id;
    void* m_Parametr;
    IEcoFL1SymbolSet* m_pICurrentWord;

} CEcoFSM1EventProcessing_2C4F446F, *CEcoFSM1EventProcessing_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFSM1EventProcessing_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ IEcoFSM1StateMachine* StateMachine, /* out */ IEcoFSM1EventProcessing** ppIEventProcessing);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFSM1EventProcessing_2C4F446F(/* in */ IEcoFSM1EventProcessing* pIEventProcessing);

#endif /* __C_ECO_FINITE_STATE_MACHINE_1_EVENT_PROCESSING_H__ */
