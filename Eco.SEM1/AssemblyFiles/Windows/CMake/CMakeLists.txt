cmake_minimum_required(VERSION 3.22)
project(UnitTest C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "/TC /Gz")
set(CMAKE_SHARED_LINKER_FLAGS "/DYNAMICBASE")
set(CMAKE_EXE_LINKER_FLAGS "/DYNAMICBASE")
set(CMAKE_EXE_LINKER_FLAGS "/NODEFAULTLIB:libcmt.lib")

add_definitions(-DECO_WINDOWS)
add_definitions(-D_DEBUG)
add_definitions(-DECO_DLL)
add_definitions(-DUGUID_UTILITY)
add_definitions(-DECO_X86_32)
add_definitions(-DECO_WIN32)
add_definitions(-DWIN32)
add_definitions(-D_WINDOWS)
add_definitions(-D_CONSOLE)

include_directories(../../../HeaderFiles)
include_directories(../../../SharedFiles)
include_directories(../../../UnitTestFiles/HeaderFiles)
include_directories(../../../UnitTestFiles/SharedFiles)


include_directories(
        $ENV{ECO_FRAMEWORK}/Eco.List1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.Core1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.System1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.Data1/SharedFiles # есть local
        $ENV{ECO_FRAMEWORK}/Eco.String1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.Log1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.DateTime1/SharedFiles # есть
#        $ENV{ECO_FRAMEWORK}/Eco.FSM1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Map1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Tree1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Mutex1/SharedFiles # есть
        $ENV{ECO_FRAMEWORK}/Eco.Stack1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.PECOFF1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Dictionary1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Set1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Comparator1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.COFF1/SharedFiles  # есть local
        $ENV{ECO_FRAMEWORK}/Eco.MZEXE1/SharedFiles # есть local
        $ENV{ECO_FRAMEWORK}/Eco.Visitor1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Queue1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Observer1/SharedFiles

#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.LexicalAnalyzer1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.SyntaxAnalyzer1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.LR1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.AST1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.BNF1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.RL1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.MacroProcessor1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.CodeGenerator1/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.EmitterI80686/SharedFiles
#        $ENV{ECO_FRAMEWORK}/Eco.Toolchain.Linker1/SharedFiles
)


include_directories(
        ../../../../Eco.Tree1/SharedFiles
        ../../../../Eco.Tree1/HeaderFiles
)

add_library(
        82F73722057E47F3A2931ED27087694D
        SHARED

        ../../../../Eco.Tree1/SourceFiles/CEcoTree1.c
        ../../../../Eco.Tree1/SourceFiles/CEcoTree1Node.c
        ../../../../Eco.Tree1/SourceFiles/CEcoTree1Factory.c
        ../../../../Eco.Tree1/SharedFiles/IEcoTree1.h
        ../../../../Eco.Tree1/SharedFiles/IdEcoTree1.h
        ../../../../Eco.Tree1/HeaderFiles/CEcoTree1Node.h
        ../../../../Eco.Tree1/HeaderFiles/CEcoTree1Factory.h
        ../../../../Eco.Tree1/HeaderFiles/CEcoTree1.h
)

include_directories(
        ../../../../Eco.Data1/SharedFiles
        ../../../../Eco.Data1/HeaderFiles
)

add_library(
        5A0F0DD57E6448EC9EE0E5D67572B47E
        SHARED

        ../../../../Eco.Data1/SharedFiles/IdEcoData1.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Factory.h
        ../../../../Eco.Data1/HeaderFiles/CEcoData1.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1.c
        ../../../../Eco.Data1/SourceFiles/CEcoData1Factory.c


        ../../../../Eco.Data1/SourceFiles/CEcoData1Column.c
        ../../../../Eco.Data1/HeaderFiles/CEcoData1Column.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Column.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Row.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Row.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Row.c

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Table.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Table.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Table.c

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Item.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Item.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Item.c
)

include_directories(
        ../../../../Eco.FSM1/SharedFiles
        ../../../../Eco.FSM1/HeaderFiles
)

