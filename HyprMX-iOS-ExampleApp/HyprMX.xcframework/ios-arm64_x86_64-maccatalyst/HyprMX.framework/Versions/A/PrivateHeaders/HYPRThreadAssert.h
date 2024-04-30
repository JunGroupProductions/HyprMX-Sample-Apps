//
//  HYPRThreadAssert.h
//  HyprMX-Framework
//
//  Copyright (c) 2014 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#ifndef HyprMX_Framework_ThreadAssert_h
#define HyprMX_Framework_ThreadAssert_h
#include <assert.h>
#define HYPRAssert(condition, desc) HYPRAssertCustomAssertIsInDebugger(_cmd, __FILE__, __LINE__, condition, desc)

#define HYPRParameterAssert(condition) HYPRAssertCustomParameterAssertIsInDebugger(__FILE__, __LINE__, condition)

void HYPRAssertCustomParameterAssertIsInDebugger(const char *file, int line, id condition);
void HYPRAssertInDebugger(SEL selector, const char* file, int line, BOOL wontAssert, NSString *error);
void HYPRAssertCustomAssertIsInDebugger(SEL selector, const char *file, int line, BOOL condition, NSString *error);

#endif
