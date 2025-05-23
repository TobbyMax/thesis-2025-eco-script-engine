/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoFSM1StateMachine
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoFSM1StateMachine
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include <IEcoFL1.h>
#include <CEcoFL1Alphabet.h>
#include "CEcoFSM1StateMachine.h"
#include "CEcoFSM1State.h"
#include "CEcoFSM1Event.h"
#include "CEcoFSM1Transition.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoFSM1StateMachine
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_QueryInterface(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoFSM1StateMachine) ) {
        *ppv = &pCMe->m_pVTblIStateMachine;
        pCMe->m_pVTblIStateMachine->AddRef((IEcoFSM1StateMachine*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIStateMachine;
        pCMe->m_pVTblIStateMachine->AddRef((IEcoFSM1StateMachine*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoFSM1StateMachine
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddRef(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

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
 *   Функция Release для интерфейса IEcoFSM1StateMachine
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_Release(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает имя конечного автомата
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_Name(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Id
 * </сводка>
 *
 * <описание>
 *   Функция возвращает идентификатор
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_Id(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Id;
}

/*
 *
 * <сводка>
 *   Функция get_Alphabet
 * </сводка>
 *
 * <описание>
 *   Функция возвращает алфавит
 * </описание>
 *
 */
IEcoFL1Alphabet* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_Alphabet(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Alphabet;
}

/*
 *
 * <сводка>
 *   Функция AddState
 * </сводка>
 *
 * <описание>
 *   Функция создает новое состояние
 * </описание>
 *
 */
IEcoFSM1State* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddState(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ char_t* Name) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    int16_t result = 0;
    int16_t nStateId = 0;
    IEcoFSM1State* pIState = 0;

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    /* Определение идентификатора нового состояния */
    nStateId = pCMe->m_States->pVTbl->Count(pCMe->m_States);
    result = createCEcoFSM1State_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, nStateId, &pIState);
    if (result != 0 || pIState == 0) {
        /* Возврат в случае ошибки */
        return 0;
    }
    /* Добавление состояния в список */
    pCMe->m_States->pVTbl->Add(pCMe->m_States, pIState);

    return pIState;
}

/*
 *
 * <сводка>
 *   Функция get_States
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список состояний
 * </описание>
 *
 */
IEcoList1* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_States(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_States;
}

/*
 *
 * <сводка>
 *   Функция AddEvent
 * </сводка>
 *
 * <описание>
 *   Функция создает новое событие
 * </описание>
 *
 */
IEcoFSM1Event* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddEvent(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ char_t* Name, /* in */ int16_t Id, /* in */ bool_t isNull) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    int16_t result = 0;
    int16_t nEventId = 0;
    uint32_t index = 0;
    IEcoFSM1Event* pIEvent = 0;

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    /* Определение идентификатора нового события */
    nEventId = pCMe->m_Events->pVTbl->Count(pCMe->m_Events);

    for (index = 0; index < nEventId; index++) {
        pIEvent = (IEcoFSM1Event*)pCMe->m_Events->pVTbl->Item(pCMe->m_Events, index);
        if (pIEvent->pVTbl->get_Id(pIEvent) == Id) {
            break;
        }
        pIEvent = 0;
    }

    if (Id != 0) {
        nEventId = Id;
    }

    if (pIEvent == 0) {
        result = createCEcoFSM1Event_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, nEventId, isNull, &pIEvent);
        if (result != 0 || pIEvent == 0) {
            /* Возврат в случае ошибки */
            return 0;
        }
        /* Добавление событие в список */
        pCMe->m_Events->pVTbl->Add(pCMe->m_Events, pIEvent);
    }

    return pIEvent;
}

/*
 *
 * <сводка>
 *   Функция get_Events
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список событий
 * </описание>
 *
 */
IEcoList1* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_Events(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Events;
}

/*
 *
 * <сводка>
 *   Функция AddTransition
 * </сводка>
 *
 * <описание>
 *   Функция добавляет возвращает интерфейс перехода
 * </описание>
 *
 */
IEcoFSM1Transition* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddTransition(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ IEcoFSM1Event* Event, /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    int16_t result = 0;
    int16_t nTransitionId = 0;
    IEcoFSM1Transition* pITransition = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    /* Определение идентификатора нового состояния */
    nTransitionId = pCMe->m_Transitions->pVTbl->Count(pCMe->m_Transitions);
    result = createCEcoFSM1Transition_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, nTransitionId, Event, Source, Target, &pITransition);
    if (result != 0 || pITransition == 0) {
        /* Возврат в случае ошибки */
        return 0;
    }
    /* Добавление состояния в список */
    pCMe->m_Transitions->pVTbl->Add(pCMe->m_Transitions, pITransition);

    return pITransition;
}

/*
 *
 * <сводка>
 *   Функция get_Transitions
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список переходов
 * </описание>
 *
 */
IEcoList1* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_Transitions(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Transitions;
}

/*
 *
 * <сводка>
 *   Функция get_TransitionTable
 * </сводка>
 *
 * <описание>
 *   Функция возвращает список состояний
 * </описание>
 *
 */
IEcoData1Table* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_get_TransitionTable(/* in */ IEcoFSM1StateMachinePtr_t me) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    IEcoData1Column* pIColumn = 0;
    IEcoData1Row* pIRow = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1State* pISourceState = 0;
    IEcoFSM1State* pITargetState = 0;
    IEcoFSM1Event* pIEvent = 0;
    IEcoList1* pIColumns = 0;
    uint32_t indexEvent = 0;
    uint32_t indexState = 0;
    uint32_t indexTransition = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    /* При повторном вызове, добавляются те же события - необходимо исправить ошибку */
    pIColumns = pCMe->m_TransitionTable->pVTbl->get_Columns(pCMe->m_TransitionTable);
    if (pIColumns->pVTbl->Count(pIColumns) > 0 ) {
        /* временная заплатка */
        return pCMe->m_TransitionTable;
    }

    /* Проход по событиям для формирования столбцов */
    for( indexEvent = 0; indexEvent < pCMe->m_Events->pVTbl->Count(pCMe->m_Events); indexEvent++) {
        pIEvent = (IEcoFSM1Event*)pCMe->m_Events->pVTbl->Item(pCMe->m_Events, indexEvent);
        /* создаем столбец тип-строка */
        pIColumn = pCMe->m_TransitionTable->pVTbl->CreateColumn(pCMe->m_TransitionTable);
        pIColumn->pVTbl->set_Name(pIColumn, pIEvent->pVTbl->get_Name(pIEvent));
        /* надо добавить тип объекта для функции перехода*/
        //pIColumn->set_DataType(pIColumn, ECO_DATA_1_TYPE_OBJECT);
        pIColumn->pVTbl->set_DataType(pIColumn, ECO_DATA_1_TYPE_STRING);
    }

    /* Проход по состояниям для формирования строк */
    for( indexState = 0; indexState < pCMe->m_States->pVTbl->Count(pCMe->m_States); indexState++) {
        pIState = (IEcoFSM1State*)pCMe->m_States->pVTbl->Item(pCMe->m_States, indexState);
        /* создаем запись тип-строка */
        pIRow = pCMe->m_TransitionTable->pVTbl->AddRow(pCMe->m_TransitionTable);
        /* Проход по переходам для заполнения строк соответствующего событию столбца */
        for( indexTransition = 0; indexTransition < pCMe->m_Transitions->pVTbl->Count(pCMe->m_Transitions); indexTransition++) {
            pITransition = (IEcoFSM1Transition*)pCMe->m_Transitions->pVTbl->Item(pCMe->m_Transitions, indexTransition);
            pISourceState = pITransition->pVTbl->get_Source(pITransition);
            if (pIState->pVTbl->get_Id(pIState) == pISourceState->pVTbl->get_Id(pISourceState)) {
                pITargetState = pITransition->pVTbl->get_Target(pITransition);
                pIEvent = pITransition->pVTbl->get_Event(pITransition);
                /* вместо имени указатель на состояние */
                //pIRow->set_ItemByName(pIRow, pITempEvent->get_Name(pITempEvent), pITempState);
                pIRow->pVTbl->set_ItemByName(pIRow, pIEvent->pVTbl->get_Name(pIEvent), pITargetState->pVTbl->get_Name(pITargetState));
            }
        }
    }

    return pCMe->m_TransitionTable;
}

/*
 *
 * <сводка>
 *   Функция AddTransitionById
 * </сводка>
 *
 * <описание>
 *   Функция добавляет возвращает интерфейс перехода
 * </описание>
 *
 */
IEcoFSM1Transition* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddTransitionById(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ int16_t EventId, /* in */ int16_t SourceStateId, /* in */ int16_t TargetStateId) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    int16_t result = 0;
    int16_t nTransitionId = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1State* pISourceState = 0;
    IEcoFSM1State* pITargetState = 0;
    IEcoFSM1Event* pIEvent = 0;
    uint32_t indexEvent = 0;
    uint32_t indexState = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    /* Определение идентификатора нового состояния */
    nTransitionId = pCMe->m_Transitions->pVTbl->Count(pCMe->m_Transitions);

    /* Поиск события по идентификатору */
    for( indexEvent = 0; indexEvent < pCMe->m_Events->pVTbl->Count(pCMe->m_Events); indexEvent++) {
        pIEvent = (IEcoFSM1Event*)pCMe->m_Events->pVTbl->Item(pCMe->m_Events, indexEvent);
        if ( pIEvent->pVTbl->get_Id(pIEvent) == EventId) {
            break;
        }
        pIEvent = 0;
    }

    /* Поиск начального и конечного состояний по идентификатору */
    for( indexState = 0; indexState < pCMe->m_States->pVTbl->Count(pCMe->m_States); indexState++) {
        pIState = (IEcoFSM1State*)pCMe->m_States->pVTbl->Item(pCMe->m_States, indexState);
        if ( pIState->pVTbl->get_Id(pIState) == SourceStateId) {
            pISourceState = pIState;
        }
        if ( pIState->pVTbl->get_Id(pIState) == TargetStateId) {
            pITargetState = pIState;
        }
    }

    result = createCEcoFSM1Transition_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, nTransitionId, pIEvent, pISourceState, pITargetState, &pITransition);
    if (result != 0 || pITransition == 0) {
        /* Возврат в случае ошибки */
        return 0;
    }
    /* Добавление состояния в список */
    pCMe->m_Transitions->pVTbl->Add(pCMe->m_Transitions, pITransition);

    return pITransition;
}
/*
 *
 * <сводка>
 *   Функция Flip
 * </сводка>
 *
 * <описание>
 *   Функция 
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_Flip(/* in */ IEcoFSM1StateMachinePtr_t me) {
    /*CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;*/
    bool_t bResult = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    return bResult;
}

