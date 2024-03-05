package org.wonjoo.ios.jpty;

import java.nio.file.FileSystems;

public class Main {
        // 라이브러리 등록하는 것
        static {
            String currentDirectory = FileSystems.getDefault().getPath("").toAbsolutePath().toString();
            String libraryPath = currentDirectory + "/native/libpty.so";
            System.out.println("Loading library from: " + libraryPath);
            try {
                System.load(libraryPath);
                System.out.println("Library loaded successfully.");
            } catch (UnsatisfiedLinkError e) {
                System.err.println("Failed to load library: " + e.getMessage());
                e.printStackTrace();
            }
        }
        // JNI를 사용하여 PTY Master 생성하는 네이티브 메서드
        public static native int createPty();
        public static void main(String[] args) {
            int masterFd = createPty();
            if (masterFd == -1) {
                System.err.println("Failed to create PTY master.");
            } else {
                System.out.println("PTY master created successfully. FD: " + masterFd);
            }

        }
}