add_library(
        5E7C610CB846447DB59A3C5A2C4F446F
        SHARED
        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1.c
        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1Factory.c
        ../../../../Eco.FSM1/SharedFiles/IdEcoFSM1.h
        ../../../../Eco.FSM1/SharedFiles/IEcoFSM1.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Factory.h

        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1Event.c
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Event.h

        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1State.c
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1State.h

        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1Transition.c
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Transition.h

        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1StateMachine.c
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1StateMachine.h

        ../../../../Eco.FSM1/SourceFiles/CEcoFSM1EventProcessing.c
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1EventProcessing.h
)

include_directories(
        ../../../../Eco.MacroProcessor1/SharedFiles
        ../../../../Eco.MacroProcessor1/HeaderFiles
)

add_library(
        A06E8BB991334E0C84CDAE59AE984DB9
        SHARED

        ../../../../Eco.MacroProcessor1/HeaderFiles/CEcoMacroProcessor1.h
        ../../../../Eco.MacroProcessor1/HeaderFiles/CEcoMacroProcessor1Factory.h
        ../../../../Eco.MacroProcessor1/HeaderFiles/CEcoMacroProcessor1Processing.h
        ../../../../Eco.MacroProcessor1/HeaderFiles/CEcoMacroProcessor1Result.h
        ../../../../Eco.MacroProcessor1/HeaderFiles/EcoC89Grammar.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IdEcoMacroProcessor1.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IEcoLexicalAnalyzer1Token.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IEcoMacroProcessor1.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IEcoMacroProcessor1Processing.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IEcoMacroProcessor1Result.h
        ../../../../Eco.MacroProcessor1/SourceFiles/CEcoMacroProcessor1.c
        ../../../../Eco.MacroProcessor1/SourceFiles/CEcoMacroProcessor1Factory.c
        ../../../../Eco.MacroProcessor1/SourceFiles/CEcoMacroProcessor1Result.c
        ../../../../Eco.MacroProcessor1/SourceFiles/CEcoMacroProcessor1Processing.c
)

include_directories(
        ../../../../Eco.BNF1/SharedFiles
        ../../../../Eco.BNF1/HeaderFiles
)

add_library(
        323DD55E33D040FA98068E2FCB1CBD49
        SHARED

       ../../../../Eco.BNF1/HeaderFiles/CEcoBNF1Rule.h
       ../../../../Eco.BNF1/HeaderFiles/CEcoBNF1.h
       ../../../../Eco.BNF1/HeaderFiles/CEcoBNF1Element.h
       ../../../../Eco.BNF1/HeaderFiles/CEcoBNF1Factory.h
       ../../../../Eco.BNF1/SharedFiles/IdEcoBNF1.h
       ../../../../Eco.BNF1/SharedFiles/IEcoBNF1.h
       ../../../../Eco.BNF1/SourceFiles/CEcoBNF1.c
       ../../../../Eco.BNF1/SourceFiles/CEcoBNF1Element.c
       ../../../../Eco.BNF1/SourceFiles/CEcoBNF1Factory.c
       ../../../../Eco.BNF1/SourceFiles/CEcoBNF1Rule.c
)

include_directories(
        ../../../../Eco.LR1/SharedFiles
        ../../../../Eco.LR1/HeaderFiles
)

add_library(
        69173E0D97DF4B23AAE05D9CDA852EE2
        SHARED

        ../../../../Eco.LR1/SharedFiles/IdEcoLR1.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1LRk.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1Action.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1Factory.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1Action.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1LRkItem.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1ActionProcessing.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1ItemComparator.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1ActionProcessing.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1Item.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1ItemSetComparator.h
        ../../../../Eco.LR1/HeaderFiles/CEcoLR1.h
        ../../../../Eco.LR1/SourceFiles/CEcoLR1.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1Action.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1ActionProcessing.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1Factory.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1Item.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1ItemComparator.c
        ../../../../Eco.LR1/SourceFiles/CEcoLR1ItemSetComparator.c
)


include_directories(
        ../../../../Eco.LexicalAnalyzer1/HeaderFiles
        ../../../../Eco.LexicalAnalyzer1/SharedFiles
)

