/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1Transition
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoFSM1Transition
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_FINITE_STATE_MACHINE_1_TRANSITION_H__
#define __C_ECO_FINITE_STATE_MACHINE_1_TRANSITION_H__

#include "IEcoFSM1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoString1.h"

typedef struct CEcoFSM1Transition_2C4F446F {

    /* Таблица функций интерфейса IEcoFSM1Transition */
    IEcoFSM1TransitionVTbl* m_pVTblITransition;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    IEcoList1* m_Transitions;
    char_t* m_Name;
    int16_t m_Id;
    void* m_Parametr;
    IEcoFSM1Event* m_Event;
    IEcoFSM1State* m_Source;
    IEcoFSM1State* m_Target;

} CEcoFSM1Transition_2C4F446F, *CEcoFSM1Transition_2C4F446FPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoFSM1Transition_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ int16_t Id, /* in */ IEcoFSM1Event* Event, /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target, /* out */ IEcoFSM1Transition** ppITransition);
/* Удаление */
void ECOCALLMETHOD deleteCEcoFSM1Transition_2C4F446F(/* in */ IEcoFSM1Transition* pITransition);

#endif /* __C_ECO_FINITE_STATE_MACHINE_1_TRANSITION_H__ */
