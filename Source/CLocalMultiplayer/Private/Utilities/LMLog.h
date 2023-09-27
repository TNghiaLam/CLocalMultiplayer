// Nghia Lam - MIT License

#pragma once

#include "Logging/LogMacros.h"

// Declare our game log categories
DECLARE_LOG_CATEGORY_EXTERN(LogLocalMulti, Log, All);

// Simplify logging for our games
// ---

#define LMLOG(type, msg, ...) UE_LOG(LogLocalMulti, type, TEXT(msg), ##__VA_ARGS__)

#define LMLOG_DISPLAY(msg, ...) UE_LOG(LogLocalMulti, Display, TEXT(msg), ##__VA_ARGS__)
#define LMLOG_WARNING(msg, ...) UE_LOG(LogLocalMulti, Warning, TEXT(msg), ##__VA_ARGS__)
#define LMLOG_ERROR(msg, ...) UE_LOG(LogLocalMulti, Error, TEXT(msg), ##__VA_ARGS__)
#define LMLOG_FATAL(msg, ...) UE_LOG(LogLocalMulti, Fatal, TEXT(msg), ##__VA_ARGS__)