add_library(
        7D1E60DAB7EA4837A79D537781F94437
        SHARED

        ../../../../Eco.LexicalAnalyzer1/HeaderFiles/CEcoLexicalAnalyzer1.h
        ../../../../Eco.LexicalAnalyzer1/HeaderFiles/CEcoLexicalAnalyzer1Factory.h
        ../../../../Eco.LexicalAnalyzer1/HeaderFiles/CEcoLexicalAnalyzer1Scanner.h
        ../../../../Eco.LexicalAnalyzer1/HeaderFiles/CEcoLexicalAnalyzer1Token.h
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IdEcoLexicalAnalyzer1.h
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IEcoLexicalAnalyzer1.h
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IEcoLexicalAnalyzer1Scanner.h
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IEcoLexicalAnalyzer1Token.h
        ../../../../Eco.LexicalAnalyzer1/SourceFiles/CEcoLexicalAnalyzer1.c
        ../../../../Eco.LexicalAnalyzer1/SourceFiles/CEcoLexicalAnalyzer1Factory.c
        ../../../../Eco.LexicalAnalyzer1/SourceFiles/CEcoLexicalAnalyzer1Scanner.c
        ../../../../Eco.LexicalAnalyzer1/SourceFiles/CEcoLexicalAnalyzer1Token.c
)

include_directories(
        ../../../../Eco.AST1/SharedFiles
        ../../../../Eco.AST1/HeaderFiles
)

add_library(
        2FE0BD508F5743BDA9F52414233542A8
        SHARED

        ../../../../Eco.AST1/SharedFiles/IEcoAST1EnumType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1MemberSelection.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Literal.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1PointerType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1FunctionDeclaration.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1WhileStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1VariableDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BinaryExpression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1FunctionType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BreakStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1FunctionType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1CompoundStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1EnumType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1TranslationUnit.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1LabelStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1GoToStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1NumberType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BlockExpressions.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ForStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1FunctionDeclaration.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1CompoundStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BlockTypes.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1UnaryExpression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1TypedefType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ConditionalExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BlockDeclarations.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1FunctionDefinition.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1SizeofExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1StructOrUnionDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1CastExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1CastExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1IntegerLiteral.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1NullExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1FunctionCall.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1ReturnStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1StructOrUnionType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BlockStatements.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BlockExpressions.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BlockStatements.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1CaseStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1IfStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BlockTranslationUnitObjects.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1ForStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BlockDeclarations.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1DoWhileStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1SwitchStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1GlobalScope.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ContinueStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1IntegerLiteral.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1ContinueStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1FunctionDefinition.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1VariableDefinition.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BreakStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1FloatLiteral.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1DefaultStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1DoWhileStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1GoToStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1SizeofType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1GlobalScope.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1IfStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Expression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1CaseStatement.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BinaryExpression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1MemberSelection.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1Scope.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1CharacterLiteral.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1EnumDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1BlockTranslationUnitObjects.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1ArrayType.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1EnumDeclaration.h
        ../../../../Eco.AST1/SharedFiles/ErrEcoAST1.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1ConditionalExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1DefaultStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ExpressionableDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1NullExpression.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1StringLiteral.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1CharacterLiteral.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1FunctionCall.h
        ../../../../Eco.AST1/SharedFiles/IdEcoAST1.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1Factory.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1TypedefDeclaration.h
        ../../../../Eco.AST1/HeaderFiles/CEcoAST1BlockTypes.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Declaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1LabelStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1FloatLiteral.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ArrayType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1PointerType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1NumberType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1ReturnStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1SingleStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Scope.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1SizeofExpression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Statement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1SizeofType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1StringLiteral.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1StructOrUnionDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1StructOrUnionType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1SwitchStatement.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1SyntaxObject.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1TranslationUnit.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1TranslationUnitObject.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1Type.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1TypedefDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1TypedefType.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1VariableDeclaration.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1UnaryExpression.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1VariableDefinition.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1WhileStatement.h

        ../../../../Eco.AST1/SourceFiles/CEcoAST1ArrayType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BinaryExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BlockDeclarations.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BlockExpressions.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BlockStatements.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BlockTranslationUnitObjects.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BlockTypes.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1BreakStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1CaseStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1CharacterLiteral.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1CastExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1CompoundStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1ConditionalExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1ContinueStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1DoWhileStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1DefaultStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1EnumType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1EnumDeclaration.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1Factory.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1FloatLiteral.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1FunctionCall.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1ForStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1FunctionDeclaration.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1FunctionDefinition.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1FunctionType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1GlobalScope.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1GoToStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1IfStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1IntegerLiteral.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1LabelStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1MemberSelection.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1NullExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1NumberType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1PointerType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1Scope.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1ReturnStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1SizeofExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1SizeofType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1StringLiteral.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1StructOrUnionDeclaration.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1StructOrUnionType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1TranslationUnit.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1SwitchStatement.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1TypedefDeclaration.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1TypedefType.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1UnaryExpression.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1VariableDeclaration.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1VariableDefinition.c
        ../../../../Eco.AST1/SourceFiles/CEcoAST1WhileStatement.c
)

