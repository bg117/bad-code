#pragma once
#ifndef __CUST_EXT__
#define __CUST_EXT__ "defined C extensions"

#pragma region Extensions

#define Enum(ename) enum ename { 
#define HEnum(ename) enum ename;
#define TypedefEnum(ename) typedef enum ename { 
#define TypedEnum(ename, type) enum ename : type { 
#define HTypedEnum(ename, type ) enum ename : type;
#define TypedTypedefEnum(ename, type) typedef enum ename : type { 
#define EndTypedefEnum(rename) } rename;
#define EndEnum(rename_optional) } rename_optional; 
#define Struct(sname) struct sname { 
#define TypedefStruct(sname) typedef struct sname { 
#define HStruct(sname) struct sname; 
#define EndTypedefStruct(rename) } rename;
#define EndStruct(rename_optional) } rename_optional; 
#define Function(type, name, ...) type name(__VA_ARGS__) { 
#define AttribFunction(__attrib_or_type, __attrib_or_type_2, name, ...) __attrib_or_type __attrib_or_type_2 name(__VA_ARGS__) {
#define HFunction(type, name, ...) type name (__VA_ARGS__); 
#define HAttribFunction(__attrib_or_type, __attrib_or_type_2, name, ...) __attrib_or_type __attrib_or_type_2 name(__VA_ARGS__);
#define EndFunction } 
#define Main int main(int argc, char *argv[]) { 
#define EndMain } 

#pragma region Modifiers

#define NoInit static
#define NoChange const

#pragma endregion

#pragma region Conditionals

#define If(expr, ...) if ((expr)) { __VA_ARGS__ }
#define ElseIf(expr, ...) else if ((expr)) { __VA_ARGS__ }
#define Else(...) else { __VA_ARGS__ }

#define Ternary(exp1,exp2,exp3) (exp1) ? (exp2) : (exp3)

#define Select(case) switch((case)) {
#define Case(c) case c: {
#define Default default: {
#define EndCase }
#define Break } break;
#define EndSelect }

#pragma endregion

#pragma region Loops

#define For(var, cond, step) for (var; cond; step) {
#define Var(type, variable, defval) type variable = defval
#define ToEq(variable, limit) variable <= limit
#define To(variable, limit) variable < limit
#define FromEq(start, variable) variable >= start
#define From(start, variable) variable > start
#define StepUp(variable) variable++
#define StepDown(variable) variable--
#define EndFor }

#define While(cond) while(cond) {
#define EndWhile }

#define DoWhile(cond, expr)\
do {\
    expr\
} while (cond)

#pragma endregion

#if defined _WIN32 || defined _WIN64

#define DllMain BOOL APIENTRY DllMain(HMODULE hMODULE, DWORD ul_reason_for_call, LPVOID lpReserved) {
#define EndDllMain }

#endif

#pragma region DataTypes

#pragma region NormalTypes

typedef void NoReturn;
typedef void Void;
typedef unsigned char Int8;
typedef unsigned char Byte;
typedef unsigned Unsigned;
typedef short Int16;
typedef int Int32;
typedef unsigned int UInt32;
typedef long long Int64;
typedef float Single;
typedef float Float;
typedef double Double;
typedef unsigned long long UInt64;

#pragma endregion

#pragma region PointerTypes

typedef void* VoidPtr;
typedef int* IntPtr;
typedef long long *LongPtr;
typedef short *ShortPtr;

#pragma endregion

#pragma region Misc

#define Using using
#define NS namespace

#define And &
#define Or |
#define Xor ^
#define Not ~
#define LShift <<
#define RShift >>
#define AndAnd &&
#define OrOr ||
#define NotEqTo !=
#define IsNot !
#define Is ==
#define IsGreaterThan >
#define IsLessThan <
#define IsLessThanOrEqualTo <=
#define IsGreaterThanOrEqualTo >=

#if defined _WIN32 || defined _WIN64
#define Newline "\r\n"

#elif defined __APPLE__ || defined __MACH__
#define Newline "\r"
#elif defined __unix__ || defined unix || defined __unix || defined __unix__ || defined __linux__
#define Newline "\n"
#endif

#define DefaultCall __cdecl
#define StdCall __stdcall
#define FastCall __fastcall
#define RetVal return 

#include <stdarg.h>
#include <stdio.h>

#define String char*
#define ByRef(val) &val

#ifdef __cplusplus

#define DeclC extern "C"
#define DeclCpp extern "C++"

#define True true
#define False false

#else

typedef enum {
    True = 1,
    False = 0,
} Boolean;

#endif

#ifdef __cplusplus
DeclC {
#endif

HFunction(NoReturn, __Out, NoChange String fmt, ...)
HFunction(NoReturn, __OutErr, NoChange String fmt, ...)
HFunction(NoReturn, __In, NoChange String fmt, ...)

#define Out(fmt, ...) __Out(fmt, ##__VA_ARGS__)
#define OutErr(fmt, ...) __OutErr(fmt, ##__VA_ARGS__)
#define In(fmt, ...) __In(fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#pragma endregion
#pragma endregion

#endif