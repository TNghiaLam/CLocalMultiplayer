// Nghia Lam - MIT License

#pragma once

#include "CoreMinimal.h"

// Declare our game log categories
DECLARE_LOG_CATEGORY_EXTERN(LogLocalMulti, Log, All);

// Simplify logging for our games
// ---

#define LMLOG(type, msg) UE_LOG(LogLocalMulti, type, TEXT(msg))
#define LMLOG_ARGS(type, msg, ...) UE_LOG(LogLocalMulti, type, TEXT(msg), __VA_ARGS__)

#define LMLOG_DISPLAY(msg) UE_LOG(LogLocalMulti, Display, TEXT(msg))
#define LMLOG_WARNING(msg) UE_LOG(LogLocalMulti, Warning, TEXT(msg))
#define LMLOG_ERROR(msg) UE_LOG(LogLocalMulti, Error, TEXT(msg))
#define LMLOG_FATAL(msg) UE_LOG(LogLocalMulti, Fatal, TEXT(msg))

#define LMLOG_DISPLAY_ARGS(msg, ...) UE_LOG(LogLocalMulti, Display, TEXT(msg), __VA_ARGS__)
#define LMLOG_WARNING_ARGS(msg, ...) UE_LOG(LogLocalMulti, Warning, TEXT(msg), __VA_ARGS__)
#define LMLOG_ERROR_ARGS(msg, ...) UE_LOG(LogLocalMulti, Error, TEXT(msg), __VA_ARGS__)
#define LMLOG_FATAL_ARGS(msg, ...) UE_LOG(LogLocalMulti, Fatal, TEXT(msg), __VA_ARGS__)