include_directories(
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles
)

add_library(
        01097B434B08447BBC0B6F5698E4C2CB
        SHARED

        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoSyntaxAnalyzer1.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoSyntaxAnalyzer1ConflictResolver_C.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoSyntaxAnalyzer1Factory.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoSyntaxAnalyzer1Parser.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_AdditiveExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoSyntaxAnalyzer1TypeUtils.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ANDExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_AssignmentExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_C0BeginState.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_CompoundStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_CastExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ConditionalExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ConstantExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_Declaration.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_DeclarationSpecifier.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_EqualityExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ExclusiveORExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_Expression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ExpressionStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ExternalDeclaration.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_FunctionDefinition.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_InclusiveORExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_FunctionDefinitionSpecifier.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_Initializer.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_IterationStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_JumpStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_LabeledStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_LogicalANDExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_MultiplicativeExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_LogicalORExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_PostfixExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_PrimaryExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_RelationalExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_SelectionStatement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_ShiftExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_SpecifierQualifier.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_Statement.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_TypeName.c
        ../../../../Eco.SyntaxAnalyzer1/SourceFiles/CEcoTSA1RM_UnaryExpression.c
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IEcoSyntaxAnalyzer1RuleMapper.h
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IEcoSyntaxAnalyzer1Parser.h
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IEcoSyntaxAnalyzer1ConflictResolver.h
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IEcoSyntaxAnalyzer1.h
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IdEcoSyntaxAnalyzer1.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoSyntaxAnalyzer1.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoSyntaxAnalyzer1ConflictResolver_C.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoSyntaxAnalyzer1Factory.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoSyntaxAnalyzer1Parser.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoSyntaxAnalyzer1TypeUtils.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_AdditiveExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ANDExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_AssignmentExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_C0BeginState.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_CastExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_CompoundStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ConditionalExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ConstantExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_Declaration.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_DeclarationSpecifier.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ExclusiveORExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_EqualityExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_Expression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ExpressionStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ExternalDeclaration.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_FunctionDefinition.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_FunctionDefinitionSpecifier.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_InclusiveORExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_Initializer.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_IterationStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_JumpStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_LabeledStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_LogicalANDExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_MultiplicativeExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_LogicalORExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_PostfixExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_PrimaryExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_RelationalExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_SelectionStatement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_ShiftExpression.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_SpecifierQualifier.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_Statement.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_TypeName.h
        ../../../../Eco.SyntaxAnalyzer1/HeaderFiles/CEcoTSA1RM_UnaryExpression.h
)

include_directories(
        ../../../../Eco.RL1/SharedFiles
        ../../../../Eco.RL1/HeaderFiles
)

