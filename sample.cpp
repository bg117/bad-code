#include "include/cstext"

Using NS Extensions;

Class(sample)
    
    Public 
    NoInit Function(NoReturn, aMethod, int one, String two, CString three)
        NoChange CString newstr = two.c_str();
        Out("Static method aMethod in class sample. Params: %d %s %s %s", one, newstr, three, Newline);
    EndFunction

    Template(T)
    NoInit AttribFunction(Float, DefaultCall, anotherMethod, T param1)
        OutErr("Static method anotherMethod in class sample with stderr. param1 = %s%s", param1, Newline);
        RetVal 1.0f;
    EndFunction
EndClass

Main
    UInt32 argcm1 = argc - 1;
    Select(argcm1 IsGreaterThan 1)
        Case(True)
            printf("true. argc is more than 1%s", Newline);
        Break

        Case(False)
            printf("false. argc is less than 1%s", Newline);
        Break
    EndSelect

    sample::aMethod(1,"hi", (CString)"hello");
    sample::anotherMethod("lol");

    For(Var(int, i, 0), ToEq(i, 10), StepUp(i))
        Out("i = %d%s", i, Newline);
    EndFor

    Int32 one = 1;
    Int32 two = 2;

    Console::Put < "Ternary operator: Ternary((one IsGreaterThan two), \"ONE IS GREATER THAN TWO%s\", \"ONE IS LESS THAN TWO%s\")" < Newline;

    Out((Ternary((one IsGreaterThan two), "ONE IS GREATER THAN TWO%s", "ONE IS LESS THAN TWO%s")), Newline);
    
    one = 2;
    two = 1;

    Out((Ternary((one IsGreaterThan two), "ONE IS GREATER THAN TWO%s", "ONE IS LESS THAN TWO%s")), Newline);

    If
    (
        argcm1 IsGreaterThan 1, 
        Out("argc is %d%s", argcm1, Newline);
    )

    ElseIf
    (
        argcm1 IsLessThanOrEqualTo 1, 
        Out("argc is less than/equal to 1%s", Newline);
    )
    
    CString c = "Hi\n";
    CString v = "Hello\n";

    Out("Before: %s", c);
    Out("Before: %s", v);

    Swap(c, v);

    Out("After: %s", c);
    Out("After: %s", v);

    String g;

    Console::Put < "OPERATOR OVERLOAD TEST WORKS!!!!!!!!!"  < Newline < "argc (argument count) = " < argcm1 < Newline;

    Out("Type something: ");
    Console::Get > g;

    For(Var(size_t, i, 1), To(i, argc) , StepUp(i))
        Console::Put  < "argv[" < i < "] (args) = " < argv[i] < Newline;
    EndFor

    RetVal 0;
EndMain