#include <jni.h>

// 중복 포함을 방지하는 헤더 가드를 정의합
#ifndef _Included_com_example_Main
#define _Included_com_example_Main

// C++ 컴파일러에서도  헤더 사용가능하게
#ifdef __cplusplus
extern "C" {
#endif

// 패키지명으로 만들어야 된다. 그리고 호출 클래스 이름도 적어줘야 한다..
JNIEXPORT jint JNICALL Java_org_wonjoo_ios_jpty_Main_createPty(JNIEnv *env, jclass clazz);

#ifdef __cplusplus
}
#endif
#endif