add_library(
        9D51655E6B8542EDB7D0CC7C9980D749
        SHARED

        ../../../../Eco.RL1/HeaderFiles/CEcoRL1.h
        ../../../../Eco.RL1/HeaderFiles/CEcoRL1Expression.h
        ../../../../Eco.RL1/HeaderFiles/CEcoRL1Factory.h
        ../../../../Eco.RL1/HeaderFiles/CEcoRL1Grammar.h
        ../../../../Eco.RL1/HeaderFiles/CEcoRL1NonTerminal.h
        ../../../../Eco.RL1/HeaderFiles/CEcoRL1Rule.h
        ../../../../Eco.RL1/SharedFiles/IdEcoRL1.h
        ../../../../Eco.RL1/SharedFiles/IEcoRL1.h
        ../../../../Eco.RL1/SharedFiles/IEcoRL1Conversion.h
        ../../../../Eco.RL1/SourceFiles/CEcoRL1.c
        ../../../../Eco.RL1/SourceFiles/CEcoRL1Expression.c
        ../../../../Eco.RL1/SourceFiles/CEcoRL1Grammar.c
        ../../../../Eco.RL1/SourceFiles/CEcoRL1Factory.c
        ../../../../Eco.RL1/SourceFiles/CEcoRL1NonTerminal.c
        ../../../../Eco.RL1/SourceFiles/CEcoRL1Rule.c
)

include_directories(
        ../../../../Eco.EmitterI80686/SharedFiles
        ../../../../Eco.EmitterI80686/HeaderFiles
)

add_library(
        67198C8746EB4AECB589ED4E68000FD9
        SHARED

        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686Factory.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686Fixup.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686Instruction1.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686InstructionSet1.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686SymbolTable1.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686SymbolEntry1.h
        ../../../../Eco.EmitterI80686/HeaderFiles/CEcoEmitterI80686Visitor.h
        ../../../../Eco.EmitterI80686/HeaderFiles/IEcoMachineCode1.h
        ../../../../Eco.EmitterI80686/SharedFiles/IdEcoEmitterI80686.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoEmitter1.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoEmitter1Fixup.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoInstruction1.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoInstructionSet1.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoSymbolEntry1.h
        ../../../../Eco.EmitterI80686/SharedFiles/IEcoSymbolTable1.h
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686Factory.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686Fixup.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686InstructionSet1.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686Instruction1.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686IVisitor.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686SymbolEntry1.c
        ../../../../Eco.EmitterI80686/SourceFiles/CEcoEmitterI80686SymbolTable1.c
)

include_directories(
        ../../../../Eco.CodeGenerator1/SharedFiles
        ../../../../Eco.CodeGenerator1/HeaderFiles
)

add_library(
        2BF1E51154E441A9ADC82D0930FC5CD0
        SHARED

        ../../../../Eco.CodeGenerator1/SharedFiles/IdEcoCodeGenerator1.h
        ../../../../Eco.CodeGenerator1/HeaderFiles/CEcoCodeGenerator1Factory.h
#        ../../../../Eco.CodeGenerator1/SourceFiles/CEcoCodeGenerator1EmitterI80686.c
        ../../../../Eco.CodeGenerator1/SourceFiles/CEcoCodeGenerator1Factory.c
        ../../../../Eco.CodeGenerator1/HeaderFiles/CEcoCodeGenerator1.h
        ../../../../Eco.CodeGenerator1/SharedFiles/IEcoCodeGenerator1.h
        ../../../../Eco.CodeGenerator1/SourceFiles/CEcoCodeGenerator1.c
#        ../../../../Eco.CodeGenerator1/HeaderFiles/CEcoCodeGenerator1EmitterI80686.h
        ../../../../Eco.CodeGenerator1/HeaderFiles/CEcoCodeGenerator1Fixup.h
        ../../../../Eco.CodeGenerator1/SharedFiles/IEcoCodeGenerator1Fixup.h
        ../../../../Eco.CodeGenerator1/SourceFiles/CEcoCodeGenerator1Fixup.c
)

include_directories(
        ../../../../Eco.PECOFF1/SharedFiles
        ../../../../Eco.PECOFF1/HeaderFiles
)