/*
 *
 * <сводка>
 *   Функция AddAlphabet
 * </сводка>
 *
 * <описание>
 *   Функция добавляет алфавит
 * </описание>
 *
 */
IEcoFL1Alphabet* ECOCALLMETHOD CEcoFSM1StateMachine_2C4F446F_AddAlphabet(/* in */ IEcoFSM1StateMachinePtr_t me, /* in */ char* Name) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)me;
    int16_t result = 0;
    IEcoFL1Alphabet* pIAlphabet = 0;

    /* Проверка указателей */
    if (me == 0) {
        return 0;
    }

    /* Создание алфавита */
    result = createCEcoFL1Alphabet_2C4F446F((IEcoUnknown*)pCMe->m_pISys, 0, Name, &pIAlphabet);
    if (result != 0 || pIAlphabet == 0) {
        /* Возврат в случае ошибки */
        return 0;
    }

    pCMe->m_Alphabet = pIAlphabet;

    return pIAlphabet;
}

/* Create Virtual Table */
IEcoFSM1StateMachineVTbl g_x6B73BD3F22F6462EAC29F5C1214E775EVTbl_2C4F446F = {
    CEcoFSM1StateMachine_2C4F446F_QueryInterface,
    CEcoFSM1StateMachine_2C4F446F_AddRef,
    CEcoFSM1StateMachine_2C4F446F_Release,
    CEcoFSM1StateMachine_2C4F446F_get_Name,
    CEcoFSM1StateMachine_2C4F446F_get_Id,
    CEcoFSM1StateMachine_2C4F446F_get_Alphabet,
    CEcoFSM1StateMachine_2C4F446F_AddState,
    CEcoFSM1StateMachine_2C4F446F_get_States,
    CEcoFSM1StateMachine_2C4F446F_AddEvent,
    CEcoFSM1StateMachine_2C4F446F_get_Events,
    CEcoFSM1StateMachine_2C4F446F_AddTransition,
    CEcoFSM1StateMachine_2C4F446F_AddTransitionById,
    CEcoFSM1StateMachine_2C4F446F_get_Transitions,
    CEcoFSM1StateMachine_2C4F446F_Flip,
    CEcoFSM1StateMachine_2C4F446F_get_TransitionTable,
    CEcoFSM1StateMachine_2C4F446F_AddAlphabet
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
int16_t ECOCALLMETHOD createCEcoFSM1StateMachine_2C4F446F(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ char_t* Name, /* out */ IEcoFSM1StateMachine** ppIStateMachine) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoFSM1StateMachine_2C4F446F* pCMe = 0;

    /* Проверка указателей */
    if (ppIStateMachine == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (voidptr_t*)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (voidptr_t*)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (voidptr_t*) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoFSM1StateMachine_2C4F446F*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoFSM1StateMachine_2C4F446F));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;
    /* Сохранение указателя на интерфейсную шину */
    pCMe->m_pIBus = pIBus;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoFSM1StateMachine */
    pCMe->m_pVTblIStateMachine = &g_x6B73BD3F22F6462EAC29F5C1214E775EVTbl_2C4F446F;

    pCMe->m_Transitions = 0;
    pCMe->m_Events = 0;
    pCMe->m_pIString = 0;
    pCMe->m_States = 0;
    pCMe->m_pIData = 0;
    pCMe->m_Name = 0;
    pCMe->m_TransitionTable = 0;
    pCMe->m_Id = 0;

    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (voidptr_t*)&pCMe->m_pIString);
    if (result != 0 || pCMe-> m_pIString == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
    }

    /* Создание экземпляра списка для состояний конечного автомата */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_States);
    if (result != 0 || pCMe->m_States == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
    }

    /* Создание экземпляра списка для переходов конечного автомата */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_Transitions);
    if (result != 0 || pCMe->m_Transitions == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
    }

    /* Создание экземпляра списка для событий конечного автомата */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (voidptr_t*)&pCMe->m_Events);
    if (result != 0 || pCMe->m_Events == 0) {
        /* Освобождение в случае ошибки */
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
    }

    /* Получение интерфейса для работы с таблицами */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoData1, 0, &IID_IEcoData1, (voidptr_t*) &pCMe->m_pIData);
    if (result != 0 && pCMe->m_pIData == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoFSM1StateMachine_2C4F446F((IEcoFSM1StateMachine*)pCMe);
    }

    /* Сохраняем имя конечного автомата и создаем управляющую таблицу */
    if (Name != 0) {
        pCMe->m_Name = pCMe->m_pIString->pVTbl->Clone(pCMe->m_pIString, Name);
        pCMe->m_TransitionTable = pCMe->m_pIData->pVTbl->CreateTable(pCMe->m_pIData, pCMe->m_Name);
    }
    else {
        pCMe->m_TransitionTable = pCMe->m_pIData->pVTbl->CreateTable(pCMe->m_pIData, "Transition");
    }

    /* Возврат указателя на интерфейс */
    *ppIStateMachine = (IEcoFSM1StateMachine*)pCMe;


    return 0;
};

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
void ECOCALLMETHOD deleteCEcoFSM1StateMachine_2C4F446F(/* in */ IEcoFSM1StateMachine* pIStateMachine) {
    CEcoFSM1StateMachine_2C4F446F* pCMe = (CEcoFSM1StateMachine_2C4F446F*)pIStateMachine;
    IEcoMemoryAllocator1* pIMem = 0;
    uint32_t index = 0;
    IEcoUnknown* pIUnk = 0;

    if (pIStateMachine != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pIString != 0 ) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_States != 0 ) {
            for (index = 0; index < pCMe->m_States->pVTbl->Count(pCMe->m_States); index++) {
                pIUnk = (IEcoUnknown*)pCMe->m_States->pVTbl->Item(pCMe->m_States, index);
                pIUnk->pVTbl->Release(pIUnk);
            }
            pCMe->m_States->pVTbl->Clear(pCMe->m_States);
            pCMe->m_States->pVTbl->Release(pCMe->m_States);
        }
        if ( pCMe->m_Transitions != 0 ) {
            for (index = 0; index < pCMe->m_Transitions->pVTbl->Count(pCMe->m_Transitions); index++) {
                pIUnk = (IEcoUnknown*)pCMe->m_Transitions->pVTbl->Item(pCMe->m_Transitions, index);
                pIUnk->pVTbl->Release(pIUnk);
            }
            pCMe->m_Transitions->pVTbl->Clear(pCMe->m_Transitions);
            pCMe->m_Transitions->pVTbl->Release(pCMe->m_Transitions);
        }
        if ( pCMe->m_Events != 0 ) {
            for (index = 0; index < pCMe->m_Events->pVTbl->Count(pCMe->m_Events); index++) {
                pIUnk = (IEcoUnknown*)pCMe->m_Events->pVTbl->Item(pCMe->m_Events, index);
                pIUnk->pVTbl->Release(pIUnk);
            }
            pCMe->m_Events->pVTbl->Clear(pCMe->m_Events);
            pCMe->m_Events->pVTbl->Release(pCMe->m_Events);
        }
        if (pCMe->m_TransitionTable != 0) {
            pCMe->m_TransitionTable->pVTbl->Release(pCMe->m_TransitionTable);
            pCMe->m_TransitionTable = 0;
        }
        if (pCMe->m_pIData != 0) {
            pCMe->m_pIData->pVTbl->Release(pCMe->m_pIData);
            pCMe->m_pIData = 0;
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
            pCMe->m_pISys = 0;
        }
        if (pCMe->m_pIBus != 0) {
            pCMe->m_pIBus->pVTbl->Release(pCMe->m_pIBus);
            pCMe->m_pIBus = 0;
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};
