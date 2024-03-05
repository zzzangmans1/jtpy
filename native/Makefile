# 환경 변수 설정
CC = gcc
JDK_HOME = /Library/Java/JavaVirtualMachines/jdk-21.jdk/Contents/Home
# 컴파일 옵션
CFLAGS = -shared -o libpty.so -I $(JDK_HOME)/include -I $(JDK_HOME)/include/darwin -fPIC

# 빌드 대상 및 의존성
all: libpty.so

# 라이브러리 빌드 규칙
libpty.so: Main.c
	$(CC) $(CFLAGS) $^

# 정리 규칙
clean:
	rm -f libpty.so