add_library(
        46511227059E4D488D6FA8123FA0A383
        SHARED

        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1FreeFormatContent.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ImageFile.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1FirstLinkerMember.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1BaseRelocationBlock.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ImportDirectoryEntry.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1DataDirectories.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ImportLibraryMember.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1Factory.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1FixupBlock.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ImportLookupTable.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ObjectFile.h
#        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1LongnamesMember.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ResourceDataEntry.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ObjectFileMember.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ResourceDirectoryEntry.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ResourceDirectoryTable.h
#        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1ResourceSection.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1SecondLinkerMember.h
#        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1SectionHeader.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1SymbolTable.h
        ../../../../Eco.PECOFF1/HeaderFiles/CEcoPECOFF1WindowsSpecificFields.h

        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1WindowsSpecificFields.h
        ../../../../Eco.PECOFF1/SharedFiles/IdEcoPECOFF1.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1BaseRelocationBlock.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1DataDirectories.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1DebugSymbolInformation.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1FirstLinkerMember.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1FreeFormatContent.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ImageFile.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ImportDirectoryEntry.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ImportLibraryMember.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ImportLookupTable.h
#        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1LongnamesMember.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ObjectFile.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ObjectFileMember.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ResourceDataEntry.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ResourceDirectoryEntry.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1ResourceDirectoryTable.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1SecondLinkerMember.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1SymbolTable.h

#        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1SectionHeader.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1SymbolTable.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1WindowsSpecificFields.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1SecondLinkerMember.c
#        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ResourceSection.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ResourceDirectoryTable.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ResourceDirectoryEntry.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ResourceDataEntry.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ObjectFileMember.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ObjectFile.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ImportLookupTable.c
#        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1LongnamesMember.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ImportLibraryMember.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ImportDirectoryEntry.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1ImageFile.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1FreeFormatContent.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1FirstLinkerMember.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1Factory.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1DataDirectories.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1BaseRelocationBlock.c
        ../../../../Eco.PECOFF1/SourceFiles/CEcoPECOFF1.c
)

include_directories(
        ../../../../Eco.Linker1/SharedFiles
        ../../../../Eco.Linker1/HeaderFiles
)

add_library(
        1E7247F803CE4A30B3A0C00E9F6D5C17
        SHARED

        ../../../../Eco.Linker1/HeaderFiles/CEcoLinker1.h
        ../../../../Eco.Linker1/HeaderFiles/CEcoLinker1Factory.h
        ../../../../Eco.Linker1/SharedFiles/IdEcoLinker1.h
        ../../../../Eco.Linker1/SharedFiles/IEcoLinker1.h
        ../../../../Eco.Linker1/SourceFiles/CEcoLinker1.c
        ../../../../Eco.Linker1/SourceFiles/CEcoLinker1Factory.c
)

include_directories(
        ../../../../Eco.SE1.Lua/SharedFiles
        ../../../../Eco.SE1.Lua/HeaderFiles
)

add_library(
        A42A420FC14D43879877877F8E62028C
        SHARED

        ../../../../Eco.SE1.Lua/SharedFiles/IEcoSE1LuaContext.h
        ../../../../Eco.SE1.Lua/SharedFiles/IEcoSE1.h
        ../../../../Eco.SE1.Lua/SharedFiles/IdEcoSE1Lua.h
        ../../../../Eco.SE1.Lua/SharedFiles/ErrEcoSE1Lua.h
        ../../../../Eco.SE1.Lua/HeaderFiles/CEcoSE1LuaFactory.h
        ../../../../Eco.SE1.Lua/HeaderFiles/CEcoSE1Lua.h
        ../../../../Eco.SE1.Lua/HeaderFiles/CEcoSE1LuaContext.h
        ../../../../Eco.SE1.Lua/SourceFiles/CEcoSE1Lua.c
        ../../../../Eco.SE1.Lua/SourceFiles/CEcoSE1LuaContext.c
        ../../../../Eco.SE1.Lua/SourceFiles/CEcoSE1LuaFactory.c
)

add_library(
        9BC2C181999243A38E45C2BC67CDDD73
        SHARED

        ../../../../Eco.SEM1/SharedFiles/IdEcoSEM1.h
        ../../../../Eco.SEM1/SharedFiles/IEcoSEM1.h
        ../../../../Eco.SEM1/SharedFiles/ErrEcoSEM1.h
        ../../../../Eco.SEM1/HeaderFiles/CEcoSEM1.h
        ../../../../Eco.SEM1/HeaderFiles/CEcoSEM1Factory.h
        ../../../../Eco.SEM1/SourceFiles/CEcoSEM1.c
        ../../../../Eco.SEM1/SourceFiles/CEcoSEM1Factory.c
)

add_executable(
        UnitTest

        ../../../UnitTestFiles/SourceFiles/EcoSEM1.c

        # Eco.SEM1
        ../../../../Eco.SEM1/SharedFiles/IdEcoSEM1.h
        ../../../../Eco.SEM1/SharedFiles/IEcoSEM1.h
        ../../../../Eco.SEM1/SharedFiles/ErrEcoSEM1.h

        # Eco.SE1.Lua
        ../../../../Eco.SE1.Lua/SharedFiles/IEcoSE1LuaContext.h
        ../../../../Eco.SE1.Lua/SharedFiles/IEcoSE1.h
        ../../../../Eco.SE1.Lua/SharedFiles/IdEcoSE1Lua.h
        ../../../../Eco.SE1.Lua/SharedFiles/ErrEcoSE1Lua.h

        # Eco.FSM1
        ../../../../Eco.FSM1/SharedFiles/IdEcoFSM1.h
        ../../../../Eco.FSM1/SharedFiles/IEcoFSM1.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Factory.h

        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Event.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1State.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1Transition.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1StateMachine.h
        ../../../../Eco.FSM1/HeaderFiles/CEcoFSM1EventProcessing.h

        # Eco.Data1
        ../../../../Eco.Data1/HeaderFiles/CEcoData1Factory.h
        ../../../../Eco.Data1/HeaderFiles/CEcoData1.h

        ../../../../Eco.Data1/SharedFiles/IdEcoData1.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Column.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Column.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Row.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Row.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Table.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Table.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Item.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Item.h

        # Eco.LexicalAnalyzer1
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IdEcoLexicalAnalyzer1.h
        ../../../../Eco.LexicalAnalyzer1/SharedFiles/IEcoLexicalAnalyzer1.h

        # Eco.SyntaxAnalyzer1
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IdEcoSyntaxAnalyzer1.h
        ../../../../Eco.SyntaxAnalyzer1/SharedFiles/IEcoSyntaxAnalyzer1.h

        # Eco.LR1
        ../../../../Eco.LR1/SharedFiles/IdEcoLR1.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1Action.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1ActionProcessing.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1LRk.h
        ../../../../Eco.LR1/SharedFiles/IEcoParser1LRkItem.h

        # Eco.AST1
        ../../../../Eco.AST1/SharedFiles/IdEcoAST1.h
        ../../../../Eco.AST1/SharedFiles/IEcoAST1.h

        # Eco.BNF1
        ../../../../Eco.BNF1/SharedFiles/IdEcoBNF1.h
        ../../../../Eco.BNF1/SharedFiles/IEcoBNF1.h

        # Eco.MacroProcessor1
        ../../../../Eco.MacroProcessor1/SharedFiles/IdEcoMacroProcessor1.h
        ../../../../Eco.MacroProcessor1/SharedFiles/IEcoMacroProcessor1.h

        # Eco.CodeGenerator1
        ../../../../Eco.CodeGenerator1/SharedFiles/IdEcoCodeGenerator1.h
        ../../../../Eco.CodeGenerator1/SharedFiles/IEcoCodeGenerator1.h

        # Eco.EmitterLLVMIR1
        ../../../../Eco.EmitterLLVMIR1/SharedFiles/IdEcoEmitterLLVMIR1.h
        ../../../../Eco.EmitterLLVMIR1/SharedFiles/IEcoEmitterLLVMIR1.h

        # Eco.Linker1
        ../../../../Eco.Linker1/SharedFiles/IdEcoLinker1.h
        ../../../../Eco.Linker1/SharedFiles/IEcoLinker1.h

        # Eco.PECOFF1
        ../../../../Eco.PECOFF1/SharedFiles/IdEcoPECOFF1.h
        ../../../../Eco.PECOFF1/SharedFiles/IEcoPECOFF1.h
)



target_link_libraries(
        UnitTest
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000042757331.lib
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/BuildFiles/Windows/x86/StaticRelease/0000000000000000000000004D656D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000046534D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.System1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000053595332.lib
        $ENV{ECO_FRAMEWORK}/Eco.List1/BuildFiles/Windows/x86/StaticRelease/53884AFC93C448ECAA929C8D3A562281.lib
        $ENV{ECO_FRAMEWORK}/Eco.String1/BuildFiles/Windows/x86/StaticRelease/84CC0A7DBABD44EEBE749C9A8312D37E.lib
        $ENV{ECO_FRAMEWORK}/Eco.Log1/BuildFiles/Windows/x86/StaticRelease/97322B6765B74342BBCE38798A0B40B5.lib
        $ENV{ECO_FRAMEWORK}/Eco.DateTime1/BuildFiles/Windows/x86/StaticRelease/5B2BA17BEA704527BC708F88568FE115.lib

#        $ENV{ECO_FRAMEWORK}/Eco.Dictionary1/BuildFiles/Windows/x86/StaticRelease/2912A7C7E0B84B4D9BFE9500EF4667D3.lib
#        $ENV{ECO_FRAMEWORK}/Eco.Map1/BuildFiles/Windows/x86/StaticRelease/0D7907DBE1C14B9E9B9FD9E8D9E251DF.lib
#        $ENV{ECO_FRAMEWORK}/Eco.Set1/BuildFiles/Windows/x86/StaticRelease/7750135D34D7461897B912F7CC615F72.lib
#        $ENV{ECO_FRAMEWORK}/Eco.Tree1/BuildFiles/Windows/x86/StaticRelease/82F73722057E47F3A2931ED27087694D.lib
        $ENV{ECO_FRAMEWORK}/Eco.Mutex1/BuildFiles/Windows/x86/StaticRelease/427A8D37D2914DCE9710D81099D5F190.lib
#        $ENV{ECO_FRAMEWORK}/Eco.PECOFF1/BuildFiles/Windows/x86/StaticRelease/46511227059E4D488D6FA8123FA0A383.lib

        $ENV{ECO_FRAMEWORK}/Eco.Comparator1/BuildFiles/Windows/x86/StaticRelease/C7ED3BA4B6EB4385BBDB3C6AC5C7A394.lib
        $ENV{ECO_FRAMEWORK}/Eco.Visitor1/BuildFiles/Windows/x86/StaticRelease/4E7C20FEFAF341069B5C42497B462BBE.lib
        $ENV{ECO_FRAMEWORK}/Eco.Queue1/BuildFiles/Windows/x86/StaticRelease/25D72F83A2564F4E9F59E489BE85E2A4.lib
        $ENV{ECO_FRAMEWORK}/Eco.Observer1/BuildFiles/Windows/x86/StaticRelease/2A1A9CF60C724209A401543FF529E3B9.lib

        82F73722057E47F3A2931ED27087694D
        5A0F0DD57E6448EC9EE0E5D67572B47E
        5E7C610CB846447DB59A3C5A2C4F446F
        A06E8BB991334E0C84CDAE59AE984DB9
        01097B434B08447BBC0B6F5698E4C2CB
        69173E0D97DF4B23AAE05D9CDA852EE2
        2FE0BD508F5743BDA9F52414233542A8
        323DD55E33D040FA98068E2FCB1CBD49
        7D1E60DAB7EA4837A79D537781F94437
        9D51655E6B8542EDB7D0CC7C9980D749

        2BF1E51154E441A9ADC82D0930FC5CD0
        46511227059E4D488D6FA8123FA0A383
        1E7247F803CE4A30B3A0C00E9F6D5C17
        67198C8746EB4AECB589ED4E68000FD9
        9BC2C181999243A38E45C2BC67CDDD73
)
